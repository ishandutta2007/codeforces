#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <stack>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 100100;

int n, ar[MAXN];
vector<int> adj[MAXN];
ll dp1[MAXN], dp2[MAXN];
bool vis[MAXN];

ll gcd(ll a, ll b) {
    while (1) {
        if (a < b) swap(a, b);
        if (!b) return a;
        ll k = b;
        b = a%b, a = k;
    }
}

ll lcm(ll a, ll b) { return a/gcd(a, b)*b; }

void dfs(int st) {
    stack<pii> stk; stk.push(pii(st, -1));
    while (!stk.empty()) {
        int cur = stk.top().first, p = stk.top().second;
        if (adj[cur].size() == 1 && adj[cur][0] == p) {
            dp1[cur] = ar[cur];
            dp2[cur] = 1;
            stk.pop();
            continue;
        }

        if (!vis[cur]) {
            vis[cur] = 1;
            for (int i=0; i<adj[cur].size(); i++) {
                int nxt = adj[cur][i];
                if (nxt == p) continue;
                stk.push(pii(nxt, cur));
            }
        } else {
            ll l = 1, c = 0, m = 1e18;
            for (int i=0; i<adj[cur].size(); i++) {
                int nxt = adj[cur][i];
                if (nxt == p) continue;
                c++;
                m = min(m, dp1[nxt]);
            }
            for (int i=0; i<adj[cur].size(); i++) {
                int nxt = adj[cur][i];
                if (nxt == p) continue;
                l = lcm(l, dp2[nxt]);
                if (l > m) {
                    dp1[0] = 0;
                    return;
                }
            }
            dp1[cur] = m/l*l*c;
            dp2[cur] = l*c;
            stk.pop();
        }
    }
}

int main() {
    ios :: sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    ll sum = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> ar[i];
        sum += ar[i];
    }

    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0);
    cout << sum-dp1[0] << '\n';
    return 0;
}