#include<bits/stdc++.h>
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define x(v) (v).first
#define y(v) (v).second
#define siz(v) (int)(v).size()
#define pb push_back
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 1e5 + 10;
const int Log = 20;
int n;
int a[N], pos[N], pre[N];
int lo[N * Log], ro[N * Log], mn[N * Log], tot = 0, rt[N];
int vis[N];
void inse(int &p, int q, int l, int r, int x, int v)
{
	p = ++tot;
	lo[p] = lo[q], ro[p] = ro[q];
	if(l == r) return mn[p] = v, void();
	int mid = (l + r) / 2;
	if(x <= mid) inse(lo[p], lo[q], l, mid, x, v);
	else inse(ro[p], ro[q], mid + 1, r, x, v);
	mn[p] = min(mn[lo[p]], mn[ro[p]]);
	return;
}
int quer1(int p, int l, int r, int L, int R)
{
	if(!p) return -1;
	if(L <= l && r <= R) return mn[p];
	int mid = (l + r) / 2;
	int res = n + 1;
	if(L <= mid) res = min(res, quer1(lo[p], l, mid, L, R));
	if(R > mid) res = min(res, quer1(ro[p], mid + 1, r, L, R));
	return res;
}

int main()
{
	scanf("%d", &n);
	mn[0] = -1;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) inse(rt[i], rt[i - 1], 1, n, a[i], i);
	for(int i = 1; i <= n; i++) pos[i] = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == 1) continue;
		int mn = quer1(rt[i], 1, n, 1, a[i] - 1);
		if(mn > pos[a[i]]) vis[a[i]] = 1;
		pos[a[i]] = i;
	}
	for(int i = 2; i <= n + 1; i++)
	{
		int mn = quer1(rt[n], 1, n, 1, i - 1);
		if(mn > pos[i]) vis[i] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == 1) 
		{
			if(pos[1] < i - 1) vis[1] = 1;
			pos[1] = i;
		}
	}
	if(pos[1] < n - 1) vis[1] = 1;
	for(int i = 1; i <= n + 2; i++) if(!vis[i]) return printf("%d\n", i), 0;
	return 0;
}