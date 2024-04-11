#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct pos {
    ll a, b;
    ll gcd(ll a, ll b) { return a? gcd(b % a, a): b; }
    pos(ll ga = 0, ll gb = 1) {
        a = ga; b = gb;
        ll g = gcd(a, b);
        a /= g; b /= g;
    }
    bool operator<(const pos &oth) const {
        return a * oth.b < oth.a * b;
    }
    bool operator==(const pos &oth) const {
        return a * oth.b == oth.a * b;
    }
};

int T;
int h, c, t;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &h, &c, &t);
        pos best = pos(abs(2 * t - (h + c)), 2);
        ll res = 2;
        ll lef = 1, rig = 2000000ll;
        while (lef <= rig) {
            ll mid = lef + rig >> 1ll;
            ll my = 2 * mid - 1ll;
            ll got = (my + 1) * h + (my - 1) * c - 2 * my * t;
            if (got > 0) {
                pos cand = pos(got, 2 * my);
                if (cand < best || cand == best && my < res) {
                    best = cand; res = my;
                }
                lef = mid + 1ll;
            } else {
                pos cand = pos(-got, 2 * my);
                if (cand < best || cand == best && my < res) {
                    best = cand; res = my;
                }
                rig = mid - 1ll;
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}