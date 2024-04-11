#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lb(a) ((a)&(-a))
const int maxn = 2e5 + 20;

int a[maxn] , b[maxn] , mp[maxn] , fen[maxn] , c[maxn];

void add(int pos , int val)
{
	for(pos++; pos < maxn; pos += lb(pos))
		fen[pos] += val;
}

int get(int pos)
{
	int res = 0;
	for(pos++; pos > 0; pos -= lb(pos))
		res += fen[pos];
	return res;
}

int main()
{
	int n;
	cin >> n;
	int m = 2 * n;
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i] , mp[2 * i] = a[i] , mp[2 * i + 1] = b[i];
	sort(mp , mp + m);
	m = unique(mp , mp + m) - mp;
	for(int i = 0; i < n; i++)
	{
		a[i] = lower_bound(mp , mp + m , a[i]) - mp;
		b[i] = lower_bound(mp , mp + m , b[i]) - mp;
	}
	for(int i = 0; i < m; i++)
		c[i] = i;
	for(int i = 0; i < n; i++)
		swap(c[a[i]] , c[b[i]]);
	ll res = 0;
	for(int i = m - 1; i >= 0; i--)
	{
		res += get(c[i] - 1);
		add(c[i] , 1);
		if(c[i] > i)
		{
			res += mp[c[i]] - mp[i] - (c[i] - i);
		}
		else
		{
			res += mp[i] - mp[c[i]] - (i - c[i]);
		}
	}
	cout << res << endl;
}