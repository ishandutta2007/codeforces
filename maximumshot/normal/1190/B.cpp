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

const int N = 1e5 + 5;

int n;
int a[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int cnt_eq = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1]) {
            cnt_eq++;
        }
    }

    if (cnt_eq > 1) {
        cout << "cslnb\n";
        return 0;
    }

    if (cnt_eq == 1) {
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i + 1]) {
                if (a[i] == 0 || (i > 1 && a[i - 1] + 1 == a[i])) {
                    cout << "cslnb\n";
                    return 0;
                } else {
                    a[i]--;
                }
            }
        }
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            res += a[i] - (i - 1);
        }
        cout << (res % 2 == 0 ? "sjfnb" : "cslnb") << "\n";
    } else {
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            res += a[i] - (i - 1);
        }
        cout << (res % 2 == 1 ? "sjfnb" : "cslnb") << "\n";
    }

    return 0;
}