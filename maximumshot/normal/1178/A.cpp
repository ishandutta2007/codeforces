#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
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
    vector<int> a(n), res;

    int total = 0;
    for (int i = 0; i < n; i++) {
         cin >> a[i];
         if (i == 0 || 2 * a[i] <= a[0]) {
             res.push_back(i + 1);
             total += a[i];
         } else {
             total -= a[i];
         }
    }

    if (total > 0) {
        cout << (int) res.size() << "\n";
        for (int x : res) {
            cout << x << " ";
        }
        cout << "\n";
    } else {
        cout << "0\n";
    }

    return 0;
}