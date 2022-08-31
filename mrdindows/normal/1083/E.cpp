#include <bits/stdc++.h>
 
#define taskname ""
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex <ld> cd;
typedef vector <cd> vcd;
typedef vector <int> vi;
 
template<class T> using v2d = vector <vector <T> >;
template<class T> bool uin(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template<class T> bool uax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}
 
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
 
const int maxN = 1e6 + 10;
const ll inf = 1e18;
 
struct Line
{
    ll a, b;
    Line() {}
    Line(ll a, ll b) : a(a), b(b) {}
    ll valueAt(ll x)
    {
        return a * x + b;
    }
    ld intersectX(Line l)
    {
        return -(ld)(b - l.b) / (a - l.a);
    }
};
 
int n;
struct rec
{
    ll x, y, a;
    rec() {}
} h[maxN];
ll dp[maxN], res = -inf;
int head = 1e6, tail = 1e6;
Line d[maxN * 2];
 
void addLine(Line l)
{
    while (tail - head >= 2 && l.intersectX(d[head]) >= d[head].intersectX(d[head + 1]))
    {
        ++head;
    }
    d[--head] = l;
}
 
ll maxAt(ll x)
{
    while (tail - head >= 2 && d[tail - 1].valueAt(x) <= d[tail - 2].valueAt(x))
    {
        --tail;
    }
    return d[tail - 1].valueAt(x);
}
 
inline ll Read()
{
    ll x = 0;
    char c = _getchar_nolock();
    while (c < 48) c = _getchar_nolock();
    while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = _getchar_nolock();
    return x;
}
 
void solve()
{
    n = Read();
    for1(i, n)
    {
        h[i].x = Read();
        h[i].y = Read();
        h[i].a = Read();
    }
    sort(h + 1, h + n + 1, [](const rec &l, const rec &r)
    {
        return l.x < r.x;
    });
    addLine(Line(0, 0));
    for1(i, n)
    {
        dp[i] = maxAt(h[i].y) + h[i].x * h[i].y - h[i].a;
        uax(res, dp[i]);
        addLine(Line(-h[i].x, dp[i]));
    }
    printf("%I64d", res);
}
 
int main()
{
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}