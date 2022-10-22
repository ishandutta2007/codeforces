#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct Fen {
    int n = 0; // [0, n)
    vector<int> f;

    Fen() = default;

    Fen(int nn) {
        n = nn;
        f.resize(n, -inf);
    }

    void upd(int i, int x) {
        for (int cur = i; cur < n; cur |= (cur + 1))
            f[cur] = max(f[cur], x);
    }

    int get(int i) {
        int res = -inf;
        for (int cur = i; cur >= 0; cur = (cur & (cur + 1)) - 1)
            res = max(res, f[cur]);
        return res;
    }
};

void work() {
    int n, d;
    cin >> n >> d;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [](pii p1, pii p2) {
        int m1 = max(p1.first, p1.second);
        int m2 = max(p2.first, p2.second);
        if (m1 != m2) return m1 < m2;
        return p1.first < p2.first;
//        return max(p1.first, p1.second) < max(p2.first, p2.second);
//        return p
    });
    int res = 0;
    int cur = d;
    for (auto [ss, aa] : a) {
        if (ss >= cur) res++, cur = max(cur, aa);
    }
    cout << res << "\n";
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}