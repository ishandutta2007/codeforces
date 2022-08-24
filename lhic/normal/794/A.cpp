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

ll a, b, c;
int n;
int main() {
    scanf("%lld%lld%lld", &a, &b, &c);
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lld", &x);
        if (x > b && x < c) {
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}