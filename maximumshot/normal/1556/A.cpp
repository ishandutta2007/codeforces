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

void work() {
    int t;
    cin >> t;
    while (t--) {
        ll c, d;
        cin >> c >> d;
        if (c % 2 != d % 2) {
            cout << "-1\n";
        } else {
            if (c == d) {
                if (c == 0)
                    cout << "0\n";
                else
                    cout << "1\n";
            } else {
                cout << "2\n";
            }
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}