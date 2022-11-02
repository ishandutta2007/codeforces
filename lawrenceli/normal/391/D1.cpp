#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <ios>

using namespace std;

const int MAXN = 50100;
const int INF = 1e8;

int n, m;
struct line {
    int x, y, l;
    line() {}
    line(int _x, int _y, int _l) : x(_x), y(_y), l(_l) {}
    bool operator<(const line& _l) const {
        return x != _l.x ? x < _l.x :
               y != _l.y ? y < _l.y :
               l < _l.l;
    }
} ver[MAXN], hor[MAXN];

struct cmp1 {
    bool operator()(const line& l1, const line& l2) const {
        return l1.x != l2.x ? l1.x < l2.x : l1 < l2;
    }
};

struct cmp2 {
    bool operator()(const line& l1, const line& l2) const {
        return l1.x + l1.l != l2.x + l2.l ? l1.x + l1.l < l2.x + l2.l : l1 < l2;
    }
};

set<line, cmp2> st;
multiset<int> st2;

bool check(int mid) {
    int pnt = 0;
    st.clear();
    st2.clear();
    for (int i=0; i<n; i++) {
        line l = ver[i];
        while (pnt < m && hor[pnt].x <= l.x - mid) {
            st.insert(hor[pnt]);
            st2.insert(hor[pnt].y);
            pnt++;
        }
        while (!st.empty() && st.begin()->x + st.begin()->l < l.x + mid) {
            st2.erase(st2.find(st.begin()->y));
            st.erase(st.begin());
        }
        typeof(st2.begin()) it = st2.lower_bound(l.y + mid);
        if (it != st2.end() && *it <= l.y + l.l - mid) return 1;
    }
    return 0;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> ver[i].x >> ver[i].y >> ver[i].l;
    for (int i=0; i<m; i++) cin >> hor[i].x >> hor[i].y >> hor[i].l;

    sort(ver, ver + n, cmp1());
    sort(hor, hor + m, cmp1());

    int lo = 0, hi = INF;

    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }

    cout << lo << '\n';
    return 0;
}