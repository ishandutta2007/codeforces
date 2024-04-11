#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 100100;
const int INF = 1e9;

int n, v;
ll x[MAXN], t[MAXN];
pll ar[MAXN];
int bit[MAXN], ans;
map<ll, int> mpx, mpy;
int cntx, cnty;

int query(int i) {
    int ret = -INF;
    for (i++; i>0; i-=i&-i) ret = max(ret, bit[i]);
    return ret;
}

void update(int i, int v) {
    for (i++; i<MAXN; i+=i&-i) bit[i] = max(bit[i], v);
}

void go1() {
    for (int i=0; i<MAXN; i++) bit[i] = -INF;
    update(mpy[0], 0);
    for (int i=0; i<n; i++) {
        if (ar[i].fi < mpx[0]) continue;
        int res = query(ar[i].se)+1;
        //cout << i << ' ' << res << endl;
        update(ar[i].se, res);
        ans = max(ans, res);
    }
    cout << ans << ' ';
}

void go2() {
    ans = 0;
    for (int i=0; i<MAXN; i++) bit[i] = 0;
    for (int i=0; i<n; i++) {
        int res = query(ar[i].se)+1;
        //cout << i << ' ' << res << endl;
        update(ar[i].se, res);
        ans = max(ans, res);
    }
    cout << ans << '\n';
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> x[i] >> t[i];
    cin >> v;
    for (int i=0; i<n; i++) {
        t[i] *= v;
        ar[i] = pll(x[i]+t[i], -x[i]+t[i]);
        mpx[ar[i].fi] = 0;
        mpy[ar[i].se] = 0;
    }
    mpx[0] = 0, mpy[0] = 0;
    sort(ar, ar+n);

    for (typeof(mpx.begin()) it=mpx.begin(); it!=mpx.end(); it++)
        mpx[it->fi] = cntx++;
    for (typeof(mpy.begin()) it=mpy.begin(); it!=mpy.end(); it++)
        mpy[it->fi] = cnty++;
    for (int i=0; i<n; i++) ar[i].fi = mpx[ar[i].fi], ar[i].se = mpy[ar[i].se];
    //for (int i=0; i<n; i++) cout << ar[i].fi << ' ' << ar[i].se << endl;
    //cout << mpx[0] << ' ' << mpy[0] << endl;

    go1();
    go2();
    return 0;
}