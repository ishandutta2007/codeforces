#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct pt {
    int x, y, c;

    friend istream &operator>>(istream &is, pt &p) {
        is >> p.x >> p.y >> p.c;
        return is;
    }
};

#define OK {l = m;continue;}

bool checkVer(const vector<pt> &pts, int k, int a, int b, int c) {
    int maxA = -1e9, cntA = 0;
    for (int i = 0; i < pts.size(); ++i) {
        if (pts[i].c == a) cntA++;
        if (cntA == k) {
            maxA = pts[i].x;
            break;
        }
        if (i + 1 == pts.size()) return false;
    }
    int minC = 1e9, cntC = 0;
    for (int i = pts.size() - 1; i >= 0; --i) {
        if (pts[i].c == c) cntC++;
        if (cntC == k) {
            minC = pts[i].x;
            break;
        }
        if (i == 0) return false;
    }
    int count = 0;
    for (auto p: pts) if (p.x > maxA && p.x < minC && p.c == b) count++;
    return count >= k;
}

bool checkT(const vector<pt> &pts, int k, int a, int b, int c) {
    int maxA = -1e9, cntA = 0;
    vector<pt> rem;
    for (int i = 0; i < pts.size(); ++i) {
        if (pts[i].c == a) cntA++;
        if (cntA == k) {
            maxA = pts[i].x;
            if (pts.size() - i - 1 < 2 * k) return false;
            for (int j = i + 1; j < pts.size(); ++j) if (pts[j].x > maxA) rem.push_back(pts[j]);
            break;
        }
        if (i + 1 == pts.size()) return false;
    }
    sort(rem.begin(), rem.end(), [](auto p, auto q) { return p.y < q.y; });
    int minC = 1e9, cntC = 0;
    for (int i = rem.size() - 1; i >= 0; --i) {
        if (rem[i].c == c && rem[i].x > maxA) cntC++;
        if (cntC == k) {
            minC = rem[i].y;
            break;
        }
        if (i == 0) return false;
    }
    int count = 0;
    for (auto p: rem) if (p.x > maxA && p.y < minC && p.c == b) count++;
    return count >= k;
}

void solve() {
    int n;
    cin >> n;
    vector<pt> pts(n);
    for (auto &p: pts) cin >> p;
    int l = 0, r = n / 3 + 1;
    sort(pts.begin(), pts.end(), [](auto p, auto q) { return p.x < q.x; });
    vector<pt> copy = pts;
    for (auto &[x, y, c]: pts) swap(x, y);
    sort(pts.begin(), pts.end(), [](auto p, auto q) { return p.x < q.x; });
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (checkVer(pts, m, 1, 2, 3)) OK
        if (checkVer(pts, m, 1, 3, 2)) OK
        if (checkVer(pts, m, 2, 1, 3)) OK
        if (checkVer(pts, m, 2, 3, 1)) OK
        if (checkVer(pts, m, 3, 1, 2)) OK
        if (checkVer(pts, m, 3, 2, 1)) OK

        if (checkVer(copy, m, 1, 2, 3)) OK
        if (checkVer(copy, m, 1, 3, 2)) OK
        if (checkVer(copy, m, 2, 1, 3)) OK
        if (checkVer(copy, m, 2, 3, 1)) OK
        if (checkVer(copy, m, 3, 1, 2)) OK
        if (checkVer(copy, m, 3, 2, 1)) OK

        if (checkT(pts, m, 1, 2, 3)) OK
        if (checkT(pts, m, 1, 3, 2)) OK
        if (checkT(pts, m, 2, 1, 3)) OK
        if (checkT(pts, m, 2, 3, 1)) OK
        if (checkT(pts, m, 3, 1, 2)) OK
        if (checkT(pts, m, 3, 2, 1)) OK
        for (auto &[x, y, c]: pts) x = -x;
        reverse(pts.begin(), pts.end());
        if (checkT(pts, m, 1, 2, 3)) OK
        if (checkT(pts, m, 1, 3, 2)) OK
        if (checkT(pts, m, 2, 1, 3)) OK
        if (checkT(pts, m, 2, 3, 1)) OK
        if (checkT(pts, m, 3, 1, 2)) OK
        if (checkT(pts, m, 3, 2, 1)) OK

        if (checkT(copy, m, 1, 2, 3)) OK
        if (checkT(copy, m, 1, 3, 2)) OK
        if (checkT(copy, m, 2, 1, 3)) OK
        if (checkT(copy, m, 2, 3, 1)) OK
        if (checkT(copy, m, 3, 1, 2)) OK
        if (checkT(copy, m, 3, 2, 1)) OK
        for (auto &[x, y, c]: copy) x = -x;
        reverse(copy.begin(), copy.end());
        if (checkT(copy, m, 1, 2, 3)) OK
        if (checkT(copy, m, 1, 3, 2)) OK
        if (checkT(copy, m, 2, 1, 3)) OK
        if (checkT(copy, m, 2, 3, 1)) OK
        if (checkT(copy, m, 3, 1, 2)) OK
        if (checkT(copy, m, 3, 2, 1)) OK
        r = m;
    }
    cout << 3 * l << '\n';
}