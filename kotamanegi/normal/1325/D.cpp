#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}


unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

#define int ll
void solve() {
    int u, v;
    cin >> u >> v;
    if (u > v) {
        cout << -1 << endl;
        return;
    }
    if (u == 0 && v == 0) {
        cout << 0 << endl;
        return;
    }
    if (u == v) {
        cout << 1 << endl;
        cout << u << endl;
        return;
    }
    int geko = v - u;
    if (geko % 2 == 1) {
        cout << "-1" << endl;
        return;
    }
    geko /= 2LL;
    if (geko & u) {
        //not zero,need 3
        cout << 3 << endl;
        cout << u << " " << geko << " " << geko << endl;
        return;
    }
    else {
        cout << 2 << endl;
        cout << u + geko << " " << geko << endl;
    }
}

#undef int
int main() {
    init();
    solve();
}