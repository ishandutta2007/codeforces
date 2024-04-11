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
        int n;
        cin >> n;
        vector<int> a(n + 1), used(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            if (!used[a[i]]) {
                used[a[i]] = 1;
                b[i] = a[i];
            }
        }
        {
            vector<pii> paths;
            used.assign(n + 1, 0);
            vector<int> din(n + 1);
            for (int i = 1; i <= n; i++)
                din[b[i]]++;
            for (int i = 1; i <= n; i++) {
                if (used[i] || din[i] > 0)
                    continue;
                int x = i;
                while (1) {
                    used[x] = 1;
                    if (!b[x]) break;
                    x = b[x];
                }
                paths.emplace_back(i, x);
            }
            if ((int) paths.size() == 1) {
                if (paths[0].first != paths[0].second) {
                    b[paths[0].second] = paths[0].first;
                } else {
                    int t = a[paths[0].second];
                    int x = 1;
                    while (x <= n) {
                        if (x != paths[0].second && b[x] == t) {
                            break;
                        }
                        x++;
                    }
                    assert(x <= n);
                    b[paths[0].second] = t;
                    b[x] = paths[0].second;
                }
            } else {
                for (int i = 0; i < (int) paths.size(); i++) {
                    int j = (i + 1) % (int) paths.size();
                    b[paths[i].second] = paths[j].first;
                }
            }
        }
        int total = 0;
        for (int i = 1; i <= n; i++)
            total += int(a[i] == b[i]);
        cout << total << "\n";
        for (int i = 1; i <= n; i++)
            cout << b[i] << " ";
        cout << "\n";
    }

    return 0;
}