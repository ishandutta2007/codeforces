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
        vector<string> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<vector<int>> p(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                p[i][j] = (j > 0 ? p[i][j - 1] : 0) + (a[i][j] == '*');
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 1; i + k - 1 < n; k++) {
                    int l = j - k + 1;
                    int r = j + k - 1;
                    if (l < 0 || r >= m)
                        break;
                    if (p[i + k - 1][r] - (l > 0 ? p[i + k - 1][l - 1] : 0) != r - l + 1)
                        break;
                    res++;
                }
            }
        }
        cout << res << "\n";
    }

    return 0;
}