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
vector<int> vertexs[200000];
int ans[200000];
int cnt[200000];
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    REP(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges.push_back(mp(a, b));
        cnt[a]++;
        cnt[b]++;
        ans[i] = -1;
    }
    
    REP(i, n) {
        if (cnt[i] >= 3) {
            int now = 0;
            for (int q = 0; q < edges.size(); ++q) {
                if (edges[q].first == i || edges[q].second == i) {
                    ans[q] = now;
                    now++;
                }
            }
            REP(q, edges.size()) {
                if (ans[q] == -1) {
                    ans[q] = now;
                    now++;
                }
                cout << ans[q] << endl;
            }
            return;
        }
    }
    REP(i, n - 1) {
        cout << i << endl;
    }
}

#undef int
int main() {
    init();
    solve();
}