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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vector<int> ar = {a, b, c, d};
        sort(ar.begin(), ar.end());
        if ((a >= ar[2] && b >= ar[2]) || (c >= ar[2] && d >= ar[2])) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}