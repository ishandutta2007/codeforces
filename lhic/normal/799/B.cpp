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

int go[10];
int en[210000];
int p[210000];
int a[210000];
int b[210000];
int n, m;
vector<tuple<int, int, int> > vv;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", p + i);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < n; ++i)
        scanf("%d", b + i);
    for (int i = 0; i < n; ++i)
        vv.push_back(make_tuple(p[i], a[i], b[i]));
    sort(vv.begin(), vv.end());
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int c;
        scanf("%d", &c);
        int ans = -1;
        while (go[c] != n) {
            if (en[go[c]]) {
                ++go[c];
                continue;
            }
            if (get<1>(vv[go[c]]) != c && get<2>(vv[go[c]]) != c) {
                ++go[c];
                continue;
            }
            en[go[c]] = 1;
            ans = get<0>(vv[go[c]]);
            ++go[c];
            break;
        }
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}