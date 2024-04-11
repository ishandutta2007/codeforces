#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	node *next;
	int where;
} *first[100001], a[200001];

int n, m, dist[100001], c[100001], l, cnt, v[100001], w[100001], f[100001], ans, A[400001], len, root;
bool b[100001], OK;

inline void makelist(int x, int y){
	a[++l].where = y;
	a[l].next = first[x];
	first[x] = &a[l];
}

inline void soso(int now){
	if (v[now]) ++cnt, w[++len] = now;
	for (node *x = first[now]; x; x = x->next)
		if (!dist[x->where]) dist[x->where] = dist[now] + 1, f[x->where] = now, soso(x->where);
}

inline void work(int now){
	v[now] ^= 1; A[++ans] = now;
	for (node *x = first[now]; x; x = x->next)
		if (f[x->where] == now)
		{
			work(x->where);
			v[now] ^= 1;
			A[++ans] = now;
		}
	if (v[now])
		if (now != root) A[++ans] = f[now], A[++ans] = now, v[f[now]] ^= 1;
		else --ans;
}
		
int main(){
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	memset(first, 0, sizeof(first)); l = 0;
	memset(dist, 0, sizeof(dist));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		makelist(x, y);
		makelist(y, x);
	}
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	root = 0; len = 0;
	bool ok = true;
	for (int i = 1; i <= n; i++)
		if (!dist[i] && v[i])
		{
			dist[i] = 1; 
			cnt = 0;
			soso(i);
			if (cnt) 
				if (!root) root = i;
				else
				{
					ok = false;
					break;
				}
		}
	if (!ok) 
	{
		printf("-1\n");
		return 0;
	}
	ans = 0;
	OK = true;
	work(root);
	if (!OK) 
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++)
	{
		if (i != 1) printf(" ");
		printf("%d", A[i]);
	}
	printf("\n");
}