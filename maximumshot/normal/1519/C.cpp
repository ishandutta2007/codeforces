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

const int X = 2e5 + 5;

vector<int> dv[X];

void precalc() {
    for (int x = 1; x < X; x++) {
        for (int y = x; y < X; y += x)
            dv[y].push_back(x);
    }
    for (int x = 1; x < X; x++)
        reverse(dv[x].begin(), dv[x].end());
}

int main() {

    precalc();

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
        vector<vector<int>> a(n + 1);
        vector<int> u(n + 1), s(n + 1);
        vector<ll> F(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> u[i];
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        for (int i = 1; i <= n; i++)
            a[u[i]].push_back(s[i]);
        for (int i = 1; i <= n; i++) {
            sort(a[i].rbegin(), a[i].rend());
            ll S = 0;
            for (int j = 1; j <= (int) a[i].size(); j++) {
                S += a[i][j - 1];
                int rem = (int) a[i].size() - j;
                for (int k : dv[j]) {
                    if (k <= rem)
                        break;
                    F[k] += S;
                }
            }
        }
        for (int k = 1; k <= n; k++)
            cout << F[k] << " ";
        cout << "\n";
    }

    return 0;
}