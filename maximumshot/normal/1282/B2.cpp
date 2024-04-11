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

void solve() {
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int res = 0;
    vector<int> b(a.size());
    for (int i = 0; i < (int) b.size(); i++) {
        b[i] = a[i];
        if (i >= k)
            b[i] += b[i - k];
    }
//    for (int x : a)2
//        cout << x << " ";
//    cout << "\n";
//    for (int x : b)
//        cout << x << " ";
//    cout << "\n";
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];
    for (int i = 0; i < n; i++) {
        ll sm = b[i] + (a[i % k] - b[i % k]) * ((i + 1) % k != 0);
        if (sm <= p) {
            res = max(res, i + 1);
        }
    }
    cout << res << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}