#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lb(a) ((a)&(-a))
const int maxn = 1e6 + 20;

int a[maxn] , t[maxn] , fen[maxn];

map<int , int> mp;

void add(int pos , int val)
{
	for(; pos < maxn; pos += lb(pos))
		fen[pos] += val;
}

int get(int pos)
{
	int res = 0;
	for(; pos > 0; pos -= lb(pos))
		res += fen[pos];
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = n - 1; i >= 0; i--)
	{
		mp[a[i]]++;
		t[i] = mp[a[i]];
		add(t[i] , 1);
	}
	mp.clear();
	ll res = 0;
	for(int i = 0; i < n; i++)
	{
		mp[a[i]]++;
		add(t[i] , -1);
		res += get(mp[a[i]] - 1);
	}
	cout << res << endl;
}