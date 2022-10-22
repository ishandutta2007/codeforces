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
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n), p(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                cout << a[i] << " ";
                p[i] = a[i];
            } else if (i + 1 == n) {
                vector<int> cs = {a[i], b[i], c[i]};
                for (int x : cs) {
                    if (x != p[i - 1] && x != p[0]) {
                        p[i] = x;
                        cout << x << " ";
                        break;
                    }
                }
            } else {
                vector<int> cs = {a[i], b[i], c[i]};
                for (int x : cs) {
                    if (x != p[i - 1]) {
                        p[i] = x;
                        cout << x << " ";
                        break;
                    }
                }
            }
        }
        cout << "\n";
    }

    return 0;
}