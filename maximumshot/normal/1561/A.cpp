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
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        auto is_sorted = [&]() -> bool {
            for (int i = 1; i < n; i++) {
                if (a[i] > a[i + 1])
                    return false;
            }
            return true;
        };
        auto f = [&](int i) {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        };
        int res = 0;
        while (!is_sorted()) {
            res++;
            for (int i = res % 2 ? 1 : 2; i < n; i += 2)
                f(i);
        }
        cout << res << "\n";
    }

    return 0;
}