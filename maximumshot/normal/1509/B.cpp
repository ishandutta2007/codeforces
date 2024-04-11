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
        string s;
        cin >> s;
        vector<int> ts, ms;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'T')
                ts.push_back(i);
            if (s[i] == 'M')
                ms.push_back(i);
        }
        if ((int) ts.size() != 2 * n / 3 || (int) ms.size() != n / 3) {
            cout << "NO\n";
            continue;
        }
        int ok = 1;
        for (int i = 0; i < n / 3; i++) {
            if (ts[i] < ms[i] && ms[i] < ts[i + n / 3]) {}
            else {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}