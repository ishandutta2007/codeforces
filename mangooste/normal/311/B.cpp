#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long) 1e18;

struct Cht {
    struct Line {
        long long k;
        long long b;
 
        Line(long long k = 0, long long b = 0) :
            k(k), b(b)
        {}
 
        inline long long getVal(long long x) {
            return k * x + b;
        }
    };
 
    vector<Line> cht;
 
    Cht() :
        cht(vector<Line>())
    {}

    inline bool better(Line a, Line b, Line c) {
        assert(a.k > b.k && b.k > c.k);
        return (c.b - a.b) * (a.k - b.k) <= (b.b - a.b) * (a.k - c.k);
    }
 
    inline void addLine(long long k, long long b) {
        Line ln = Line(k, b);
        while (cht.size() && cht.back().k == ln.k) {
            if (cht.back().b <= ln.b) {
                return;
            }
            cht.pop_back();
        }
        while ((int) cht.size() >= 2 && better(cht[(int) cht.size() - 2], cht.back(), ln)) {
            cht.pop_back();
        }
        cht.push_back(ln);
    }
 
    inline long long getMin(long long x) {
        if (cht.empty()) {
            return INF;
        }

        int l = -1;
        int r = (int) cht.size() - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            Line a = cht[mid];
            Line b = cht[mid + 1];
            assert(a.k > b.k);
            if (b.b - a.b <= x * (a.k - b.k)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return cht[r].getVal(x);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> d(n - 1);
    for (auto &x : d) {
        cin >> x;
    }

    vector<int> pref(n, 0);
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + d[i - 1];
    }

    vector<int> times;
    for (int i = 0; i < m; i++) {
        int h, t;
        cin >> h >> t;
        h--;
        t -= pref[h];
        times.push_back(t);
    }
    sort(times.begin(), times.end());

    vector<long long> dp(m);
    long long sum = 0;
    for (int i = 0; i < m; i++) {
        sum += times[i];
        dp[i] = (long long) (i + 1) * times[i] - sum;
    }

    long long ans = dp.back();
    for (int num = 1; num < k; num++) {
        Cht cht;
        vector<long long> nDp(m);

        long long sum = 0;
        for (int i = 0; i < m; i++) {
            sum += times[i];
            if (i >= num) {
                nDp[i] = min(INF, cht.getMin(times[i]) + (long long) i * times[i] - sum);
            } else {
                nDp[i] = INF;
            }

            if (i != m - 1 && dp[i] != INF) {
                cht.addLine(-i, dp[i] + sum);
            }
        }

        dp = nDp;
        ans = min(ans, dp.back());
    }

    cout << ans << '\n';
}