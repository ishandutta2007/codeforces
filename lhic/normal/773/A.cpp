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


ll solve() {
    ll x, y, p, q;
    cin >> x >> y >> p >> q;
    if (p == q) {
        if (x == y)
            return 0;
        else
            return -1;
    }
    if (p == 0) {
        if (x == 0)
            return 0;
        else
            return -1;
    }
    ll k = max({(y + q - 1) / q, (x + p - 1) / p, (y - x + (q - p - 1)) / (q - p)});
    return q * k - y;
}

int main() {
    int tt;
    cin >> tt;
    for (int i = 0; i < tt; ++i)
        cout << solve() << "\n";
    return 0;
}