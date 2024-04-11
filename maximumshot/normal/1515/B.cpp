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

bool is_square(int n) {
    int x = 1;
    while (x * x < n)
        x++;
    return x * x == n;
}

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
        if ((n % 2 == 0 && is_square(n / 2)) || (n % 4 == 0 && is_square(n / 4))) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}