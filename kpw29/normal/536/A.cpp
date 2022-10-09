#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define milion 1000100
#define tysiac 1010
#define dwa_tysiace 2010
#define sto_tysiecy 100100
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;

ll a,b,zap, l, t, m;

ll element(ll i)
{
	return ((i-1) * b + a);
}

bool da_sie(ll k)
{
	//cout << k << endl;
	ll el = element(k);
	if (el > t) return false;
	ll el1 = element(l);
	//cout << el1 << ' ' << el << endl;
	ll suma = (el1 + el) * (k - l + 1) / 2;
	if (suma > t * m) return false;
	return true;
}
ll bin_search(ll x, ll y)
{
	while (x != y)
	{
		ll k = (x + y)/2 +1;
		if (da_sie(k) == false) y = k-1;
		else x = k;
	}
	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> a >> b >> zap;
	while (zap--)
	{
		cin >> l >> t >> m;
		ll wyn = bin_search(l-1, inf);
		if (wyn == l - 1) cout << "-1" << endl;
		else cout << wyn << endl;
	}
	
}