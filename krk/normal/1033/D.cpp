#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;

map <ll, int> M;
map <ll, int> lft;
int n;
ll a;
int res = 1;

ll Sqrt2(ll x)
{
    ll lef = 1, rig = 2000000000;
    while (lef <= rig) {
        ll mid = lef + rig >> 1ll;
        if (mid * mid <= x) lef = mid + 1;
        else rig = mid - 1;
    }
    lef--;
    if (lef * lef == x) return lef;
    return -1;
}

ll Sqrt3(ll x)
{
    ll lef = 1, rig = 1500000;
    while (lef <= rig) {
        ll mid = lef + rig >> 1ll;
        if (mid * mid * mid <= x) lef = mid + 1;
        else rig = mid - 1;
    }
    lef--;
    if (lef * lef * lef == x) return lef;
    return -1;
}

ll Sqrt4(ll x)
{
    ll lef = 1, rig = 38000;
    while (lef <= rig) {
        ll mid = lef + rig >> 1ll;
        if (mid * mid * mid * mid <= x) lef = mid + 1;
        else rig = mid - 1;
    }
    lef--;
    if (lef * lef * lef * lef == x) return lef;
    return -1;
}

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a);
        ll g = Sqrt4(a);
        if (g >= 0) { M[g] += 4; continue; }
        g = Sqrt3(a);
        if (g >= 0) { M[g] += 3; continue; }
        g = Sqrt2(a);
        if (g >= 0) { M[g] += 2; continue; }
        lft[a]++;
    }
    while (!lft.empty()) {
        pair <ll, int> p = *lft.begin(); lft.erase(lft.begin());
        bool found = false;
        for (map <ll, int>::iterator it = M.begin(); it != M.end() && !found; it++)
            if (p.first % it->first == 0) {
                M[it->first] += p.second; M[p.first / it->first] += p.second;
                found = true;
                break;
            }
        for (map <ll, int>::iterator it = lft.begin(); it != lft.end() && !found; it++) {
            ll g = gcd(p.first, it->first);
            if (g > 1) {
                M[g] += p.second; M[p.first / g] += p.second;
                found = true;
                break;
            }
        }
        if (!found) M[p.first] = (p.second + 1) * (p.second + 1) - 1;
    }
    for (map <ll, int>::iterator it = M.begin(); it != M.end(); it++)
        res = ll(res) * (it->second + 1) % mod;
    printf("%d\n", res); fflush(stdout);
    return 0;
}