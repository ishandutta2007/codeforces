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

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for (int iter = 0; iter < q; iter++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            sum -= a[x];
            a[x] ^= 1;
            sum += a[x];
        } else {
            int k;
            cin >> k;
            if (k <= sum) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }

    return 0;
}