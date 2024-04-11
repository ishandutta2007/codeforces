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
int gcd(int a,int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void solve() {
    int a, m;
    cin >> a >> m;
    int hoge = gcd(a, m);
    m /= hoge;
    a /= hoge;
    int ans = 0;
    vector<int> go;
    int now = m;
    for (int q = 2; q * q <= now; ++q) {
        if (now % q == 0) {
            go.push_back(q);
            while (now % q == 0) {
                now /= q;
            }
        }
    }
    if (now != 1) {
        go.push_back(now);
    }
    REP(i, (1 << go.size())) {
        int cnt = 0;
        int val = 1;
        for (int q = 0; q < go.size(); ++q) {
            if (((1 << q) & i) != 0) {
                val *= go[q];
                cnt++;
            }
        }
        int left = (a + val - 1) / val;
        int right = (m + a - 1) / val;
        int tmp = max(0LL, right - left + 1);
        if (cnt % 2 == 0) {
            ans += tmp;
        }
        else {
            ans -= tmp;
        }
    }
    cout << ans << endl;
}
#undef int
int main() {
    init();
    int t;
    cin >> t;
    REP(te,t)
    solve();
}