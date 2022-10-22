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

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> f(m);
        for (int i = 0; i < m; i++) {
            int sz;
            cin >> sz;
            f[i].resize(sz);
            for (int j = 0; j < sz; j++)
                cin >> f[i][j];
        }
        vector<int> days(m);
        for (int i = 0; i < m; i++)
            days[i] = i;
        sort(days.begin(), days.end(), [&](int i, int j) {
            return f[i].size() < f[j].size();
        });
        vector<int> used(n + 1), res(m);
        for (int day : days) {
            int best = -1;
            for (int x : f[day]) {
                if (best == -1 || used[best] > used[x])
                    best = x;
            }
            res[day] = best;
            used[best]++;
        }
        if (*max_element(used.begin() + 1, used.end()) > (m + 1) / 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int x : res)
                cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}