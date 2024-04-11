#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int LOG = 30;

struct Trie {
    vector<vector<int>> nxt;
    vector<int> par, sz;

    int add_vertex() {
        nxt.push_back(vector<int>(2, -1));
        par.push_back(-1);
        sz.push_back(0);
        return (int) nxt.size() - 1;
    }

    Trie() {
        add_vertex();
    }

    void add(int x) {
        int v = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            int k = (x >> i) & 1;
            if (nxt[v][k] == -1) {
                int to = add_vertex();
                nxt[v][k] = to;
                par[to] = v;
            }
            v = nxt[v][k];
        }
        while (v != -1)
            sz[v]++, v = par[v];
    }

    int query() {
        vector<int> dp(nxt.size());
        for (int v = (int) nxt.size() - 1; v >= 0; v--) {
            int l = nxt[v][0];
            int r = nxt[v][1];
            if (l == -1 && r == -1) {
                dp[v] = 1;
                continue;
            }
            int sl = l == -1 ? 0 : sz[l];
            int sr = r == -1 ? 0 : sz[r];
            if (sl < sr)
                swap(sl, sr), swap(l, r);
            if (sr > 1)
                dp[v] = max(dp[l], dp[r]) + 1;
            else
                dp[v] = dp[l] + (sr > 0 ? 1 : 0);
        }
        return dp[0];
    }
};

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Trie trie;
    for (int x : a)
        trie.add(x);

    cout << n - trie.query() << "\n";

    return 0;
}