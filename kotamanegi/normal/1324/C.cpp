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
#define seg_size 262144
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


#define int long long
string s;
int calc(int now) {
    int back = 0;
    for (int q = 1; q <= s.length(); ++q) {
        if (s[q-1] == 'R') {
            back = q;
        }
        if (q - back >= now) return 0;
    }
    if (back + now <= s.length()) return 0;
    return 1;
}
void solve() {
    cin >> s;
    int bot = 1e9;
    int top = 0;
    while (bot - top > 1) {
        int mid = (top + bot) / 2;
        if (calc(mid) == 1) {
            bot = mid;
        }
        else {
            top = mid;
        }
    }
    cout << bot << endl;
}
#undef int
int main() {
    init();
    int t;
    cin >> t;
    REP(i,t)
    solve();
}