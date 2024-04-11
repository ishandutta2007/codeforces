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

vector<pii> fast(int n) {
    vector<pii> res;
    if (n <= 8) {
        for (int i = 3; i < n; i++)
            res.emplace_back(i, n);
        for (int x = n; x > 1; x = (x + 1) / 2)
            res.emplace_back(n, 2);
        return res;
    }
    for (int i = 3; i < n; i++) {
        if (i == 8)
            continue;
        res.emplace_back(i, n);
    }
    for (int x = n; x > 1; x = (x + 7) / 8)
        res.emplace_back(n, 8);
    for (int x = 8; x > 1; x = (x + 1) / 2)
        res.emplace_back(8, 2);
    return res;
}

void check(int n, vector<pii> res) {
    if ((int) res.size() > n + 5) {
        cout << "WA\ntoo big\n";
        cout << "sz = " << (int) res.size() << "\n";
        return;
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    for (auto [x, y] : res)
        a[x] = (a[x] + a[y] - 1) / a[y];
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1)
            c1++;
        if (a[i] == 2)
            c2++;
    }
    if (c2 != 1 || c1 + c2 != n) {
        cout << "WA\ninconsistent\nc1 = " << c1 << "\nc2 = " << c2 << "\n";
        return;
    }
    cout << "OK\n";
}

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
        vector<pii> fs = fast(n);
//        check(n, fs);

        cout << (int) fs.size() << "\n";
        for (auto [x, y] : fs)
            cout << x << " " << y << "\n";
    }

    return 0;
}