#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
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
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
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
const int N = 1000010;
int n;
int mn[N], mx[N], rsx[N], rsn[N];
bool flag[N];
int main()
{
	n = read();
    memset(mn, 0x3f3f3f3f, sizeof(mn));
    memset(mx, -1, sizeof(mx));
    memset(flag, 0, sizeof(flag));
    rep(i, 1, n)
    {
        int times = read();
        while(times --)
        {
        	int x = read();
            if (x > mn[i]) flag[i] = 1;
            mn[i] = min(mn[i], x);
            mx[i] = max(mx[i], x);
        }
    }
    int num = 0;
    rep(i, 1, n)
    {
        if (flag[i])
        {
            if(num != -1) num ++;
            continue;
        }
        rsn[mn[i]] ++;
        rsx[mx[i]] ++;
    }
    rep0(i, N) rsn[i] += rsn[i - 1], rsx[i] += rsx[i - 1];
    ll ans = 0;
    rep(i, 1, n)
    {
        if (flag[i])
        {
            ans += n;
            continue;
        }
        ans += rsn[mx[i] - 1];
        ans += num;
    }
    printf("%lld\n", ans);
    return 0;
}