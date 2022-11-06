#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define Next(a) ((a != x) ? solve(a) : 0)
#define ll long long
using namespace std;
int x, y;
const int mod = 1e9 + 7;
map<int, int> Mp;

ll pw2(ll a)
{
	ll now = 1, x = 2;
	while(a)
	{
		if(a & 1) now = now * x % mod;
		x = x * x % mod;
		a >>= 1;
	}
    return now;
}

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

ll solve(int x)
{
    if (Mp.find(x) != Mp.end()) return Mp[x];
    ll ans = pw2(x - 1);
    for (int i = 1; i * i <= x; i ++)
        if (x % i == 0)
        {
            ans -= Next(x / i);
            ans %= mod;
            ans += mod;
            ans %= mod;
            if (i * i < x) {ans -= Next(i); ans %= mod; ans += mod; ans %= mod;}
        }
    Mp[x] = (int)ans;
    return ans;
}

int main()
{
    int x = read();
    int y = read();
    if (y % x)
    {
    	cout << 0;
        return 0;
    }
	ll ans = (int)solve(y / x);
   	cout << ans;
   	return 0;
}