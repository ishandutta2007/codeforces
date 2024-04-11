#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 201
#define MAXN (N + N + 23)
#define INF 0x7f7f7f7f

struct edge {
	int next,to,flow;
}e[MAXN * MAXN * 17];

int head[MAXN],cur[MAXN],tag[MAXN],ecnt = 1;

void add(int u,int v, int f) {
	e[++ecnt].to=v;
	e[ecnt].next=head[u];
	e[ecnt].flow=f;
	head[u]=ecnt;
	e[++ecnt].to=u;
	e[ecnt].next=head[v];
	e[ecnt].flow=0;
	head[v]=ecnt;
}
queue <int> q;
bool bfs() {
	memset(tag,0,sizeof(tag));
	tag[0]=1;
	q.push(0);
	while (!q.empty()) {
		int x=q.front();q.pop();
		for (int now=head[x];now;now=e[now].next) {
			if (e[now].flow && !tag[e[now].to]) {
				tag[e[now].to]=tag[x]+1;
				q.push(e[now].to);
			}
		}
	}
	return tag[1]!=0;
}

int dfs(int x,int flow) {
	if (x==1) return flow;
	int used=0;
	for (int &now=cur[x];now;now=e[now].next) {
		if (e[now].flow && tag[x]<tag[e[now].to]) {
			int ret=dfs(e[now].to,min(flow-used,e[now].flow));
			if (ret) {
				used+=ret;
				e[now].flow-=ret;
				e[now^1].flow+=ret;
				if (used==flow) return flow;
			}
		}
	}
	return used;
}

int n, T, A, B;

int dinic() {
	int ans=0;
	while (bfs()) {
		for (int i=0;i<=2 + A + B;i++) cur[i]=head[i];
		ans+=dfs(0,INF);
	}
	return ans;
}

int b[N][N];
int rx[N], ry[N];
map <int, int> X, Y;

struct Node {
	int x1, y1, x2, y2;
} a[N];

int main() {
	read(n); read(T);
	for (int i = 1; i <= T; i++) {
		int x1, y1, x2, y2;
		read(x1); read(y1); read(x2); read(y2);
		a[i] = {x1, y1, x2, y2};
		X[x1] = 0;
		X[x2 + 1] = 0;
		Y[y1] = 0;
		Y[y2 + 1] = 0;
	}
	for (auto &v : X) {
		v.second = ++A;
		rx[A] = v.first;
	}
	for (auto &v : Y) {
		v.second = ++B;
		ry[B] = v.first;
	}
	for (int i = 1; i <= T; i++) {
		int x1, y1, x2, y2;
		x1 = X[a[i].x1];
		x2 = X[a[i].x2 + 1];
		y1 = Y[a[i].y1];
		y2 = Y[a[i].y2 + 1];
		for (int x = x1; x < x2; x++)
			for (int y = y1; y < y2; y++) {
				b[x][y] = 1;
			}
	}
	for (int i = 1; i < A; i++) {
		add(0, 1 + i, rx[i + 1] - rx[i]);
	}
	for (int i = 1; i < B; i++) {
		add(1 + A + i, 1, ry[i + 1] - ry[i]);
	}
	for (int i = 1; i < A; i++)
		for (int j = 1; j < B; j++) {
			if (b[i][j]) {
				add(1 + i, 1 + A + j, INF);
			}
		}
	printf("%d\n", dinic());
}