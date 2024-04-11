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
        int a, b;
        cin >> a >> b;
        int total = a + b;
        vector<int> res;
        for (int k = 0; k <= a + b; k++) {
            int ok = 0;
            for (int q = 0; q < 2; q++) {
                int ca = q == 0 ? (total + 1) / 2 : total / 2;
                int cb = total - ca;
                int x = cb - b + k;
                if (x % 2)
                    continue;
                x /= 2;
                if (x < 0 || x > k)
                    continue;
                int y = k - x;
                if (x > a || y > b || x > cb || y > ca)
                    continue;
                ok = 1;
            }
            if (ok)
                res.push_back(k);
        }
        cout << (int) res.size() << "\n";
        for (auto k : res)
            cout << k << " ";
        cout << "\n";
    }

    return 0;
}