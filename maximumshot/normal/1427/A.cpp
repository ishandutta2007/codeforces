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
        vector<int> a(n);
        int sm = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sm += a[i];
        }
        if (sm == 0) {
            cout << "NO\n";
            continue;
        }
        if (sm > 0)
            sort(a.rbegin(), a.rend());
        else
            sort(a.begin(), a.end());
        cout << "YES\n";
        for (int x : a)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}