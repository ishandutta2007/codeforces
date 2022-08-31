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
int a[120000];
int cc[120000];
ll pw2[120000];
int mu[120000];
const ll MOD = 1e9 + 7;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        for (int j = 1; j * j <= a[i]; ++j) {
            if (a[i] % j != 0)
                continue;
            ++cc[j];
            if (j * j != a[i])
                ++cc[a[i] / j];
        }
    }
    pw2[0] = 1;
    for (int i = 1; i <= 110000; ++i)
        pw2[i] = (pw2[i - 1] * 2) % MOD;
    ll ans = 0;
    mu[1] = 1;
    for (int i = 1; i <= 110000; ++i) {
        for (int j = i + i; j <= 110000; j += i)
            mu[j] -= mu[i];
        ans += mu[i] * (pw2[cc[i]] - 1);
        if (ans < 0)
            ans += MOD;
        if (ans >= MOD)
            ans -= MOD;
    }
    cout << ans << "\n";
    return 0;
}