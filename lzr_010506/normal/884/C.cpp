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

int p[N], vis[N];
int n;

int dfs(int u)
{
    int cnt = 0;
    while (!vis[u])
    {
        vis[u] = 1;
        cnt ++;
        u = p[u];
    }
    return cnt;
}

vector<int> V;

int main()
{
    n = read();
    rep(i, 1, n) p[i] = read();
    rep(i, 1, n) if (!vis[i]) V.push_back(dfs(i));
    sort(V.begin(), V.end(), greater<int>());
    ll ans = 0;
    int nn = V.size() - 1;
    rep(i, 0, nn)
    if (i == 1)
    {
        ans -= 1ll * V[i - 1] * V[i - 1];
        ans += 1ll * (V[i - 1] + V[i]) * (V[i - 1] + V[i]);
    }
    else ans += 1ll * V[i] * V[i];
    
    printf("%I64d\n", ans);
    return 0;
}