#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define dwn(i, n) for (int i=(n); --i>=0; )
#define repr(i, l, r) for (int i=(l), _##i=(r); i<_##i; ++i)
#define dwnr(i, l, r) for (int i=(r), _##i=(l); --i>=_##i; )
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define dwni(i, n) for (__typeof((n).rbegin()) i=(n).rbegin(), _##i=(n).rend(); i!=_##i; ++i)
#define repv(i, n) for (int i=0, _##i=((n).size()); i<_##i; ++i)
#define dwnv(i, n) for (int i=((n).size()); --i>=0; )
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;
typedef vector<int> vi;

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <class T> void setmin(T& a, T b) { if (b < a) a = b; }
template <class T> void setmax(T& a, T b) { if (b > a) a = b; }

const int MAXN = 1<<17;

int n, m;
struct data {
    int x, l, r;
    data() {}
    data(int _x, int _l, int _r) : x(_x), l(_l), r(_r) {}
    bool operator<(const data& d) const {
        return l < d.l;
    }
};
set<data> st;

ll tree[2*MAXN], lazy[2*MAXN];

void down(int cur, int lt, int rt) {
    if (lazy[cur]) {
        tree[cur] += lazy[cur]*(rt-lt);
        if (lt + 1 != rt)
            lazy[2*cur] += lazy[cur], lazy[2*cur+1] += lazy[cur];
        lazy[cur] = 0;
    }
}

void update(int cur, int lt, int rt, int ql, int qr, ll v) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    if (lt >= ql && rt <= qr) {
        lazy[cur] = v;
        down(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        update(2*cur, lt, mid, ql, qr, v);
        update(2*cur+1, mid, rt, ql, qr, v);
        tree[cur] = tree[2*cur] + tree[2*cur+1];
    }
}

ll query(int cur, int lt, int rt, int ql, int qr) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return 0;
    if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return query(2*cur, lt, mid, ql, qr)+query(2*cur+1, mid, rt, ql, qr);
    }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++)
        st.insert(data(i+1, i, i+1));
    for (int i=0; i<m; i++) {
        int type, l, r;
        scanf("%d %d %d", &type, &l, &r);
        l--;
        if (type == 1) {
            int x; scanf("%d", &x);
            typeof(st.begin()) it;
            data d = data(x, l, r);
            it = st.upper_bound(d); it--;
            if (it->l < l && it->r > l) {
                data e = *it;
                if (it->r <= r) {
                    update(1, 0, n, l, e.r, abs(e.x-x));
                    st.erase(it);
                    st.insert(data(e.x, e.l, l));
                } else {
                    update(1, 0, n, l, r, abs(e.x-x));
                    st.erase(it);
                    st.insert(data(e.x, e.l, l));
                    st.insert(data(e.x, r, e.r));
                }
            }
            it = st.lower_bound(data(0, r, 0)); it--;
            if (r < it->r) {
                data e = *it;
                update(1, 0, n, e.l, r, abs(e.x-x));
                st.erase(it);
                st.insert(data(e.x, r, e.r));
            }
            while (1) {
                it = st.lower_bound(d);
                if (it == st.end() || it->l >= r) break;
                //cout << it->l << ' ' << it->r << ' ' << abs(it->x-x) <<  endl;
                update(1, 0, n, it->l, it->r, abs(it->x-x));
                st.erase(it);
            }
            st.insert(d);
            /*
            for (typeof(st.begin()) it2=st.begin(); it2 != st.end(); it2++) {
                typeof(st.begin()) it3 = it2; it3++;
                if (it3 == st.end()) break;
                if (it2->r != it3->l) cout << it2->r << ' ' << it3->l << endl;
            }
            */
        } else {
            printf("%I64d\n", query(1, 0, n, l, r));
        }
    }
    return 0;
}