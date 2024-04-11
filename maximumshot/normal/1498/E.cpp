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

int main() {

//#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
//#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> k(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> k[i];

    vector<int> del(n + 1);

    while (1) {
        int mn_v = -1, mx_v = -1, cn = 0;
        for (int v = 1; v <= n; v++) {
            if (del[v])
                continue;
            cn++;
            if (mn_v == -1 || k[mn_v] > k[v])
                mn_v = v;
            if (mx_v == -1 || k[mx_v] < k[v])
                mx_v = v;
        }
        if (cn == 1) {
            cout << "! 0 0" << endl;
            return 0;
        }
        if (k[mn_v] == 0) {
            del[mn_v] = 1;
            for (int v = 1; v <= n; v++) {
                if (!del[v])
                    k[v]--;
            }
            continue;
        }
        if (k[mx_v] + 1 == cn) {
            del[mx_v] = 1;
            continue;
        }
        vector<pii> pairs;
        for (int v = 1; v <= n; v++) {
            if (del[v])
                continue;
            for (int u = 1; u < v; u++) {
                if (del[u])
                    continue;
                pairs.emplace_back(u, v);
            }
        }
        for (auto& [u, v] : pairs) {
            if (k[u] > k[v])
                swap(u, v);
        }
        for (auto [u, v] : pairs) {
            assert(k[u] <= k[v]);
        }
        auto calc_score = [&](pii p) -> int {
            return abs(k[p.first] - k[p.second]);
        };
        sort(pairs.begin(), pairs.end(), [&](pii p1, pii p2) {
            return calc_score(p1) > calc_score(p2);
        });
        for (auto [u, v] : pairs) {
            cout << "? " << v << " " << u << endl;
            string res;
            cin >> res;
            if (res == "Yes") {
                cout << "! " << u << " " << v << endl;
                return 0;
            }
        }
        cout << "! 0 0" << endl;
        return 0;
    }

    return 0;
}