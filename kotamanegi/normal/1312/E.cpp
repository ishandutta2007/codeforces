#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144 * 4LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}


#define int ll

unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

int grid[600][600];
int final_dp[600];

void solve() {
    int n;
    cin >> n;
    vector<int> inputs;
    REP(i, n) {
        int a;
        cin >> a;
        inputs.push_back(a);
    }
    queue<pair<int, int>> next;
    for (int i = 1; i <= 2000; ++i) {
        queue<pair<int, int>> go = next;
        while (next.empty() == false) next.pop();
        REP(q, n) {
            if (inputs[q] == i) {
                grid[q][q] = i;
                go.push(mp(q, q));
            }
        }
        while (go.empty() == false) {
            pair<int, int> now = go.front();
            go.pop();
            //right
            for (int q = now.second + 1; q < n; ++q) {
                if (grid[now.second + 1][q] == i) {
                    //you can fill out!
                    if (grid[now.first][q] == i + 1)continue;
                    grid[now.first][q] = i + 1;
                    next.push(mp(now.first, q));
                }
            }
            for (int q = now.first - 1; q >= 0; --q) {
                if (grid[q][now.first-1] == i) {
                    //you can fill out!
                    if (grid[q][now.second] == i + 1)continue;
                    grid[q][now.second] = i + 1;
                    next.push(mp(q, now.second));
                }
            }
        }
    }
    REP(i, 600) {
        final_dp[i] = 1e9;
    }
    final_dp[0] = 0;
    REP(i, n) {
        for (int q = i; q < n; ++q) {
            if (grid[i][q] != 0) {
                final_dp[q + 1] = min(final_dp[q + 1], final_dp[i] + 1);
            }
        }
    }
    cout << final_dp[n] << endl;
}

#undef int
int main() {
    init();
    solve();
}