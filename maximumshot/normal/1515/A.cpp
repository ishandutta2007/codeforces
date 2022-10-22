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
        int n, x;
        cin >> n >> x;
        vector<int> w(n);
        for (int i = 0; i < n; i++)
            cin >> w[i];
        sort(w.begin(), w.end());
        int cur = 0, ok = 1;
        for (int i = 0; i < n; i++) {
            cur += w[i];
            if (cur == x) {
                if (i + 1 < n) {
                    swap(w[i], w.back());
                    break;
                } else {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok) {
            cout << "YES\n";
            for (auto val : w)
                cout << val << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}