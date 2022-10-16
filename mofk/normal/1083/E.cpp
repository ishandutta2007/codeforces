#include <bits/stdc++.h>

using namespace std;

const double INF = 1e18;
const long long LINF = 1e18;
const int MAXN = 1e6 + 6;

struct Hull {
    long long a[MAXN], b[MAXN];
    double x[MAXN];
    int head, tail;

    Hull(): head(1), tail(0) {}

    long long get(long long xQuery) {
        if (head > tail) return 0;
        while (head < tail && x[head + 1] <= xQuery) head++;
        x[head] = xQuery;
        return a[head] * xQuery + b[head];
    }

    void add(long long aNew, long long bNew) {
        double xNew = 0;
        while (head <= tail) {
            if (aNew == a[tail]) return;
            xNew = 1.0 * (b[tail] - bNew) / (aNew - a[tail]);
            if (head == tail || xNew >= x[tail]) break;
            tail--;
        }
        a[++tail] = aNew;
        b[tail] = bNew;
        x[tail] = xNew;
    }
};

struct rect {
    long long x, y, cost;
    rect() { x = y = cost = 0; }
    bool operator < (const rect &a) const {
        return x < a.x;
    }
};

Hull hull;

int n;
rect a[1000006];
long long ans;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y >> a[i].cost;
    sort(a + 1, a + n + 1);
    hull.add(0, 0);
    for (int i = 1; i <= n; ++i) {
        long long f = a[i].x * a[i].y - a[i].cost - hull.get(-a[i].y);
        ans = max(ans, f);
        hull.add(-a[i].x, -f);
    }
    cout << ans << endl;
    return 0;
}