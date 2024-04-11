#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    string s;
    cin >> s;

    int l0 = n, l1 = n, r0 = -1, r1 = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            l0 = min(l0, i);
            r0 = max(r0, i);
        } else {
            l1 = min(l1, i);
            r1 = max(r1, i);
        }
    }

    if (r0 - l0 + 1 <= k || r1 - l1 + 1 <= k) {
        cout << "tokitsukaze\n";
        return 0;
    }

    set<int> q0, q1;

    for (int i = k; i < n; i++) {
        if (s[i] == '0') {
            q0.insert(i);
        } else {
            q1.insert(i);
        }
    }

    for (int l = 0; l + k - 1 < n; l++) {
        {
            l0 = l1 = n;
            r0 = r1 = -1;
            if (!q0.empty()) {
                l0 = min(l0, *q0.begin());
                r0 = max(r0, *(--q0.end()));
            }
            if (!q1.empty()) {
                l1 = min(l1, *q1.begin());
                r1 = max(r1, *(--q1.end()));
            }
            l0 = min(l0, l);
            r0 = max(r0, l + k - 1);
            if (r0 - l0 + 1 > k && r1 - l1 + 1 > k) {
                cout << "once again\n";
                return 0;
            }
        }
        {
            l0 = l1 = n;
            r0 = r1 = -1;
            if (!q0.empty()) {
                l0 = min(l0, *q0.begin());
                r0 = max(r0, *(--q0.end()));
            }
            if (!q1.empty()) {
                l1 = min(l1, *q1.begin());
                r1 = max(r1, *(--q1.end()));
            }
            l1 = min(l1, l);
            r1 = max(r1, l + k - 1);
            if (r0 - l0 + 1 > k && r1 - l1 + 1 > k) {
                cout << "once again\n";
                return 0;
            }
        }
        if (l + k < n) {
            if (s[l + k] == '0') {
                q0.erase(l + k);
            } else {
                q1.erase(l + k);
            }
        }
        if (s[l] == '0') {
            q0.insert(l);
        } else {
            q1.insert(l);
        }
    }

    cout << "quailty\n";

    return 0;
}