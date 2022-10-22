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
        int n;
        cin >> n;
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> d[i];
        sort(d.begin() + 1, d.end());
        ll S = d[n];
        ll sf = 0;
        for (int i = n; i >= 1; i--) {
            S += d[i] * ll(n - i) - sf;
            sf += d[i];
//            for (int j = i + 1; j <= n; j++)
//                S += d[i] - d[j];
        }
        cout << S << "\n";
    }

    return 0;
}