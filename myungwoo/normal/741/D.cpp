#include <bits/stdc++.h>
using namespace std;

#define MAXN 500005
#define MSK 1 << 22
#define pb push_back
#define sz(v) ((int)(v).size())

int N, K;
int parv[MAXN], D[MAXN];
int msk[MAXN], H[MAXN];
int arr[MAXN], num[MAXN], out[MAXN], sz[MAXN];
int V[MSK];
vector <int> con[MAXN];

void set_tree(int n)
{
	num[n] = ++K; arr[K] = n;
	sz[n] = 1;
	for (int t: con[n]){
		msk[t] = msk[n] ^ parv[t];
		H[t] = H[n]+1;
		set_tree(t);
		sz[n] += sz[t];
	}
	out[n] = K;
}

void dfs(int n, bool keep)
{
	int big_child = 0;
	for (int t: con[n])
		if (sz[big_child] < sz[t]) big_child = t;
	for (int t: con[n]) if (t != big_child)
		dfs(t, 0);
	if (big_child) dfs(big_child, 1);

	D[n] = 0;
	for (int t: con[n])
		D[n] = max(D[n], D[t]);
	for (int t: con[n]) if (t != big_child){
		for (int i=num[t];i<=out[t];i++){
			for (int v=1;v<MSK;v<<=1)
				D[n] = max(D[n], V[msk[arr[i]]^v] + H[arr[i]] - H[n]*2);
			D[n] = max(D[n], V[msk[arr[i]]] + H[arr[i]] - H[n]*2);
		}
		for (int i=num[t];i<=out[t];i++)
			V[msk[arr[i]]] = max(V[msk[arr[i]]], H[arr[i]]);
	}
	for (int v=1;v<MSK;v<<=1)
		D[n] = max(D[n], V[msk[n]^v] - H[n]);
	D[n] = max(D[n], V[msk[n]] - H[n]);
	V[msk[n]] = max(V[msk[n]], H[n]);
	if (!keep){
		for (int i=num[n];i<=out[n];i++)
			V[msk[arr[i]]] = -1e9;
	}
}

int main()
{
	scanf("%d", &N);
	for (int i=2;i<=N;i++){
		int p; char c; scanf("%d %c", &p, &c);
		con[p].pb(i); parv[i] = 1 << (c-'a');
	}
	set_tree(1);
	for (int i=0;i<MSK;i++)
		V[i] = -1e9;
	dfs(1, 0);
	for (int i=1;i<=N;i++)
		printf("%d ", D[i]);
	puts("");
}