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

ll fast(int n, vector<int> c) {
    ll res = 0;
    for (int i = 0; i < n; i += 2) {
        ll B = 0;
        ll minB = inf64;
        for (int j = i + 1; j < n; j += 2) {
            if (j > i + 1) {
                // j - 2, j - 1
                minB = min(minB, B - c[j - 2]);
                B += -c[j - 2] + c[j - 1];
            }
            ll lx = 1;
            ll rx = c[i];
            lx = max(lx, 1 - B);
            lx = max(lx, -minB);
            rx = min(rx, c[j] - B);
            if (lx <= rx) {
                res += rx - lx + 1;
            }
        }
    }
    return res;
}

void work() {
    int t;
    t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> c(n);
        for (int i = 0; i < n; i++)
            cin >> c[i];
        ll res = fast(n, c);
        cout << res << "\n";
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