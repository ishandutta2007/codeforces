#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define elif else if
#define int long long
#define rt return
void pe() { cout << "Shit happens ;(\n"; exit(0); }
const int BINF = 9e8, LINF = 2e9, mod = 1e9 + 7, P = 179, Q = 1791791791;
map<int, vector<int>> g;
map<int, int> clr;
map<int, int> vis;
int d[15];
int s;
vector<int> cc;
vector<int> ans;
bool ok;
void dfs(int v) {
    if (!ok)
        cc.push_back(v);
    vis[v] = 1;
    for (int u : g[v])
        if (!vis[u])
            dfs(u);
        else if (vis[u] == 1) {
            ans.clear();
            bool add = 0;
            for (int x : cc) {
                if (x == u)
                    add = 1;
                if (add)
                    ans.push_back(x);
            }
            ok = 1;
        }
    vis[v] = 2;
    if (!ok)
        cc.pop_back();
}
int f[1 << 15];
struct answ {
    int f, t, x;
};
vector<answ> per[1 << 15];
int dp[1 << 15];
pair<int, int> gans[15];
void solve() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            clr[x] = i;
            s += x;
            d[i] -= x;
        }
    }
    if (s % k != 0) {
        cout << "No";
        return;
    }
    s /= k;
    for (int i = 0; i < k; ++i)
        d[i] += s;
    for (pair<int, int> p : clr) {
        int nx = d[p.y] + p.x;
        if (clr.find(nx) != clr.end())
            g[p.x].push_back(nx);
    }
    fill(dp, dp + (1 << 15), -1);
    for (pair<int, int> p : clr) {
        cc.clear(), ok = 0;
        dfs(p.x);
        if (ok) {
            int mask = 0;
            if (ans.size() == 0)
                pe();
            bool cok = 1;
            vector<answ> output;
            int lastc = -1;
            vector<pair<int, int>> nei;
            vector<int> vals;
            for (int x : ans) {
                if ((mask >> clr[x]) & 1)
                    cok = 0;
                mask |= 1 << clr[x];
                if (lastc != -1)
                    nei.push_back({clr[x], lastc});
                vals.push_back(x);
                lastc = clr[x];
            }
            nei.push_back({clr[ans[0]], lastc});
            for (int i = 0; i < ans.size(); ++i)
                output.push_back({nei[i].x, nei[i].y, vals[(i + 1 + ans.size()) % ans.size()]});
            if (cok) {
                dp[mask] = mask;
                f[mask] = 1;
                per[mask] = output;
            }
        }
    }
    for (int mask = 1; mask < (1 << k); ++mask)
        for (int smask = (mask - 1) & mask; smask > 0; smask = (smask - 1) & mask)
            if (dp[mask ^ smask] != -1 && f[smask])
                dp[mask] = smask;
    int curr = (1 << k) - 1;
    if (dp[curr] == -1) {
        cout << "No";
        return;
    }
    while (curr) {
        int part = dp[curr];
        curr ^= part;
        for (answ a : per[part])
            gans[a.f] = {a.t, a.x};
    }
    cout << "Yes\n";
    for (int i = 0; i < k; ++i)
        cout << gans[i].y << " " << gans[i].x + 1 << "\n";
    return;
}
signed main() {
    ios_base::sync_with_stdio(false);
 
    solve();
 
    return 0;
}