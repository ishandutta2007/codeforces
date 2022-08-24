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
const int MAXN = 120000;
int l[MAXN];
int r[MAXN];
set<int> ss;
int v[MAXN];

void run(int x, int lb, int rb) {
    if (v[x] >= lb && v[x] <= rb)
        ss.insert(v[x]);
    if (l[x] != -1)
        run(l[x], lb, min(rb, v[x] - 1));
    if (r[x] != -1)
        run(r[x], max(lb, v[x] + 1), rb);
}
int n;
int bd[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> l[i] >> r[i];
        if (l[i] > 0)
            --l[i], bd[l[i]] = 1;
        if (r[i] > 0)
            --r[i], bd[r[i]] = 1;
    }
    int rt = -1;
    for (int i = 0; i < n; ++i)
        if (bd[i] == 0)
            rt = i;
    run(rt, 0, 1e9 + 100);
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (!ss.count(v[i]))
            ++ans;
    cout << ans << "\n";
    return 0;
}