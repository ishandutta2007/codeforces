#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

struct node
{
	int gcd , t , mn;
	node()
	{
		t = 0;
		mn = 1e9;
		gcd = 0;
	}
};

node seg[maxn * 4] , void_node;

int a[maxn];

node merge(node a , node b)
{
	node c;

	c.gcd = __gcd(a.gcd , b.gcd);

	c.mn = min(a.mn , b.mn);
	c.t = (a.mn == c.mn? a.t : 0) + (b.mn == c.mn? b.t : 0);
	return c;
}

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		seg[v].gcd = a[s];
		seg[v].mn = a[s];
		seg[v].t = 1;
		return;
	}

	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	build(0 , n , 1);

	int q;
	cin >> q;

	while(q--)
	{
		int l , r;
		cin >> l >> r;
		l--;
		
		node tmp = get(l , r , 0 , n , 1);
		if(tmp.gcd == tmp.mn)
			cout << r - l - tmp.t << endl;
		else
			cout << r - l << endl;
	}
}