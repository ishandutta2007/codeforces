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

int x, y, z;
int dp[3000][3];
int dfs(int a, int b) {
    if (a <= 0) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    int cnter[5] = {};
    cnter[dfs(a - x, 0)]++;
    if (b != 1) {
        cnter[dfs(a - y, 1)]++;
    }
    if (b != 2) {
        cnter[dfs(a - z, 2)]++;
    }
    REP(i, 100) {
        if (cnter[i] == 0) {
            return dp[a][b] = i;
        }
    }
}

int cnt[4] = {};
int lengthen[4] = {};

int eval(int b,int a) {
    if (a <= 0) return 0;
    if (a <= 1000) return dp[a][b];
    int target = (a - 1000) % lengthen[b];
    return dp[1000 + target][b];
}

void sol(int a) {
    cnt[eval(0,a) ^ eval(0,a - x)]++;
    cnt[eval(0,a) ^ eval(1,a - y)]++;
    cnt[eval(0,a) ^ eval(2,a - z)]++;
    return;
}
void solve() {
    int n;
    vector<int> inputs;
    scanf("%lld%lld%lld%lld", &n, &x, &y, &z);
    REP(i, n) {
        int a;
        cin >> a;
        inputs.push_back(a);
    }
    sort(ALL(inputs));
    REP(i, 3000) {
        REP(q, 3) {
            dp[i][q] = -1;
        }
    }
    REP(q, 4) {
        cnt[q] = 0;
    }
    REP(i, 3000) {
        REP(q, 3) {
            dp[i][q] = dfs(i, q);
        }
    }
    REP(i, 3) {
        for (int len = 500;; ++len) {
            int ok = 1;
            for (int q = 0; q < len; ++q) {
                if (dp[q + 1000][i] != dp[q + 1000 + len][i]) {
                    ok = 0;
                    break;
                }
            }
            if (ok == 0) continue;
            lengthen[i] = len;
            /*
            REP(q, inputs.size()) {
                if (inputs[q] <= 1010) continue;
                for (int j = inputs[q]; j >= inputs[q] - 5; --j) {
                    int target = (j - 1000) % len;
                    REP(t, 3) {
                        calc[t][j] = dp[1000 + target][t];
                    }
                }
            }
            */
            break;
        }
    }
    int now = 0;
    REP(i, n) {
        sol(inputs[i]);
        now ^= eval(0, inputs[i]);
    }
    if (now == 0) {
        printf("0\n");
        return;
    }
    else {
        printf("%lld\n", cnt[now]);
    }
}

#undef int
int main() {
    int t;
    scanf("%d", &t);
    REP(tea,t)
    solve();
}