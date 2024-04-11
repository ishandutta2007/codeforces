#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int cc = 1;
        for (int i = 1; i < n; i++)
            if (a[i] > a[i - 1])
                cc++;
        if (k == 1) {
            if (cc > 1) {
                cout << "-1\n";
            } else {
                cout << "1\n";
            }
        } else {
            if (k >= cc) {
                cout << "1\n";
            } else {
                cc -= k;
                cout << 1 + (cc + k - 2) / (k - 1) << "\n";
            }
        }
    }

    return 0;
}