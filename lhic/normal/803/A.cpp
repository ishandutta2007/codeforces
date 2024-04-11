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

int n, k;
int a[120][120];

int main() {
    cin >> n >> k;
    if (k > n * n) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (k)
            a[i][i] = 1, --k;
        for (int j = i + 1; j < n; ++j) {
            if (k >= 2)
                k -= 2, a[i][j] = a[j][i] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    return 0;
}