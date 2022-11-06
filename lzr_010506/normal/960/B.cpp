#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db long double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi totor<int>
#define vl totor<ll>
#define rep(i, x, y) for(register int i = x; i <= y; i ++)
#define rrep(i, x, y) for(register int i = x; i >= y; i --)
#define eps 1e-15
#define lb(x) x & -x
#define sz(x) (x).size()
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
int n, k1, k2;
int a[1000010], b[1000010];
ll ans;
multiset<int, greater<int> > c;
int main()
{
	n = read();
	k1 = read();
	k2 = read();
	rep(i, 1, n)
		a[i] = read();
	rep(i, 1, n)
		b[i] = read();
	rep(i, 1, n)
		c.insert(abs(a[i] - b[i]));
	int k = k1 + k2;
	while(k1 + k2)
	{
	    int pos = 0, mx = -1;
        rep(i, 1, n)
            if(abs(a[i] - b[i]) > mx) mx = abs(a[i] - b[i]), pos = i;
        if(a[pos] > b[pos])
        {
            if(k1 > 0) k1 --, a[pos] --;
            else k2 --, b[pos] ++;
        }
        else
        {
            if(k1 > 0) k1 --, a[pos] ++;
            else k2 --, b[pos] --;
        }
	}
	rep(i, 1, n)
        ans += (ll)(a[i] - b[i]) * (a[i] - b[i]);
    cout << ans;
	return 0;
}