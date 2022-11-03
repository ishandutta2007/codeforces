#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 3e5 + 20;
const int maxlog = 21;
const int maxN = maxn * maxlog;

int t[maxN] , c[maxN][2] , tah = 2 , a[maxn] , is[maxlog];

void add(ll val)
{
	int pos = 0;
	for(int i = maxlog - 1; i >= 0; i--)
	{
		t[pos]++;
		if(!c[pos][0])
			c[pos][0] = tah++ , c[pos][1] = tah++;
		pos = c[pos][bit(val , i)];
	}
	t[pos]++;
}

void update(ll val)
{
	for(int i = 0; i < maxlog; i++)
		if(bit(val , i))
			is[i] ^= 1;
}

ll mex()
{
	int pos = 0 , res = 0;
	for(int i = maxlog - 1; i>= 0; i--)
	{
		res *= 2;
		if(!c[pos][0])
			c[pos][0] = tah++ , c[pos][1] = tah++;
		if(t[c[pos][is[i]]] == (1LL << i))
			pos = c[pos][!is[i]] , res++;
		else
			pos = c[pos][is[i]];
	}
	return res;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n , q;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a , a + n);
	n = unique(a , a + n) - a;
	for(int i = 0; i < n; i++)
		add(a[i]);
	while(q--)
	{
		int x;
		cin >> x;
		update(x);
		cout << mex() << endl;
	}
}