#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9

using namespace std;
inline ll read()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
ll n, s;

bool check(ll x)
{
	ll res = x;
	while(x)
	{
		res -= x % 10;
		x /= 10;
	}
	return res < s;
}

int main()
{
	n = read();
	s = read();
	ll l = 0, r = n;
	ll ans = n + 1;
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		if(check(mid)) l = mid + 1;
		else ans = mid, r = mid - 1;
	}
	cout << n - ans + 1;
	return 0;
}