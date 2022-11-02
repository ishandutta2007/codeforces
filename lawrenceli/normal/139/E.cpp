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

const int MAXN = 100100;
const int MAXM = 1<<14;

int n, m, a[MAXN], h[MAXN], l[MAXN], r[MAXN];
pii arr[MAXM];

bool cmp1(pii p, int i) {
    return p.fi < i;
}

bool cmp2(int i, pii p) {
    return i < p.fi;
}

double tree[2*MAXM], lazy[2*MAXM];

void init(int cur, int lt, int rt) {
    lazy[cur] = 1;
    if (lt + 1 == rt) tree[cur] = arr[lt].se;
    else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
    }
}

void down(int cur, int lt, int rt) {
    if (lazy[cur] != 1) {
        if (lt + 1 != rt) {
            lazy[2*cur] *= lazy[cur];
            lazy[2*cur+1] *= lazy[cur];
            lazy[cur] = 1;
        } else tree[cur] *= lazy[cur], lazy[cur] = 1;
    }
}

void update(int cur, int lt, int rt, int ql, int qr, double v) {
    down(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        lazy[cur] = v;
        down(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        update(2*cur, lt, mid, ql, qr, v);
        update(2*cur+1, mid, rt, ql, qr, v);
    }
}

double query(int cur, int lt, int rt, int p) {
    down(cur, lt, rt);
    if (lt + 1 == rt) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        if (p < mid) return query(2*cur, lt, mid, p);
        else return query(2*cur+1, mid, rt, p);
    }
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i] >> h[i] >> l[i] >> r[i];
    for (int i=0; i<m; i++) cin >> arr[i].fi >> arr[i].se;
    sort(arr, arr + m);
    init(1, 0, m);
    for (int i=0; i<n; i++) {
        int lt, rt;
        lt = lower_bound(arr, arr + m, a[i] - h[i], cmp1) - arr;
        rt = upper_bound(arr, arr + m, a[i] - 1, cmp2) - arr;
        update(1, 0, m, lt, rt, (100. - l[i]) / 100);
        lt = lower_bound(arr, arr + m, a[i] + 1, cmp1) - arr;
        rt = upper_bound(arr, arr + m, a[i] + h[i], cmp2) - arr;
        update(1, 0, m, lt, rt, (100. - r[i]) / 100);
    }

    double ans = 0;
    for (int i=0; i<m; i++)
        ans += query(1, 0, m, i);

    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}