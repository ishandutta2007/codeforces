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

const int N = 2e5 + 5;

int n, q;
int a[N];
int dp[N], pr[N];

void read() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void solve() {
    fill(dp, dp + n + 1, 0);
    fill(pr, pr + n + 1, 0);
    unordered_map<int, int> mn, mx, cn;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        if (!mn.count(x)) mn[x] = n + 1;
        if (!mx.count(x)) mx[x] = 0;
        mn[x] = min(mn[x], i);
        mx[x] = max(mx[x], i);
        cn[x]++;
    }
    vector<pair<pii, int>> segs;
    for (pii item : mn) {
        int x = item.first;
        segs.emplace_back(make_pair(mx[x], mn[x]), cn[x]);
    }
    sort(segs.begin(), segs.end());
    vector<pii> st;
    for (auto it : segs) {
        int l, r, w;
        tie(r, l) = it.first;
        w = it.second;
        while (!st.empty() && st.back().first > l) {
            int ww = st.back().second;
            w = max(w, ww);
            st.pop_back();
        }
        st.emplace_back(r, w);
    }
    int res = 0;
    for (auto it : st) res += it.second;
    cout << n - res << "\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();

    return 0;
}