#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
const int P = 29;
const int N = 100005;
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
int n, a[200010];
ll ans, rest;
priority_queue<ll, vector<ll>, greater<ll> > Q;
int main()
{
	n = read();
	rep(i, 1, n) Q.push(read());
    while (Q.size() % 2 != 1) Q.push(0);
    ll ans = 0;
    while (Q.size() > 1)
    {
        ll x = Q.top(); Q.pop();
        x += Q.top(); Q.pop();
        x += Q.top(); Q.pop();
        ans += x;
        Q.push(x);
    }

    printf("%lld\n", ans);
	return 0;
}