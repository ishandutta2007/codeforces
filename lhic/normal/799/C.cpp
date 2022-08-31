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

int n;
ll c, d;
vector<pair<ll, ll> > vv1;
vector<pair<ll, ll> > vv2;

int main() {
    scanf("%d%lld%lld", &n, &c, &d);
    for (int i = 0; i < n; ++i) {
        ll b, cs;
        char t;
        scanf("%lld%lld %c", &b, &cs, &t);
        if (t == 'C') {
            if (cs <= c)
                vv1.push_back(make_pair(cs, b));
        }
        else {
            if (cs <= d)
                vv2.push_back(make_pair(cs, b));
        }
    }
    sort(vv1.begin(), vv1.end());
    sort(vv2.begin(), vv2.end());
    ll ans = 0;
    if (!vv1.empty() && !vv2.empty()) {
        ll mx = 0;
        for (int i = 0; i < vv1.size(); ++i)
            mx = max(mx, vv1[i].second);
        ans = mx;
        mx = 0;
        for (int i = 0; i < vv2.size(); ++i)
            mx = max(mx, vv2[i].second);
        ans += mx;
    }
    if (vv1.size() >= 2) {
        ll mx = vv1[0].second;
        int now = 0;
        for (int i = 1; i < vv1.size(); ++i) {
            mx = max(mx, vv1[i].second);
            while (now + 1 < i && vv1[i].first + vv1[now + 1].first <= c)
                ++now;
            while (now >= 0 && vv1[i].first + vv1[now].first > c)
                --now;
            if (now < 0)
                break;
            ans = max(ans, vv1[i].second + vv1[now].second);
            vv1[i].second = mx;
        }
    }
    if (vv2.size() >= 2) {
        ll mx = vv2[0].second;
        int now = 0;
        for (int i = 1; i < vv2.size(); ++i) {
            mx = max(mx, vv2[i].second);
            while (now + 1 < i && vv2[i].first + vv2[now + 1].first <= d)
                ++now;
            while (now >= 0 && vv2[i].first + vv2[now].first > d)
                --now;
            if (now < 0)
                break;
            ans = max(ans, vv2[i].second + vv2[now].second);
            vv2[i].second = mx;
        }
    }
    cout << ans << "\n";
    return 0;
}