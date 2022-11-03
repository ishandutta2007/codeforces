#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int maxb = 21;

int x;

struct node
{
	int Or , prefix[maxb] , suffix[maxb] , PrefixSize , SuffixSize , szp[maxb] , szs[maxb];
	ll ans;

	node()
	{
		Or = 0;
		memset(prefix , 0 , sizeof prefix);
		memset(suffix , 0 , sizeof suffix);
		memset(szp , 0 , sizeof szp);
		memset(szs , 0 , sizeof szs);
		PrefixSize = SuffixSize = ans = 0;
	}
};

node seg[maxn * 4] , void_node;

node merge(node a , node b)
{
	node c;
	c.ans = a.ans + b.ans;
	c.Or = a.Or | b.Or;

	int pt = a.SuffixSize - 1 , sum = 0;

	for(int i = 0; i < b.PrefixSize; i++)
	{
		while(pt >= 0 && (b.prefix[i] | a.suffix[pt]) >= x)
		{
			sum += a.szs[pt];
			pt--;
		}

		c.ans += 1LL * sum * b.szp[i];
	}

	for(int i = 0; i < a.PrefixSize; i++)
	{
		c.prefix[i] = a.prefix[i];
		c.szp[i] = a.szp[i];
	}
	c.PrefixSize = a.PrefixSize;

	for(int i = 0; i < b.PrefixSize; i++)
	{
		int id = c.PrefixSize;
		b.prefix[i] |= a.Or;

		if(id && c.prefix[id - 1] == b.prefix[i])
			c.szp[id - 1] += b.szp[i];
		else
		{
			c.prefix[id] = b.prefix[i];
			c.szp[id] = b.szp[i];
			c.PrefixSize++;
		}
	}
	
	for(int i = 0; i < b.SuffixSize; i++)
	{
		c.suffix[i] = b.suffix[i];
		c.szs[i] = b.szs[i];
	}
	c.SuffixSize = b.SuffixSize;

	for(int i = 0; i < a.SuffixSize; i++)
	{
		int id = c.SuffixSize;
		a.suffix[i] |= b.Or;

		if(id && c.suffix[id - 1] == a.suffix[i])
			c.szs[id - 1] += a.szs[i];
		else
		{
			c.suffix[id] = a.suffix[i];
			c.szs[id] = a.szs[i];
			c.SuffixSize++;
		}
	}

	return c;
}

void update(int p , int val , int s , int e , int v)
{
	if(e - s < 2)
	{
		seg[v].prefix[0] = val;
		seg[v].suffix[0] = val;
		seg[v].Or = val;
		seg[v].ans = (val >= x);
		seg[v].szp[0] = seg[v].szs[0] = 1;
		seg[v].PrefixSize = seg[v].SuffixSize = 1;

		return;
	}

	int m = (s + e) / 2;

	if(p < m)
		update(p , val , s , m , 2 * v);
	else
		update(p , val , m , e , 2 * v + 1);

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

	int n , q;
	cin >> n >> q >> x;

	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		update(i , x , 0 , n , 1);
	}

	while(q--)
	{
		int type;
		cin >> type;

		if(type == 1)
		{
			int pos , val;
			cin >> pos >> val;
			pos--;

			update(pos , val , 0 , n , 1);
		}
		else
		{
			int l , r;
			cin >> l >> r;
			l--;

			cout << get(l , r , 0 , n , 1).ans << endl;
		}
	}
}