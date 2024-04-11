#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int X = 1e6 + 123;

struct pt {
    int x, y;
};

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;

    vector<pt> a(n), b(m), c;

    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    for (int i = 0; i < m; i++)
        cin >> b[i].x >> b[i].y;

    sort(b.begin(), b.end(), [&](const pt& p1, const pt& p2) {
        return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
    });

    for (auto p : b) {
        while (!c.empty() && c.back().x <= p.x && c.back().y <= p.y) {
            c.pop_back();
        }
        c.push_back(p);
    }
    reverse(c.begin(), c.end());
    m = (int) c.size();

    vector<int> f(X + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int lx = (j + 1 < m ? c[j + 1].x + 1 : 0);
            int rx = c[j].x;
            lx -= a[i].x;
            rx -= a[i].x;
            lx = max(0, lx);
            rx = min(rx, X);
            if (rx >= 0)
                f[rx] = max(f[rx], max(0, c[j].y + 1 - a[i].y));
        }
    }

    for (int x = X; x > 0; x--)
        f[x - 1] = max(f[x - 1], f[x]);

    int res = inf;
    for (int x = 0; x <= X; x++)
        res = min(res, x + f[x]);

    cout << res << "\n";

    return 0;
}