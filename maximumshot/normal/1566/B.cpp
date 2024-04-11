#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int any0 = 0;
        for (char c : s) if (c == '0') any0 = 1;
        if (!any0) {
            cout << 0 << "\n";
            continue;
        }
        int lpos = inf, rpos = -inf;
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == '0') {
                lpos = min(lpos, i);
                rpos = max(rpos, i);
            }
        }
        int all0 = 1;
        for (int i = lpos; i <= rpos; i++) {
            if (s[i] == '1') {
                all0 = 0;
                break;
            }
        }
        if (all0) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}