#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int ll
const int maxn = 1e5 + 20;
const ll mod[2] = {1000 * 1000 * 1000 + 7 , 1000 * 1000 * 1000 + 9};
const ll base[2] = {3079 , 737};

struct node
{
	ll lazy , hash[2] , sz;

	node()
	{
		lazy = -1;
		hash[0] = hash[1] = sz = 0;
	}
};

ll pw[maxn][2] , one[maxn][2];

node seg[maxn * 4] , void_node;

string a;

void prepare()
{
	pw[0][0] = pw[0][1] = 1;
	for(int i = 1; i < maxn; i++)
		for(int j = 0; j < 2; j++)
		{
			pw[i][j] = (pw[i - 1][j] * base[j]) % mod[j];
			one[i][j] = (one[i - 1][j] + pw[i - 1][j]) % mod[j];
		}
}

node merge(node a , node b)
{
	node c;
	for(int i = 0; i < 2; i++)
		c.hash[i] = (((a.hash[i] * pw[b.sz][i]) % mod[i]) + b.hash[i]) % mod[i];
	c.sz = a.sz + b.sz;
	return c;
}

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		for(int i = 0; i < 2; i++)
			seg[v].hash[i] = a[s];
		seg[v].sz = 1;
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

void ok(int s , int e , int v , int k)
{
	seg[v].lazy = k;
	for(int i = 0; i < 2; i++)
		seg[v].hash[i] = (one[e - s][i] * k) % mod[i];
}

void shift(int s , int e , int v)
{
	if(e - s >= 2 && seg[v].lazy != -1)
	{
		int m = (s + e) / 2;
		ok(s , m , 2 * v , seg[v].lazy);
		ok(m , e , 2 * v + 1 , seg[v].lazy);
	}
	seg[v].lazy = -1;
}

void update(int l , int r , int val , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		ok(s , e , v , val);
		return;
	}
	if(r <= s || e <= l)
		return;
	shift(s , e , v);
	int m = (s + e) / 2;
	update(l , r , val , s , m , 2 * v);
	update(l , r , val , m , e , 2 * v + 1);

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

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	prepare();
	int n , m , k , q;
	cin >> n >> m >> k >> a;
	q = m + k;
	build(0 , n , 1);

	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int l , r , c;
			cin >> l >> r >> c;
			l--;
			c += '0';
			update(l , r , c , 0 , n , 1);
		}
		else
		{
			int l , r , d;
			cin >> l >> r >> d;
			l--;
			node a = get(l , r - d , 0 , n , 1);
			node b = get(l + d , r , 0 , n , 1);
			bool f = 1;
			for(int i = 0; i < 2; i++)
				if(a.hash[i] != b.hash[i])
					f = 0;
			cout << (f? "YES" : "NO") << endl;
		}
	}
}