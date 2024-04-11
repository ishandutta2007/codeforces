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

    int n, m, p;
    cin >> n >> m >> p;

    int I = -1;
    for (int x, i = 0; i < n; i++) {
        cin >> x;
        if (x % p && I == -1) {
            I = i;
        }
    }

    int J = -1;
    for (int x, i = 0; i < m; i++) {
        cin >> x;
        if (x % p && J == -1) {
            J = i;
        }
    }

    cout << I + J << "\n";

    return 0;
}