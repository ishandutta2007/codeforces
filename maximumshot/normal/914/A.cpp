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

    const int X = 1e6 + 5;

    vector<int> u(X);
    for (int i = 0; i * i < X; i++)
        u[i * i] = 1;

    int n;
    cin >> n;

    int res = -inf;
    for (int x, i = 0; i < n; i++) {
        cin >> x;
        if (x < 0 || !u[x])
            res = max(res, x);
    }

    cout << res << "\n";

    return 0;
}