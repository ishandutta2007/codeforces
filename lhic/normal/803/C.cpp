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

ll n, k;

void check(ll x) {
    ll n = ::n / x;
    if (k * (k + 1) / 2 > n)
        return;
    for (ll i = 0; i < k - 1; ++i) {
        cout << (i + 1) * x << " ";
        n -= (i + 1);
    }
    cout << n * x << "\n";
    exit(0);
}

vector<ll> vv;

int main() {
    cin >> n >> k;
    if (k > 1000000) {
        cout << -1 << "\n";
        return 0;
    }
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i != 0)
            continue;
        vv.push_back(i);
        if (i * i != n)
            vv.push_back(n / i);
    }
    sort(vv.begin(), vv.end());
    for (int i = vv.size() - 1; i >= 0; --i) {
        check(vv[i]);
    }
    cout << -1 << "\n";
    return 0;
}