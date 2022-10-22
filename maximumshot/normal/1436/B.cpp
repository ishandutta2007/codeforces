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
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        if (n % 2) {
            for (int i = 1; i <= 3; i++)
                for (int j = 1; j <= 3; j++)
                    a[n - i][n - j] = 1;
            n -= 3;
        }
        for (int i = 0; i < n; i += 2) {
            a[i][i] = 1;
            a[i][i + 1] = 1;
            a[i + 1][i] = 1;
            a[i + 1][i + 1] = 1;
        }

        for (auto row : a) {
            for (auto x : row)
                cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}