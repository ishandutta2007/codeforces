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

const int X = 1e6 + 5;

int pr[X];

int main() {

    fill(pr, pr + X, 1);
    pr[0] = pr[1] = 0;
    for (int p = 2; p * p < X; p++) {
        if (!pr[p]) continue;
        for (int x = p * p; x < X; x += p) {
            pr[x] = 0;
        }
    }

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> res;

    for (int i = 1; i <= n; i++) {
        int j = i < n ? i + 1 : 1;
        res.emplace_back(i, j);
    }

    for (int i = 0; i < n / 2 && !pr[(int) res.size()]; i++) {
        res.emplace_back(i + 1, i + n / 2 + 1);
    }

    cout << (int) res.size() << '\n';

    vector<int> d(n + 1);
    for (pii p : res) {
        d[p.first]++;
        d[p.second]++;
    }

    for (int i = 1; i <= n; i++) {
        assert(pr[d[i]]);
    }

    assert(pr[(int) res.size()]);

    for (pii p : res) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}