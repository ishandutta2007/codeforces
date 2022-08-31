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
ll a[410000];
ll dp1[410000];
ll dp0[410000];
ll ans[410000];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", a + i);
    for (int i = 1; i < n - 1; ++i)
        dp1[i] = min(a[i], max(a[i - 1], a[i + 1]));
    for (int i = 0; i < n - 1; ++i)
        dp0[i] = max(a[i], a[i + 1]);
    ll cr1 = 0;
    ll cr0 = 0;
    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            ll mx = 0;
            for (int i = 0; i < n; ++i)
                mx = max(mx, a[i]);
            ans[i] = mx;
        }
        else if ((n - i) % 2 == 0) {
            int x = (n - i - 2) / 2;
            cr0 = max(cr0, dp0[x]);
            cr0 = max(cr0, dp0[n - x - 2]);
            ans[i] = cr0;
        }
        else {
            int x = (n - i - 1) / 2;
            cr1 = max(cr1, dp1[x]);
            cr1 = max(cr1, dp1[n - x - 1]);
            ans[i] = cr1;
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%lld ", ans[i]);
    printf("\n");
    return 0;
}