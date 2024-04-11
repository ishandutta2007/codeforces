#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define right ololojfs
const int maxN = (int)1e5 + 100;
int d[maxN];
bool was[maxN];
int n;
bool right[maxN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        right[i] = (c == '>');
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        if (!right[i]) d[i] = -d[i];
    }
    int cur = 1;
    for (int iters = 1; iters <= (n + 1); iters++) {
        if (was[cur]) {
            cout << "INFINITE";
            return 0;
        }
        was[cur] = true;
        cur += d[cur];
        if (cur < 1 || cur > n) {
            cout << "FINITE";
            return 0;
        }
    }
    cout << "INFINITE";
}