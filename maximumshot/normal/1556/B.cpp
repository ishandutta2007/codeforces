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

ll calc(vector<int> a, vector<int> b) {
    int n = (int) a.size();
    vector<int> have, need;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[0]) {
            have.push_back(i);
        }
    }
    for (int i = 0; i < n; i += 2)
        need.push_back(i);
    ll res = 0;
    for (int i = 0; i < (int) have.size(); i++)
        res += abs(have[i] - need[i]);
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i], a[i] %= 2;

        int c0 = 0, c1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]) c1++;
            else c0++;
        }
        if (abs(c0 - c1) > 1) {
            cout << "-1\n";
        } else {
            if (c0 == c1) {
                vector<int> b(n);
                for (int i = 0; i < n; i++) b[i] = i % 2;
                ll res = calc(a, b);
                for (auto& x : b) x ^= 1;
                res = min(res, calc(a, b));
                cout << res << "\n";
            } else {
                vector<int> b(n);
                for (int i = 0; i < n; i++) b[i] = i % 2;
                if ((c0 > c1 && b[0]) || (c0 < c1 && !b[0])) {
                    for (auto &x : b) x ^= 1;
                }
                cout << calc(a, b) << "\n";
            }
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}