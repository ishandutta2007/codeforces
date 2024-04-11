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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int res = 0;
        for (int j = 0;;) {
            int is_sort = 1;
            for (int q = j; q + 1 < n; q++)
                is_sort &= a[q] <= a[q + 1];
            if (is_sort)
                break;
            int m = j;
            while (m < n && a[m] <= x)
                m++;
            is_sort = 1;
            for (int q = j; q + 1 < m; q++)
                is_sort &= a[q] <= a[q + 1];
            if (!is_sort) {
                res = -1;
                break;
            }
            assert(m < n);
            swap(x, a[m]);
            j = m;
            res++;
        }
        cout << res << "\n";
    }

    return 0;
}