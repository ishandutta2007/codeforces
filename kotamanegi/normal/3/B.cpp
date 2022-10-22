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
int cost[300000];
void solve(){
    int n, v;
    cin >> n >> v;
    vector<pair<int, int>> inputs[3];
    REP(i, n) {
        int a, b;
        cin >> a >> b;
        inputs[a].push_back(mp(b, i + 1));
    }
    sort(ALL(inputs[1]), greater<pair<int, int>>());
    sort(ALL(inputs[2]), greater<pair<int, int>>());
    int itr0 = 0, itr1 = 0;
    int ans = 0;
    REP(i, inputs[1].size()) {
        cost[i + 1] = cost[i] + inputs[1][i].first;
    }
    int geko = 0;
    ans = cost[min((int)inputs[1].size(), v)];
    itr0 = min((int)inputs[1].size(), v);
    for (int q = 0; q < inputs[2].size()&&(q+1)*2 <= v; ++q) {
        int hoge = v - (q+1) * 2;
        hoge = min(hoge, (long long)inputs[1].size());
        geko += inputs[2][q].first;
        if (ans < cost[hoge]+geko) {
            ans = cost[hoge] + geko;
            itr0 = hoge;
            itr1 = q+1;
        }
    }
    cout << ans << endl;
    REP(i, itr0) {
        cout << inputs[1][i].second << endl;
    }
    REP(i, itr1) {
        cout << inputs[2][i].second << endl;
    }
    return;
}
#undef int
int main() {
    init();
    solve();
}