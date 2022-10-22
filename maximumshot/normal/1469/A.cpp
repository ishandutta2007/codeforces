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

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.size();
        if (n % 2) {
            cout << "NO\n";
            continue;
        }
        int b = 0, ok = 1, cnt = 0;
        for (char c : s) {
            if (c == '(')
                cnt++;
        }
        if (cnt > n / 2) {
            ok = 0;
        } else {
            for (char c : s) {
                if (c == '(') {
                    b++;
                } else if (c == ')') {
                    b--;
                    if (b < 0)
                        ok = 0;
                } else {
                    if (cnt < n / 2)
                        b++, cnt++;
                    else {
                        b--;
                        if (b < 0)
                            ok = 0;
                    }
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}