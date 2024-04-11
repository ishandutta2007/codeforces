#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int64_t INF = 1e9 + 7, INF2 = 1e15;
int n;
int64_t a[nax];
int64_t sum[nax];


bool dc(int l, int r) {
    if (l == r) return true;
    int mid = l + r >> 1;
    if (!dc(l, mid) || !dc(mid + 1, r)) return false;
    for (auto cc = 0 ; cc < 2 ; ++ cc) {
        int64_t s = 0, mx = -INF, mn_s = -INF2;
    static  vector <pair <int64_t, int64_t>> max_sum;max_sum.clear();
        for (int i = mid + 1 ; i <= r ; ++ i) {
            s += a[i], mx = max(mx, a[i]);
            mn_s = max(mn_s, s);
            max_sum.emplace_back(mx, mn_s);
        }
        s = 0;
        mx = -INF;
        auto k = max_sum.begin();
        assert(!max_sum.empty());
        for (int i = mid ; i >= l ; -- i) {
            s += a[i], mx = max(mx, a[i]);
            while (k != max_sum.end() && k->first <= mx) k++;
            if (k == max_sum.begin()) continue;
            auto c = k;
            -- c;
            assert(c->first <= mx);
            if (mx < s + c->second) return  false;
        }
        int dist = r - mid - 1;
        mid = l + dist;
        reverse(a + l, a + r + 1);
    }
    return true;
}

bool solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    return dc(1, n);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ; ) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}