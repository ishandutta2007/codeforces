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
void solve() {
    vector<int> gogo[26];
    string s;
    cin >> s;
    string t;
    cin >> t;
    REP(i, s.length()) {
        gogo[s[i] - 'a'].push_back(i);
    }
    int now = 0;
    int ans = 1;
    REP(i, t.length()) {
        int itr = t[i] - 'a';
        if (gogo[itr].size() == 0) {
            cout << -1 << endl;
            return;
        }
        auto x = lower_bound(ALL(gogo[itr]), now);
        if (x == gogo[itr].end()) {
            ans++;
            now = gogo[itr][0] + 1;
        }
        else {
            now = *x + 1;
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