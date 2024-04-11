#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 1e5 + 20;
const int maxb = 19;

struct node
{
	int prefix , suffix , size;
	ll sum;
	node()
	{
		prefix = suffix = size = sum = 0;
	}
};

node seg[maxn * 4][maxb];
int a[maxn];

node merge(node a , node b)
{
	node c;
	c.prefix = ((a.prefix == a.size)? a.size + b.prefix : a.prefix);
	c.suffix = ((b.suffix == b.size)? b.size + a.suffix : b.suffix);
	c.sum = a.sum + b.sum + (ll)a.suffix * b.prefix;
	c.size = a.size + b.size;
	return c;
}

void build(int s , int e , int v , int b)
{
	if(e - s < 2)
	{
		seg[v][b].size = 1;
		seg[v][b].prefix = seg[v][b].suffix = seg[v][b].sum = bit(a[s] , b);
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v , b);
	build(m , e , 2 * v + 1 , b);

	seg[v][b] = merge(seg[2 * v][b] , seg[2 * v + 1][b]);
}

void update(int p , int s , int e , int v , int b)
{
	if(e - s < 2)
	{
		seg[v][b].size = 1;
		seg[v][b].prefix = seg[v][b].suffix = seg[v][b].sum = bit(a[s] , b);
		return;
	}
	int m = (s + e) / 2;
	if(p < m)
		update(p , s , m , 2 * v , b);
	else
		update(p , m , e , 2 * v + 1 , b);

	seg[v][b] = merge(seg[2 * v][b] , seg[2 * v + 1][b]);
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
	for(int i = 0; i < maxb; i++)
		build(0 , n , 1 , i);

	while(q--)
	{
		int p;
		cin >> p;
		p--;
		cin >> a[p];
		for(int i = 0; i < maxb; i++)
			update(p , 0 , n , 1 , i);
		
		ll ans = 0;
		for(int i = 0; i < maxb; i++)
			ans += (1LL << i) * seg[1][i].sum;
		cout << ans << endl;
	}
}