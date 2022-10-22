#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    if (*max_element(a.begin(), a.end()) > *min_element(b.begin(), b.end())) {
        cout << "-1\n";
        return 0;
    }

    ll res = 0;

    for (int i = 0; i < n; i++) {
        res += 1ll * a[i] * m;
    }

    int mx1 = 0;
    int mx2 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > mx1) {
            mx2 = mx1;
            mx1 = a[i];
        } else if (a[i] > mx2) {
            mx2 = a[i];
        }
    }

    sort(b.begin(), b.end());

    ll t1 = 0;
    ll t2 = 0;

    for (int i = 0; i < m; i++) {
        if (i > 0) {
            t1 += b[i] - mx1;
            t2 += b[i] - mx2;
        } else {
            if (mx1 == b[i]) {
            } else {
                t1 += b[i] - mx2;
            }
            if (mx2 == b[i]) {

            } else {
                t2 += b[i] - mx1;
            }
        }
    }

    cout << res + min(t1, t2) << "\n";

    return 0;
}