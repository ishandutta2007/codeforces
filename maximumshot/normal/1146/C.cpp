#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

int ask(vector<int> a, vector<int> b) {
    cout << (int)a.size() << " " << (int)b.size() << " ";
    for (int x : a) {
        cout << x << " ";
    }
    for (int x : b) {
        cout << x << " ";
    }
    cout << endl;
    int res;
    cin >> res;
    if (res == -1) {
        exit(0);
    }
    return res;
}

int ask(int s, int l, int r) {
    vector<int> a = {s};
    vector<int> b;
    for (int x = l; x <= r; x++) {
        b.push_back(x);
    }
    return ask(a, b);
}

void solve() {
    int n;
    cin >> n;
    int l = 1;
    int r = n - 1;
    int m;
    int mx = ask(n, 1, n - 1);
    while (l < r) {
        m = (l + r) / 2;
        if (ask(n, l, m) == mx) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    {
        vector<int> a = {l}, b;
        for (int x = 1; x <= n; x++) {
            if (x != l) {
                b.push_back(x);
            }
        }
        int res = ask(a, b);
        cout << "-1 " << res << endl;
    }
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;

    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}