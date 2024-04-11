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
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];
        vector<int> used(n + 1, 1);
        for (int mx = n, i = n - 1; i >= 0;) {
            while (!used[mx])
                mx--;
            used[mx] = 0;
            int j = i;
            while (p[j] != mx) {
                used[p[j]] = 0;
                j--;
            }
            for (int q = j; q <= i; q++)
                cout << p[q] << " ";
            i = j - 1;
        }
        cout << "\n";
    }

    return 0;
}