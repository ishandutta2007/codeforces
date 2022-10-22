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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> c(n + 1);
    for (int x : a) c[x]++;

    vector<int> ops;
    auto op = [&](int i) {
        ops.push_back(i);
        int x = 0;
        while (c[x]) x++;
        int y = a[i];
        c[y]--;
        c[x]++;
        a[i] = x;
    };

    while (*max_element(c.begin(), c.end()) > 1) {
        int x = 0;
        while (c[x]) x++;
        // 0 <= x < n
        op(x);
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != i) {
            if (c[i] == 0)
                op(i);
            else {
                for (int j = 0; j < n; j++) {
                    if (a[j] == i) {
                        op(j);
                        op(i);
                        break;
                    }
                }
            }
        }
    }

//    cout << "a = "; for (int x : a) cout << x << " "; cout << "\n";

    cout << (int) ops.size() << "\n";
    for (int i : ops)
        cout << i + 1 << " ";
    cout << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}