#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

struct node
{
	int pre , suf , ans , sz;
	node()
	{
		pre = suf = ans = sz = 0;
	}
};

node seg[maxn * 4] , void_node;

pair<int , int> a[maxn];

int n , l[maxn] , r[maxn] , w[maxn] , L[maxn] , R[maxn];

vector<int> q[maxn];

node merge(node a , node b)
{
	node c;
	c.sz = a.sz + b.sz;

	c.pre = a.pre + (a.pre == a.sz? b.pre : 0);
	c.suf = b.suf + (b.suf == b.sz? a.suf : 0);
	c.ans = max(a.ans , b.ans);
	c.ans = max(c.ans , max(c.pre , c.suf));
	c.ans = max(c.ans , a.suf + b.pre);

	return c;
}

void build(int s , int e , int v)
{
	seg[v].sz = e - s;
	seg[v].pre = seg[v].suf = seg[v].ans = 0;

	if(e - s < 2)
		return;
	int m = (s + e) / 2;

	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
}

void update(int p , int s , int e , int v)
{
	if(e - s < 2)
	{
		seg[v].pre = seg[v].suf = seg[v].ans = 1;
		return;
	}
	int m = (s + e) / 2;

	if(p < m)
		update(p , s , m , 2 * v);
	else
		update(p , m , e , 2 * v + 1);

	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

node get(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return seg[v];
	if(r <= s || e <= l)
		return void_node;

	int m = (s + e) / 2;

	return merge(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

void solve()
{
	build(0 , n , 1);

	for(int i = n - 1; i >= 0; i--)
	{
		int k = a[i].second;
		update(k , 0 , n , 1);
		
		for(auto tmp : q[i])
		{
			if(get(l[tmp] , r[tmp] , 0 , n , 1).ans >=w[tmp])
				L[tmp] = i;
			else
				R[tmp] = i;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i].first , a[i].second = i;
	sort(a , a + n);

	int Q;
	cin >> Q;

	for(int i = 0; i < Q; i++)
	{
		cin >> l[i] >> r[i] >> w[i];
		l[i]--;

		L[i] = 0 , R[i] = n;
	}

	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < maxn; j++)
			q[j].clear();
		for(int j = 0; j < Q; j++)
			q[(L[j] + R[j]) / 2].pb(j);

		solve();
	}

	for(int i = 0; i < Q; i++)
		cout << a[L[i]].first << endl;
	cout << endl;
}