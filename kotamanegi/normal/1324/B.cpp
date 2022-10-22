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

void solve() {
    int n;
    cin >> n;
    vector<int> inputs;
    REP(i, n) {
        int a;
        cin >> a;
        inputs.push_back(a);
    }
    map<int, vector<int>> gogo;
    REP(i, inputs.size()) {
        gogo[inputs[i]].push_back(i);
    }
    for (auto i : gogo) {
        if (i.second.size() > 2) {
            cout << "YES" << endl;
            return;
        }
        if (i.second.size() == 2) {
            if (i.second[0] + 1 != i.second[1]) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
    return;
}
#undef int
int main() {
    init();
    int t;
    cin >> t;
    REP(i,t)
    solve();
}