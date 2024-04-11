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
int a[220000];
int dd[220000];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; ++i)
        dd[i] = n + 1;
    int now = -n - 100;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0)
            now = i;
        dd[i] = min(dd[i], i - now);
    }
    now = n + n + 100;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0)
            now = i;
        dd[i] = min(dd[i], now - i);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", dd[i]);
    }
    printf("\n");
    return 0;
}