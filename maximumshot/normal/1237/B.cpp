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

    vector<int> a(n + 1), b(n + 1), p(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] = p[b[i]];
    }

    int res = 0, mn = n + 1;

    for (int i = n; i >= 1; i--) {
        if (b[i] > mn) {
            res++;
        } else {
            mn = b[i];
        }
    }

    cout << res << "\n";

    return 0;
}