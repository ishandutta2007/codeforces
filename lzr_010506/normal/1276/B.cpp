#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<sum2r, sum2r>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define sti set<int>::iterator
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
const int N = 2e5 + 10;
int n, m, a, b, vis1[N], vis2[N];
vi G[N];

void dfs1(int x)
{
    if(x == b) return;
    for(auto to : G[x])
    {
        if(vis1[to] == 1) continue;
        vis1[to] = 1;
        dfs1(to);
    }
}

void dfs2(int x)
{
    if(x == a) return;
    for(auto to : G[x])
    {
        if(vis2[to] == 1) continue;
        vis2[to] = 1;
        dfs2(to);
    }
}

int main()
{
    int T = read();
    while(T --)
    {
        n = read();
        m = read();
        a = read();
        b = read();
        rep(i, 1, n) G[i].clear(), vis1[i] = 0, vis2[i] = 0;
        rep(i, 1, m)
        {
            int x = read();
            int y = read();
            G[x].pb(y);
            G[y].pb(x);
        }
        dfs1(a);
        dfs2(b);
        int cnt1 = 0, cnt2 = 0;
        rep(i, 1, n)
        {
            if(vis1[i] == 1 && vis2[i] == 0) cnt1 ++;
            if(vis1[i] == 0 && vis2[i] == 1) cnt2 ++;
        }
        printf("%lld\n", 1LL * cnt1 * cnt2);
    }
    return 0;
}