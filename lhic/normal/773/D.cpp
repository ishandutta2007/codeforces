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
const ll INF = 1e15;

int n;
ll a[2100][2100];
int fl[2100];
ll dd[2100];
int en[2100];
ll mnn[2100];

int main() {
    scanf("%d", &n);
    ll mn = 1e9 + 100;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            scanf("%lld", &a[i][j]);
            a[j][i] = a[i][j];
            mn = min(mn, a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            if (a[i][j] == mn)
                fl[i] = 1;
        }
    }
    fill(dd, dd + n, INF);
    for (int j = 0; j < n; ++j)
        if (fl[j])
            dd[j] = 0;
    for (int i = 0; i < n; ++i) {
        mnn[i] = 1e9 + 100;
        for (int j = 0; j < n; ++j)
            if (i != j)
                mnn[i] = min(mnn[i], a[i][j] - mn);
        dd[i] = min(dd[i], mnn[i] * 2);
    }
    for (int i = 0; i < n; ++i) {
        int bst = -1;
        for (int j = 0; j < n; ++j)
            if (!en[j] && (bst == -1 || dd[j] < dd[bst]))
                bst = j;
        en[bst] = 1;
        for (int j = 0; j < n; ++j) {
            if (!en[j] && dd[j] > dd[bst] + a[bst][j] - mn)
                dd[j] = dd[bst] + a[bst][j] - mn;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << (n - 1) * mn + dd[i] << "\n";
    }
    return 0;
}