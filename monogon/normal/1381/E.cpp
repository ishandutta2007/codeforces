
#include <bits/stdc++.h>
using namespace std;

// pro-tip: use complex<double> if you're really lazy
// and don't like typing a custom point struct

#define pt complex<double>
#define x real()
#define y imag()

const int N = 1e5 + 5;
int n, q;
double f[N], ans[N];
pt p[N];

// list of events (x coordinate, query index if applicable, A, B)
// where we should answer at this x if a query, or
// we should integrate the line Ax+B starting at x coordinate if not query
// to integrate on interval, we integrate its negation
// starting at the right endpoint of the interval.
vector<tuple<double, int, double, double>> ve;

void add_segment(const pt &p, const pt &q, int k) {
    // vertical line has no effect on the area.
    if(abs(q.x - p.x) < 1e-10) return;
    if(p.x > q.x) return add_segment(q, p, -k);
    double A = (q.y - p.y) / (q.x - p.x);
    double B = p.y - p.x * A;
    ve.emplace_back(p.x, 0, k * A, k * B);
    ve.emplace_back(q.x, 0, -k * A, -k * B);
}

// point on line segment AB with the same y coordinate as p
pt proj(pt a, pt b, pt p) {
    return {(b.x - a.x) * (p.y - a.y) / (b.y - a.y) + a.x, p.y};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    // j = index of point with minimum y coordinate
    // L, R = two pointers that we use to scan polygon vertically,
    // drawing the midpoint lines
    int j = 0, X, Y, L = 0, R = 0, idx;
    double area = 0, a = 0, b = 0, pos, A, B;
    for(int i = 0; i < n; i++) {
        cin >> X >> Y;
        p[i] = pt(X, Y);
        if(p[i].y < p[j].y) j = i;
    }
    for(int i = 1; i <= q; i++) {
        cin >> f[i];
        ve.emplace_back(f[i], i, -1, -1);
    }
    // compute total area of polygon
    for(int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (conj(p[i]) * p[j]).y;
        if(p[i].y > p[j].y) add_segment(p[i], p[j], 1);
        else add_segment(p[j], p[i], 1);
    }
    area = abs(0.5 * area);
    rotate(p, p + j, p + n);
    pt mid = p[0], mid2;
    for(int i = 0; i < n - 1; i++) {
        int L2 = L + 1;
        int R2 = (R + n - 1) % n;
        if(p[L2].y < p[R2].y) {
            mid2 = (p[L2] + proj(p[R], p[R2], p[L2])) * 0.5;
            L = L2;
        }else {
            mid2 = (p[R2] + proj(p[L], p[L2], p[R2])) * 0.5;
            R = R2;
        }
        add_segment(mid, mid2, 2);
        mid = mid2;
    }
    sort(ve.begin(), ve.end());
    for(auto &e : ve) {
        tie(pos, idx, A, B) = e;
        if(idx > 0) {
            ans[idx] = area + (0.5 * a * pos * pos + b * pos);
        }else {
            area -= (0.5 * A * pos * pos + B * pos);
            a += A, b += B;
        }
    }
    cout << fixed << setprecision(6);
    for(int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}