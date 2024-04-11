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
int n, t, k, d;

int main() {
    cin >> n >> t >> k >> d;
    int t1 = t * ((n + k - 1) / k);
    int t2 = t1 - 1;
    int cnt = 0;
    cnt += k * (t2 / t);
    if (d < t2)
        cnt += k * ((t2 - d) / t);
    if (cnt >= n)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}