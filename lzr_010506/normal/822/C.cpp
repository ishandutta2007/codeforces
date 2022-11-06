#include <bits/stdc++.h>
#define ll long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;
const int N = 3e5;
const ll INF = 1e16;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const ll mod = 10000000007ll;

ll pre[N];
vector<pii> vc1[N], vc2[N];

int main()
{
    int n, x;
    n = read();
    x = read();
    for(int i = 0; i < n; i ++)
    {
        int l, r, c;
        l = read();
        r = read();
        c = read();
        int len = r - l + 1;
        vc1[l].pb(mp(len,c));
        vc2[r].pb(mp(len,c));
    }
    for(int i = 0; i < N; i ++) pre[i] = mod;
    ll ans = mod;
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j < vc1[i].size(); j ++)
        {
            int len = vc1[i][j].X;
            if(len>=x) continue;
            ll cost = vc1[i][j].Y + pre[x - len];
            ans = min(ans, cost);
        }
        for(int j = 0; j < vc2[i].size(); j ++)
        {
            int len = vc2[i][j].X;
            ll cost = vc2[i][j].Y;
            pre[len] = min(pre[len], cost);
        }
    }
    if(ans == mod) ans = -1;
    printf("%lld\n", ans);
    return 0;
}