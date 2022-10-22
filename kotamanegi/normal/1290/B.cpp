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
int counter[26][400000];
void solve() {
    string s;
    cin >> s;
    //something
    for (int i = 0; i < s.length(); ++i) {
        REP(t, 26) {
            counter[t][i + 1] += counter[t][i];
            if (s[i] == t + 'a') {
                counter[t][i + 1]++;
            }
        }
    }
    //query
    int query;
    cin >> query;
    REP(tea, query) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == r) {
            cout << "Yes" << endl;
            continue;
        }
        r++;
        int now_max = 0;
        int now_itr = 0;
        int type = 0;
        REP(q, 26) {
            int hoge = counter[q][r] - counter[q][l];
            if (now_max < hoge) {
                now_max = max(now_max, hoge);
                now_itr = q;
            }
            if (hoge != 0) {
                type++;
            }
        }
        if (type == 1) {
            cout << "No" << endl;
            continue;
        }
        if (type >= 3) {
            cout << "Yes" << endl;
            continue;
        }
            if (s[l] != s[r - 1]) {
                cout << "Yes" << endl;
                continue;
            }
        cout << "No" << endl;
        continue;
    }
}
#undef int
int main() {
    init();
    solve();
}