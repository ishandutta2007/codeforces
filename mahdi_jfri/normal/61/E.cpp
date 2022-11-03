#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lb(a) ((a)&(-a))
const int maxn = 1e6 + 20;

int a[maxn] , b[maxn] , n;

ll fen_t[maxn] , fen[maxn] , ans;

ll lower(ll x)
{
	return lower_bound(b , b + n , x) - b;
}

void add(int pos , int val)
{
	for(pos++; pos < maxn; pos += lb(pos))
		fen[pos] += val;
}

ll get(int pos)
{
	ll res = 0;
	for(pos++; pos > 0; pos -= lb(pos))
		res += fen[pos];
	return res;
}

void add_t(int pos , int val)
{
	for(pos++; pos < maxn; pos += lb(pos))
		fen_t[pos] += val;
}
ll get_t(int pos)
{
	ll res = 0;
	for(pos++; pos > 0; pos -= lb(pos))
		res += fen_t[pos];
	return res;
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] , b[i] = a[i];
	sort(b , b + n);
	ll ans = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		ll pos = lower(a[i]);
		ans += get(pos - 1);
		ll x = get_t(pos - 1);
		add(pos , x);
		add_t(pos , 1);
	}
	cout << ans << endl;
}