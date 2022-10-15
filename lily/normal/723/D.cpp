#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAXN 55

struct lake {
	int x,y,size;
	lake(){}
	lake(int a,int b,int c):x(a),y(b),size(c){}
	bool operator < (lake a) const {
		return size<a.size;
	}
}a[MAXN*MAXN];

int n,m,k,cnt=0;
int G[MAXN][MAXN],visit[MAXN][MAXN];
char temp[MAXN];

struct statu {
	int x,y;
	statu(){}
	statu(int q,int w):x(q),y(w){}
};

int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};


inline bool inrange(int x,int y) {
	return x>0 && x<=n && y>0 && y<=m;
}

queue <statu> q;

inline int bfs(int sx,int sy) {
	int ans=0;
	q.push(statu(sx,sy));
	visit[sx][sy]=1;
	while (!q.empty()) {
		int x=q.front().x,y=q.front().y;q.pop();
		ans++;
		for (int d=0;d<4;d++) {
			int tox=x+dx[d],toy=y+dy[d];
			if (inrange(tox,toy) && !G[tox][toy] && !visit[tox][toy]) {
				visit[tox][toy]=1;
				q.push(statu(tox,toy));
			}
		}
	}
	return ans;
}

inline void fillG(lake L) {
	q.push(statu(L.x,L.y));
	G[L.x][L.y]=1;
	while (!q.empty()) {
		int x=q.front().x,y=q.front().y;q.pop();
		for (int d=0;d<4;d++) {
			int tox=x+dx[d],toy=y+dy[d];
			if (inrange(tox,toy) && !G[tox][toy]) {
				G[tox][toy]=1;
				q.push(statu(tox,toy));
			}
		}
	}

}

inline void fuckEdge() {
	for (int i=1;i<=n;i++) {
		if (!G[i][1] && !visit[i][1]) {
			bfs(i,1);
		}
		if (!G[i][m] && !visit[i][m]) {
			bfs(i,m);
		}
	}
	for (int i=2;i<m;i++) {
		if (!G[1][i] && !visit[1][i]) {
			bfs(1,i);
		}
		if (!G[n][i] && !visit[n][i]) {
			bfs(n,i);
		}
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) {
		scanf("%s",temp+1);
		for (int j=1;j<=m;j++) {
			if (temp[j]=='*')
				G[i][j]=1;
			else 
				G[i][j]=0;
		}
	}
	fuckEdge();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) {
			if (!G[i][j] && !visit[i][j]) {
				a[++cnt]=lake(i,j,bfs(i,j));
			}
		}
	sort(a+1,a+cnt+1);
	int tot=0;
	for (int i=1,ta=cnt-k;i<=ta;i++) {
		fillG(a[i]);
		tot+=a[i].size;
	}
	printf("%d\n",tot);
	for (int i=1;i<=n;i++,putchar('\n'))
		for (int j=1;j<=m;j++) {
			if (G[i][j]) {
				putchar('*');
			}
			else {
				putchar('.');
			}
		}
	return 0;
}