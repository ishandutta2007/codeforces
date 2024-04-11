#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    // 2*3,2*5,2*7 = 6,10,14
    // 3*5,3*7=15,21
    // 6, 10, 14, 15

    int tt;
    cin >> tt;

    for (int ti = 0; ti < tt; ti++) {
        int n;
        cin >> n;
        n -= (6 + 10 + 14);
        if (n <= 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        if (n == 6) { // n' = 36
            cout << "1 6 14 15\n";
        } else if (n == 10) { // n' == 40
            cout << "6 9 10 15\n";
        } else if (n == 14) { // n' == 44
            cout << "6 10 13 15\n";
        } else if (n > 0) {
            set<int> q = {6, 10, 14, n};
            for  (int x : q)
                cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}