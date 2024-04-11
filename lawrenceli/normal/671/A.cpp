#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ios>
#include <iomanip>

using namespace std;

#define A first
#define B second

typedef long double ld;
typedef pair<int, int> pii;

const int maxn = 100100;

pii a, b, t;
int n;
pii p[maxn], q[maxn];

ld dist(pii p1, pii p2) {
    return sqrt(pow(p1.A - p2.A, 2) + pow(p1.B - p2.B, 2));
}

bool cmp1(pii p1, pii p2) {
    return dist(p1, a) - dist(p1, t) < dist(p2, a) - dist(p2, t);
}

bool cmp2(pii p1, pii p2) {
    return dist(p1, b) - dist(p1, t) < dist(p2, b) - dist(p2, t);
} 

int main() {
    ios_base::sync_with_stdio(0);

    cin >> a.A >> a.B >> b.A >> b.B >> t.A >> t.B;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].A >> p[i].B;
        q[i] = p[i];
    }

    ld ans = 0;
    for (int i = 0; i < n; i++)
        ans += 2 * dist(p[i], t);

    sort(p, p + n, cmp1);
    sort(q, q + n, cmp2);

    ld ans2 = ans + min(dist(p[0], a) - dist(p[0], t), dist(q[0], b) - dist(q[0], t));

    if (p[0] != q[0]) {
        ans += dist(p[0], a) - dist(p[0], t);
        ans += dist(q[0], b) - dist(q[0], t);
    } else {
        ld k;
        if (n > 1) k = min(dist(p[0], a) - dist(p[0], t) + dist(q[1], b) - dist(q[1], t), dist(p[1], a) - dist(p[1], t) + dist(q[0], b) - dist(q[0], t));
        else k = dist(p[0], a) + dist(q[0], b);
        k = min(k, dist(p[0], a) + dist(q[0], b));
        ans += k;
    }

    cout << fixed << setprecision(10) << min(ans, ans2) << '\n';
}