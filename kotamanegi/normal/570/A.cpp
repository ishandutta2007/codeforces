#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(100);
}
#define int ll
void solve(){
    int cnt[300] = {};
    int  cnter[300][300] = {};
    int n, m;
    cin >> n >> m;
    REP(i, m) {
        REP(q, n) {
            cin >> cnter[q+1][i+1];
        }
    }
    for (int i = 1; i <= m; ++i) {
        int itr = 1;
        for (int q = 1; q <= n; ++q) {
            if (cnter[q][i] > cnter[itr][i]) {
                itr = q;
            }
        }
        if (itr != -1) {
            cnt[itr]++;
        }
    }
    int ans = 1;
    REP(i, n) {
        if (cnt[i + 1] > cnt[ans]) {
            ans = i + 1;
        }
    }
    cout << ans << endl;
}
#undef int
int main() {
    init();
    solve();
}