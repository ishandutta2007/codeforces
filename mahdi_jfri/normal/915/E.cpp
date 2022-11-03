#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 6e5 + 20;

struct node
{
	int lazy , t , sz;
	node()
	{
		sz = 0;
		lazy = -1;
		t = 0;
	}
};

node seg[maxn * 4];

int l[maxn] , r[maxn] , k[maxn] , a[maxn];

vector<int> v1;

int f(int x)
{
	return lower_bound(v1.begin() , v1.end() , x) - v1.begin();
}

void ok(int v , int val)
{
	seg[v].lazy = val;
	seg[v].t = seg[v].sz * val;
}

void shift(int s , int e , int v)
{
	if(e - s >= 2 && seg[v].lazy != -1)
	{
		ok(2 * v , seg[v].lazy);
		ok(2 * v + 1 , seg[v].lazy);
	}
	seg[v].lazy = -1;
}

void update(int l , int r , int val , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		ok(v , val);
		return;
	}
	if(r <= s || e <= l)
		return;
	shift(s , e , v);
	int m = (s + e) / 2;

	update(l , r , val , s , m , 2 * v);
	update(l , r , val , m , e , 2 * v + 1);

	seg[v].t = seg[2 * v].t + seg[2 * v + 1].t;
}

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		seg[v].sz = a[s];
		return;
	}
	int m = (s + e) / 2;

	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);

	seg[v].sz = seg[2 * v].sz + seg[2 * v + 1].sz;
}

int main()
{
	int n , q;
	scanf("%d%d", &n, &q);

	v1.reserve(1 << 20);

	for(int i = 0; i < q; i++)
	{
		scanf("%d%d%d", &l[i], &r[i], &k[i]);
		k[i] %= 2;
		l[i]--;
		v1.pb(l[i]);
		v1.pb(r[i]);
	}
	sort(v1.begin() , v1.end());
	v1.resize(unique(v1.begin() , v1.end()) - v1.begin());

	for(int i = 0; i + 1 < (int)v1.size(); i++)
		a[i] = v1[i + 1] - v1[i];

	a[(int)v1.size() - 1] = n - v1.back();

	build(0 , v1.size() , 1);

	for(int i = 0; i < q; i++)
	{
		update(f(l[i]) , f(r[i]) , k[i] , 0 , v1.size() , 1);
		printf("%d\n", n - seg[1].t);
	}
}