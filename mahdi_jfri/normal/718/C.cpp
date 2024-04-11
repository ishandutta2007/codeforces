#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const ll mod = 1e9 + 7;

struct matrix
{
	int val[2][2];
	int n;
	matrix(int nn, int x = 0)
	{
		n = nn;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (i != j)
					val[i][j] = 0;
				else
					val[i][j] = x;
	}
	matrix()
	{
		n = 2;
	}
	int* operator[] (int x)
	{
		return val[x];
	}
	matrix operator * (matrix b)
	{
		matrix ans(n, 0);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				for(int k=0; k<n; k++)
					ans[i][k] += 1LL * val[i][j] * b[j][k] % mod, ans[i][k] %= mod;
		return ans;
	}
	matrix operator + (matrix b)
	{
		matrix ans(n , 0);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				ans[i][j] = (val[i][j] + b[i][j]) % mod;
		return ans;
	}
};

matrix operator ^ (matrix a, ll b)
{
	matrix ans(a.n, 1);
	while(b)
	{
		if (b & 1)
			ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

struct node
{
	matrix lazy;
	matrix sum;
	node()
	{
		lazy[0][0] = lazy[1][1] = 1;
		lazy[0][1] = lazy[1][0] = 0;
		sum[0][0] = sum[0][1] = sum[1][0] = sum[1][1] = 0;
	}
};

node seg[maxn * 4] , void_node;

matrix shit(2 , 1);

int a[maxn];

node merge(node a , node b)
{
	node c;
	c.sum = a.sum + b.sum;
	return c;
}

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		seg[v].sum[0][0] = seg[v].sum[0][1] = seg[v].sum[1][0] = 1;
		seg[v].sum = seg[v].sum ^ (a[s] - 1);
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);

	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

void ok(int v , matrix &tmp)
{
	seg[v].sum = seg[v].sum * tmp;
	seg[v].lazy = seg[v].lazy * tmp;
}

void shift(int s , int e , int v)
{
	if(e - s >= 2)
	{
		ok(2 * v , seg[v].lazy);
		ok(2 * v + 1 , seg[v].lazy);
	}
	seg[v].lazy = shit;
}

void update(int l , int r , matrix &tmp , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		ok(v , tmp);
		return;
	}
	if(r <= s || e <= l)
		return;
	shift(s , e , v);
	int m = (s + e) / 2;
	update(l , r , tmp , s , m , 2 * v);
	update(l , r, tmp , m , e , 2 * v + 1);

	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

node get(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return seg[v];
	if(r <= s || e <= l)
		return void_node;
	shift(s , e , v);
	int m = (s + e) / 2;
	return merge(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

ll kir(ll x)
{
	matrix tmp(2 , 0);
	tmp[0][0] = tmp[0][1] = tmp[1][0] = 1;
	tmp = tmp ^ (x - 1);
	return tmp[0][0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , q;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	build(0 , n , 1);
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int l , r , x;
			cin >> l >> r >> x;
			l--;
			matrix tmp(2 , 0);
			tmp[0][0] = tmp[0][1] = tmp[1][0] = 1;
			tmp = tmp ^ x;
			update(l , r , tmp , 0 , n , 1);
		}
		else
		{
			int l , r;
			cin >> l >> r;
			l--;
			cout << get(l , r , 0 , n , 1).sum[0][0] << endl;
		}
	}
}