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
        int n, m, s = 0;
        cin >> n >> m;
        vector<int> a(n);
        for (int &x : a) {
            cin >> x;
            s += x;
        }
        cout << min(m, s) << "\n";
    }

    return 0;
}