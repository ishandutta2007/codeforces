#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>
#include <random>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}
typedef unsigned long long ull;
const int MAXN = 210000;

mt19937_64 rnd(123);
ull rn[MAXN];
int cc[MAXN];
ull go[MAXN];
map<ull, int> mmc;
map<ull, ll> mms;
ll ans = 0;

void run(int l, int r, vector<pair<int, int> > vv) {
    sort(vv.begin(), vv.end());
    vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
    if (l + 1 == r) {
        if (vv.size())
            ++ans;
        return;
    }
    int mid = (l + r) >> 1;
    vector<pair<int, int> > vvl;
    vector<pair<int, int> > vvr;
    int lb = l - 1;
    int rb = r + 1;
    for (int i = 0; i < vv.size(); ++i) {
        if (vv[i].first >= mid)
            vvr.push_back(vv[i]), rb = min(rb, vv[i].first);
        else if (vv[i].second < mid)
            vvl.push_back(vv[i]), lb = max(lb, vv[i].second);
        else {
            vvl.push_back(make_pair(vv[i].first, mid - 1));
            vvr.push_back(make_pair(mid, vv[i].second));
            lb = mid - 1;
            rb = mid;
        }
    }
    run(l, mid, vvl);
    run(mid, r, vvr);
    fill(cc + l, cc + r, 0);
    fill(go + l, go + r, 0);
    ull nd = 0;
    for (int i = 0; i < vv.size(); ++i) {
        if (vv[i].first >= mid) {
            if ((vv[i].second - vv[i].first + 1) % 2 == 0) {
                ++cc[vv[i].first + 1];
                ++cc[vv[i].second + 1];
            }
            else {
                ++cc[vv[i].first + 1];
                --cc[vv[i].second + 1];
            }
        }
        else if (vv[i].second < mid) {
            if ((vv[i].second - vv[i].first + 1) % 2 == 0) {
                ++cc[vv[i].second - 1];
                if (vv[i].first > l)
                    ++cc[vv[i].first - 1];
            }
            else {
                if (vv[i].second > l)
                    ++cc[vv[i].second - 1];
                if (vv[i].first > l)
                    --cc[vv[i].first - 1];
            }
        }
        else {
            nd ^= rn[i];
            go[mid - 1] ^= rn[i];
            if (vv[i].first > l)
                go[vv[i].first - 1] ^= rn[i];
            go[mid] ^= rn[i];
            go[vv[i].second + 1] ^= rn[i];
        }
    }
    ull hs = 0;
    int now = 0;
    mmc.clear();
    mms.clear();
    ll c0 = 0;
    ll s0 = 0;
    for (int i = mid - 1; i >= l; i -= 2) {
        now += cc[i];
        hs ^= go[i];
        if (now == 0 && i <= lb)
            ++mmc[hs ^ nd], mms[hs ^ nd] += mid - i;
        else if (now == 0 && i > lb)
            ++c0, s0 += mid - i;
    }
    hs = 0;
    now = 0;
    for (int i = mid - 2; i >= l; i -= 2) {
        now += cc[i];
        hs ^= go[i];
        if (now == 0 && i <= lb)
            ++mmc[hs ^ nd], mms[hs ^ nd] += mid - i;
        else if (now == 0 && i > lb)
            ++c0, s0 += mid - i;
    }
    hs = 0;
    now = 0;
    for (int i = mid; i < r; i += 2) {
        now += cc[i];
        hs ^= go[i];
        if (now == 0) {
            ans += (ll)(i - mid + 1) * mmc[hs] + mms[hs];
            if (i >= rb && hs == nd)
                ans += (ll)(i - mid + 1) * c0 + s0;
        }
    }
    hs = 0;
    now = 0;
    for (int i = mid + 1; i < r; i += 2) {
        now += cc[i];
        hs ^= go[i];
        if (now == 0) {
            ans += (ll)(i - mid + 1) * mmc[hs] + mms[hs];
            if (i >= rb && hs == nd)
                ans += (ll)(i - mid + 1) * c0 + s0;
        }
    }
}
vector<pair<int, int >> vv;
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        rn[i] = rnd();
    vector<pair<int, int> > vv;
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l, --r;
        vv.push_back(make_pair(l, r));
    }
    run(0, m, vv);
    cout << ans << "\n";
    return 0;
}