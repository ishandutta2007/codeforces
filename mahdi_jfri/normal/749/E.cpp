#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ld long double
#define lb(a) ((a)&(-a))
const int maxn = 1e5 + 20;

int a[maxn];

ll fen[maxn];

void add(int pos , ll val)
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

int main()
{
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	ll inv = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		inv += get(a[i] - 1);
		add(a[i] , 1);
	}
	fill(fen , fen + maxn , 0);
	ll inve = 0;
	for(ll i = n - 1; i >= 0; i--)
	{
		inve += (i + 1) * get(a[i] - 1);
		add(a[i] , n - i);
	}
	ld sum = 0;
	for(ll i = 1; i <= n; i++)
		sum += (ll) i * (i - 1) / 4.0 * (n - i + 1);
	cout << setprecision(30) << fixed;
	cout << (sum - inve) / (n * (n + 1) / 2) + inv << endl;
}