#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll t;
const int maxN = 2 * (int)1e5 + 10;
ll a[maxN];
int n;
int x[maxN];
bool bad[maxN];
int bal[maxN];
ll b[maxN];
int main() {
    srand(123 + 23123123 + 123123 - 123123);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        if (x[i] < i) {
            cout << "No";
            return 0;
        }
        bad[x[i]] = true;
        bal[i]++;
        bal[x[i]]--;
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += bal[i];
        if (cur > 0 && bad[i]) {
            cout << "No";
            return 0;
        }
        if (cur > 0) {
            b[i] = a[i + 1] + t;
        }
        else {
            b[i] = max(b[i - 1] + 1, a[i] + t);
            if ((i != n) && bad[i] && b[i] >= a[i + 1] + t) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}