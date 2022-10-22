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

    int tt;
    cin >> tt;

    for (int ti = 0; ti < tt; ti++) {
        ll a, b, n;
        cin >> a >> b >> n;
        int res = 0;
        while (a <= n && b <= n) {
            if (a > b)
                b += a;
            else
                a += b;
            res++;
        }
        cout << res << "\n";
    }

    return 0;
}