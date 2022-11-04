#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
const LL mod = 1e9+7;

int n , k , ans , pp , si , lc;
int p[maxn] , d[maxn] , f[20][maxn] , tr[maxn*4] , pl[maxn*4] , pr[maxn*4];
vector<int> v[maxn];

int lca(int x , int y)
{
	if (d[x] < d[y]) swap(x,y);
	for (int j = 16 ; j >= 0 ; j--)
		if (d[f[j][x]] >= d[y]) x = f[j][x];
	for (int j = 16 ; j >= 0 ; j--)
	{
		if (f[j][x] != f[j][y])
		{
			x = f[j][x];
			y = f[j][y];
		}
	}
	if (x != y)
	{
		x = f[0][x];
		y = f[0][y];
	}
	return x;
}

void dfs(int x , int y)
{
	p[x] = ++pp;
	d[x] = d[y]+1;
	f[0][x] = y;
	for (int j = 1 ; j <= 16 ; j++)
		f[j][x] = f[j-1][f[j-1][x]];
	for (auto to: v[x])
		if (to != y) dfs(to,x);
}

void build(int num , int l , int r)
{
	if (l == r)
	{
		tr[num] = l;
		return;
	}
	int mid = ((l+r)>>1);
	build(num*2,l,mid);
	build(num*2+1,mid+1,r);
	tr[num] = lca(tr[num*2],tr[num*2+1]);
}

int getout(int num , int l , int r , int x , int y)
{
	if (x <= l && r <= y) return tr[num];
	int mid = ((l+r)>>1);
	if (y <= mid) return getout(num*2,l,mid,x,y);
	else if (x >= mid+1) return getout(num*2+1,mid+1,r,x,y);
	else return lca(getout(num*2,l,mid,x,y),getout(num*2+1,mid+1,r,x,y));
}

void putin(int num , int l , int r , int x , int y)
{
	if (l == r)
	{
		pl[num] = pr[num] = y;
		return;
	}
	int mid = ((l+r)>>1);
	if (x <= mid) putin(num*2,l,mid,x,y);
	else putin(num*2+1,mid+1,r,x,y);
	if (pl[num*2]) pl[num] = pl[num*2];
	else pl[num] = pl[num*2+1];
	if (pr[num*2+1]) pr[num] = pr[num*2+1];
	else pr[num] = pr[num*2];
}

int getl(int num , int l , int r , int x)
{
	if (x >= r) return pr[num];
	if (l == r) return 0;
	int mid = ((l+r)>>1);
	if (x <= mid) return getl(num*2,l,mid,x);
	else 
	{
		int ret = getl(num*2+1,mid+1,r,x);
		if (ret) return ret;
		else return pr[num*2];
	}
}

int getr(int num , int l , int r , int x)
{
	if (x <= l) return pl[num];
	if (l == r) return 0;
	int mid = ((l+r)>>1);
	if (x >= mid+1) return getr(num*2+1,mid+1,r,x);
	else 
	{
		int ret = getr(num*2,l,mid,x);
		if (ret) return ret;
		else return pl[num*2+1];
	}
}

void ins(int y , int x)
{
	if (!lc)
	{
		lc = x;
		si = 1;
		putin(1,1,n,p[x],x);
		return;
	}
	int ff = getout(1,1,n,y,x);
	if (ff != lc)
	{
		si += d[lc]-d[ff]+d[x]-d[ff];
		lc = ff;
	}
	else 
	{
		int ll = getl(1,1,n,p[x]-1);
		int rr = getr(1,1,n,p[x]+1);
		int fl , fr , ff = 0;
		if (ll) 
		{
			fl = lca(ll,x);
			if (!ff || d[fl] > d[ff]) ff = fl;
		}
		if (rr) 
		{
			fr = lca(rr,x);
			if (!ff || d[fr] > d[ff]) ff = fr;
		}
		si += d[x]-d[ff];
	}
	putin(1,1,n,p[x],x);
}

void ers(int x , int y)
{
	int ff = getout(1,1,n,x+1,y);
	if (ff != lc)
	{
		si -= d[ff]-d[lc]+d[x]-d[lc];
		lc = ff;
	}
	else
	{
		int ll = getl(1,1,n,p[x]-1);
		int rr = getr(1,1,n,p[x]+1);
		int fl , fr , ff = 0;
		if (ll) 
		{
			fl = lca(ll,x);
			if (!ff || d[fl] > d[ff]) ff = fl;
		}
		if (rr) 
		{
			fr = lca(rr,x);
			if (!ff || d[fr] > d[ff]) ff = fr;
		}
		si -= d[x]-d[ff];
	}
	putin(1,1,n,p[x],0);
}

int main()
{
	int i , j , x , y;
	cin >> n >> k;
	for (i = 1 ; i < n ; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	build(1,1,n);
	i = 1;
	for (j = 1 ; j <= n ; j++)
	{
		ins(i,j);
		while (si > k)
		{ 
			ers(i,j);
			i++;
		}
		ans = max(ans,j-i+1);
	}
	cout << ans << "\n";
	return 0;
}