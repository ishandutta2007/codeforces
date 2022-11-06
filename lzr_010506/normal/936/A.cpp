#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
#define db double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
ll k, d, t;
ll gcd(ll a, ll b)
{
	while(a)
	{
		ll c = a;
		a = b % a;
		b = c;
	}
	return b;
}

int main()
{
	cin >> k >> d >> t;
	ll size = ((k - 1) / d + 1) * d;
	ll tim = ((k - 1) / d + 1) * d + k;
	t = t * 2;
	ll tp = t / tim;
	ll last = t - tp * tim;
	bool flag = 0;
	ll ans = 0;
	if(last <= k * 2)
    {
        ans = last / 2;
        if(last & 1) flag = 1;
    }
    else ans = last - k;
    cout << tp * size + ans;
    if(flag) cout << ".5";
    else cout << ".0";
	return 0;
}