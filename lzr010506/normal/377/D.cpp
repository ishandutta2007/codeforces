#include <bits/stdc++.h>
#define mp make_pair
#define nd second
#define st first
#define pb push_back
#define N 300010
using namespace std;
int L[N],R[N],U[N];
vector< pair <int,int> > a[N] , b[N];
int ak[8 * N],it[8 * N], ah[8 * N], ans = 0x7f7f7f7f;
void update(int x, int l, int r, int u, int v, int k)
{
	if(x == 0) return;
	if(l > v || r < u) return;
	if(u <= l && r <= v)
	{
		it[x] += k;
		ak[x] += k;
		if(!ah[x]) ah[x] = l;
		return;
	}
	int mid = (l + r) >> 1;
	update(x << 1, l, mid, u, v, k);
	update(x << 1 | 1, mid + 1, r, u, v, k);
	if(it[x << 1] > it[x << 1 | 1])
	{
		it[x] = it[x << 1];
		ah[x] = ah[x << 1];
	}
	else
	{
		it[x] = it[x << 1 | 1];
		ah[x] = ah[x << 1 | 1];
	}
	it[x] += ak[x];
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
	{
		scanf("%d %d %d", &L[i], &U[i], &R[i]);
		a[U[i]].pb(mp(L[i], U[i]));
		b[R[i]].pb(mp(L[i], U[i]));
	}
	int res = 0;
	int ll = -1, rr = -1;
	for(int i = 1; i < N; i ++)
	{
		int u = a[i].size();
		for(int j = 0; j < u; j ++)
		{
			pair<int, int> v = a[i][j];
			update(1, 1, N - 10, v.st, v.nd, 1);
		}
		if(it[1] > res)
		{
			res = it[1];
			rr = i;
			ll = ah[1];
		}
		u = b[i].size();
		for(int j = 0; j < u; j ++)
		{
			pair<int, int> v = b[i][j];
			update(1, 1, N - 10, v.st, v.nd, -1);
		}
	}
	printf("%d\n",res);
	for(int i = 0; i < n; i ++)
		if(ll >= L[i] && ll <= U[i] && rr >= U[i] && rr <= R[i]) 
			printf("%d ",i + 1);
	return 0;
}