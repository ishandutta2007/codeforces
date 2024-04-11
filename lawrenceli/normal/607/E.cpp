#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ios>
#include <vector>
#include <iomanip>
#include <set>

using namespace std;

#define A first
#define B second

typedef long double ld;
typedef long long ll;
typedef pair<ld, ld> pnt;
typedef pair<pnt, int> data;
typedef pair<int, int> pii;

const int maxn = 50100;
const ld eps = 1e-10;

int n, m;
ld X, Y, a[maxn], b[maxn];
data ar[2 * maxn]; int sze;

bool cmp(data d1, data d2) {
    ld x1 = d1.A.A - X, y1 = d1.A.B - Y;
    ld x2 = d2.A.A - X, y2 = d2.A.B - Y;
    if (x1 * x2 < 0) return x1 < x2;
    if (x1 < 0) x1 *= -1, y1 *= -1;
    if (x2 < 0) x2 *= -1, y2 *= -1;
    return y1 * x2 < y2 * x1;
}

int bit[2 * maxn];

void upd(int i, int v) {
    for (i++; i < 2 * maxn; i += i & -i) bit[i] += v;
}

int qry(int i) {
    int ret = 0;
    for (i++; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}

int ind[maxn];

ll check(ld d) {
    sze = 0;
    for (int i = 0; i < n; i++) {
        ld a1 = 1 + a[i] * a[i];
        ld b1 = -2 * (X + a[i] * (Y - b[i]));
        ld c1 = X * X + (Y - b[i]) * (Y - b[i]) - d * d;
        ld d1 = b1 * b1 - 4 * a1 * c1;
        if (d1 < 0) continue;
        ld x1 = (-b1 + sqrt(d1)) / (2 * a1);
        ld x2 = (-b1 - sqrt(d1)) / (2 * a1);
        ld y1 = a[i] * x1 + b[i];
        ld y2 = a[i] * x2 + b[i];
        ar[sze++] = data(pnt(x1, y1), i);
        ar[sze++] = data(pnt(x2, y2), i);
    }

    sort(ar, ar + sze, cmp);
    memset(ind, -1, sizeof(ind));
    memset(bit, 0, sizeof(bit));

    ll ret = 0;
    for (int i = 0; i < sze; i++) {
        int k = ar[i].B;
        if (ind[k] == -1) {
            ind[k] = i;
            upd(i, 1);
        } else {
            ret += qry(i) - qry(ind[k]);
            upd(ind[k], -1);
        }
    }

    return ret;
}

ld dist(ld x, ld y) { return sqrt(x * x + y * y); }

ld go(ld d) {
    sze = 0;
    for (int i = 0; i < n; i++) {
        ld a1 = 1 + a[i] * a[i];
        ld b1 = -2 * (X + a[i] * (Y - b[i]));
        ld c1 = X * X + (Y - b[i]) * (Y - b[i]) - d * d;
        ld d1 = b1 * b1 - 4 * a1 * c1;
        if (d1 < 0) continue;
        ld x1 = (-b1 + sqrt(d1)) / (2 * a1);
        ld x2 = (-b1 - sqrt(d1)) / (2 * a1);
        ld y1 = a[i] * x1 + b[i];
        ld y2 = a[i] * x2 + b[i];
        ar[sze++] = data(pnt(x1, y1), i);
        ar[sze++] = data(pnt(x2, y2), i);
    }

    sort(ar, ar + sze, cmp);
    memset(ind, -1, sizeof(ind));

    ld ret = 0;
    int cnt = 0;
    set<pii> st;
    for (int i = 0; i < sze; i++) {
        int k = ar[i].B;
        if (ind[k] == -1) {
            ind[k] = i;
            st.insert(pii(i, k));
        } else {
            auto it = st.upper_bound(pii(ind[k], k));
            while (it != st.end()) {
                ld x1 = (b[it -> B] - b[k]) / (a[k] - a[it -> B]);
                ld y1 = a[k] * x1 + b[k];
                ret += dist(x1 - X, y1 - Y);
                cnt++;
                it++;
            }
            st.erase(pii(ind[k], k));
        }
    }

    ret += ld(m - cnt) * d;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> X >> Y >> m;
    X /= 1000, Y /= 1000;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i] /= 1000, b[i] /= 1000;
    }

    ld lo = eps, hi = 1e10;
    while (hi - lo > 2 * eps) {
        ld mid = (lo + hi) / 2;
        if (check(mid) >= m) hi = mid;
        else lo = mid + eps;
    }

    cout << fixed << setprecision(10) << go(lo - eps) << '\n';
}