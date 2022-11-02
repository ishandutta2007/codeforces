#include <bits/stdc++.h>
using namespace std;

#define MAXK 250004

int yy[]={-1, 0, 1, 0}, xx[]={0, 1, 0, -1};
int N, K, S;
int A[502][502], B[502][502];
int par[MAXK], sz[MAXK], cnt[MAXK], made;

int cp(int n){ return par[n] == n ? n : (par[n] = cp(par[n])); }

void _union(int a, int b)
{
	a = cp(a), b = cp(b);
	if (a == b) return;
	par[b] = a; sz[a] += sz[b];
}

inline void add(int y, int x)
{
	if (y < 1 || y > N || x < 1 || x > N || !A[y][x]) return;
	int n = cp(A[y][x]);
	if (!cnt[n]++) made += sz[n];
}

inline void del(int y, int x)
{
	if (y < 1 || y > N || x < 1 || x > N || !A[y][x]) return;
	int n = cp(A[y][x]);
	if (!--cnt[n]) made -= sz[n];
}

int cnt_x(int y, int x)
{
	return B[y+S-1][x+S-1]-B[y-1][x+S-1]-B[y+S-1][x-1]+B[y-1][x-1];
}

int main()
{
	scanf("%d%d", &N, &S);
	for (int i=1;i<=N;i++){
		char buf[502]; scanf("%s", buf+1);
		for (int j=1;j<=N;j++) if (buf[j] == '.') A[i][j] = ++K;
	}
	for (int i=1;i<=K;i++) par[i] = i, sz[i] = 1;
	for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) if (A[i][j]){
		for (int d=0;d<4;d++){
			int y = i+yy[d], x = j+xx[d];
			if (y < 1 || y > N || x < 1 || x > N || !A[y][x]) continue;
			_union(A[i][j], A[y][x]);
		}
	}
	for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) B[i][j] = B[i-1][j]+B[i][j-1]-B[i-1][j-1]+(!A[i][j]);
	int ans = 0;
	for (int i=1;i<=K;i++) if (cp(i) == i) ans = max(ans, sz[i]);
	for (int i=1;i<=N-S+1;i++){
		for (int y=i-1;y<=i+S;y++)
			for (int x=1;x<=S;x++)
				add(y, x);
		for (int y=i;y<i+S;y++) add(y, S+1);
		ans = max(ans, made + cnt_x(i, 1));
		for (int j=2;j<=N-S+1;j++){
			for (int y=i;y<i+S;y++) del(y, j-2);
			del(i-1, j-1); del(i+S, j-1);
			for (int y=i;y<i+S;y++) add(y, j+S);
			add(i-1, j+S-1); add(i+S, j+S-1);
			ans = max(ans, made + cnt_x(i, j));
		}
		for (int y=i-1;y<=i+S;y++)
			for (int x=N;x>N-S;x--)
				del(y, x);
		for (int y=i;y<i+S;y++) del(y, N-S);
	}
	printf("%d\n", ans);
}