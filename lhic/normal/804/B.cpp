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
const ll MOD = 1e9 + 7;
char s[1200000];

int main() {
    scanf("%s", s);
    ll ans = 0;
    ll now = 1;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a')
            now = (now * 2) % MOD;
        else {
            ans += now - 1;
        }
    }
    if (ans < 0)
        ans += MOD;
    ans %= MOD;
    cout << ans << "\n";
    return 0;
}