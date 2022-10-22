#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct DSU {
    int n = 0;
    vector<int> p;

    DSU(int nn) {
        n = nn;
        p.resize(n);
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        p[y] = x;
    }
};

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;

        DSU dsu(n);
        vector<int> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
            perm[i] = i;
        sort(perm.begin(), perm.end(), [&](int i, int j) {
            return h[i] > h[j];
        });
        vector<int> color(n);
        set<pii> Q;
        vector<int> S(m);
        for (int i = 0; i < m; i++)
            Q.insert({S[i], i});
        for (int i : perm) {
            int j = Q.begin()->second;
            Q.erase(Q.begin());
            S[j] += h[i];
            color[i] = j + 1;
            Q.insert({S[j], j});
        }
        if (*max_element(S.begin(), S.end()) - *min_element(S.begin(), S.end()) <= x) {
            cout << "YES\n";
            for (auto val : color)
                cout << val << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}