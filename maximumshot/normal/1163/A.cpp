#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

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

    if (m == 0) {
        cout << "1\n";
        return 0;
    }

    if (n % 2 == 0) {
        if (m <= n / 2) {
            cout << m << "\n";
        } else {
            cout << n - m << "\n";
        }
    } else {
        if (m <= n / 2) {
            cout << m << "\n";
        } else {
            int cnt = n / 2;
            m -= cnt;
            if (m > 0) {
                m--;
            }
            cnt -= m;
            cout << cnt << "\n";
        }
    }

    return 0;
}