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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    auto print = [&](vector<int> ar) {
        cout << "Yes\n";
        for (int x : ar)
            cout << x << " ";
        cout << "\n";
    };

    auto check = [&](vector<int> ar) -> bool {
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (ar[j] != a[i][j])
                    cnt++;
            }
            if (cnt > 2)
                return false;
        }
        return true;
    };

    for (int i = 1; i < n; i++) {
        vector<int> js;
        for (int j = 0; j < m; j++) {
            if (a[0][j] != a[i][j]) {
                js.push_back(j);
            }
        }
        if ((int) js.size() > 2) {
            js.resize(3);
            for (int i0 : {0, i}) {
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (x == y)
                            continue;
                        vector<int> hlp = a[i0];
                        hlp[js[x]] = a[0][js[x]];
                        hlp[js[y]] = a[i][js[y]];
                        for (int z = 0; z < 3; z++) {
                            if (x == z || y == z)
                                continue;
                            int j0 = js[z];
                            for (int p = 0; p < n; p++) {
                                int cnt = 0;
                                for (int q = 0; q < m; q++) {
                                    if (q == j0)
                                        continue;
                                    if (a[p][q] != hlp[q])
                                        cnt++;
                                }
                                if (cnt > 1) {
                                    hlp[j0] = a[p][j0];
                                    break;
                                }
                            }
                            if (check(hlp)) {
                                print(hlp);
                                return 0;
                            }
                        }
                    }
                }
            }
            cout << "No\n";
            return 0;
        }
    }

    print(a[0]);

    return 0;
}