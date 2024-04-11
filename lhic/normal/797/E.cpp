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
const int SQ = 300;

int n, q;
int ans[101000][SQ];
int a[120000];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j < SQ; ++j) {
            if (i + a[i] + j >= n)
                ans[i][j] = 1;
            else
                ans[i][j] = 1 + ans[i + a[i] + j][j];
        }
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int p, k;
        cin >> p >> k;
        --p;
        int aa = 0;
        if (k >= SQ) {
            while (p < n)
                p = p + a[p] + k, ++aa;
        }
        else {
            aa = ans[p][k];
        }
        cout << aa << "\n";
    }
    return 0;
}