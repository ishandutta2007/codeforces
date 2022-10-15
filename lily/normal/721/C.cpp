#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
#define MAXN 5005
#define MAXM 5005

struct edge {
	int next,to,w;
}e[MAXM];


int dis[MAXN][MAXN],pre[MAXN][MAXN];

int n,m,T,ecnt=0;
int head[MAXN];

inline void add(int u,int v,int w) {
	e[++ecnt].to=v;
	e[ecnt].next=head[u];
	e[ecnt].w=w;
	head[u]=ecnt;
}
// ya 16384
queue<int> q;
inline void work() {
	dis[1][1]=1;
	q.push((1<<14) + 1);
	while (!q.empty()) {
		int x=q.front()>>14,y=q.front()&16383,st=(x<<14)+y,dd=dis[x][y];q.pop();
		if (dd>=T) continue;
		for (int now=head[x];now;now=e[now].next) {
			int d=dis[e[now].to][y+1];
			if ((!d || d>dd+e[now].w)) {
				dis[e[now].to][y+1]=dd+e[now].w;
				pre[e[now].to][y+1]=st;
				q.push((e[now].to<<14)+y+1);
			}
		}
	}
}

int sta[MAXN],top=0;

int main() {
	scanf("%d%d%d",&n,&m,&T);
	for (int i=1,u,v,w;i<=m;i++) {
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	T++;
	work();
	int ans=0;
	for (int i=1;i<=n;i++) {
		if (dis[n][i] && dis[n][i]<=T) ans=i;
	}
	int x=n,y=ans;
	while (x!=1) {
		sta[++top]=x;
		int to=pre[x][y];
		x=to>>14,y=to&16383;
	}
	printf("%d\n1",ans);
	while (top) {
		printf(" %d",sta[top--]);
	}
	return 0;
}