#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;

struct node
{
	int lazy , nd , ni , one , zero;
	node()
	{
		lazy = nd = ni = one = zero = 0;
	}
};

node seg[maxn * 4];

string x;

node merge(node a , node b)
{
	node c;
	c.nd = max(a.zero + b.nd , a.nd + b.one);
	c.ni = max(a.one + b.ni , a.ni + b.zero);
	c.one = a.one + b.one;
	c.zero = a.zero + b.zero;
	return c;
}

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		seg[v].nd = seg[v].ni = 1;
		seg[v].zero = (x[s] == '4');
		seg[v].one = 1 - seg[v].zero;
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);

	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

void ok(int v)
{
	swap(seg[v].ni , seg[v].nd);
	swap(seg[v].one , seg[v].zero);
	seg[v].lazy ^= 1;
}

void shift(int s , int e , int v)
{
	if(e - s >= 2 && seg[v].lazy)
	{
		ok(2 * v);
		ok(2 * v + 1);
	}
	seg[v].lazy = 0;
}

// flip ?

void flip(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		ok(v);
		return;
	}
	if(r <= s || e <= l)
		return;
	shift(s , e , v);
	int m = (s + e) / 2;
	flip(l , r , s , m , 2 * v); 
	// :|||||||||||||||||||||||||||||||||||||||||||||||||||
	flip(l , r , m , e , 2 * v + 1);
	
	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , q;
	cin >> n >> q >> x;
	build(0 , n , 1);

	while(q--)
	{
		string type;
		cin >> type;
		if(type == "switch")
		{
			int l , r;
			cin >> l >> r;
			l--;
			flip(l , r , 0 , n , 1);
		}
		else
			cout << seg[1].nd << endl;
	}
}