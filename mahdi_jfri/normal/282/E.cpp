#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
const int maxn = 2e5 + 20;
const int maxb = 45;
const int maxN = maxn * maxb;

int t[maxN] , c[maxN][2] , tah = 1;

ll a[maxn] , px[maxn] , res;

void add(ll val , int k = 1)
{
	int pos = 0;
	for(int i = maxb - 1; i >= -1; i--)
	{
		t[pos] += k;
		if(i < 0)
			break;
		if(!c[pos][0])
			c[pos][0] = tah , c[pos][1] = tah + 1 , tah += 2;
		pos = c[pos][bit(val , i)];
	}
}

ll get(ll val)
{
	int pos = 0;
	ll res = 0;
	for(int i = maxb - 1; i >= 0; i--)
	{
		res *= 2;
		if(!c[pos][0])
			c[pos][0] = tah , c[pos][1] = tah + 1 , tah += 2;
		if(t[c[pos][!bit(val , i)]])
			pos = c[pos][!bit(val , i)] , res++;
		else
			pos = c[pos][bit(val , i)];
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] , px[i + 1] = px[i] ^ a[i];
	for(int i = 0; i < n; i++)
		add(px[n] ^ px[i]) , res = max(res , px[n] ^ px[i]);
	add(0);
	for(int i = 0; i < n; i++)
	{
		add(px[n] ^ px[i] , -1);
		res = max(res , get(px[i + 1]));
	}
	cout << res << endl;
}