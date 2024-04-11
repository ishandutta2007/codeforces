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

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll s = 0;
    vector<int> a(n), can(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2) {
            can[i] = 1;
            a[i] = (a[i] - 1) / 2;
        } else {
            a[i] /= 2;
        }
        s += a[i];
    }

    for (int i = 0; i < n; i++) {
        if (!can[i]) {
            cout << a[i] << " ";
        } else {
            if (s < 0) {
                s++;
                a[i]++;
            }
            cout << a[i] << " ";
        }
    }

    cout << "\n";

    return 0;
}