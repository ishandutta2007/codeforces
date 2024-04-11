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
int color[300000];
vector<int> vertexs[300000];
int val[300000];
int dfs(int now, int back) {
    val[now] += color[now];
    for (auto x : vertexs[now]) {
        if (x == back) continue;
        int hoge = dfs(x, now);
        if (hoge >= 0) {
            val[now] += hoge;
        }
    }
    return val[now];
}

int ans[300000];
void sol_dfs(int now, int back,int back_win) {
    ans[now] = back_win + val[now];
    back_win += color[now];
    vector<pair<int, int>> inputs;
    for (auto x : vertexs[now]) {
        if (x == back) continue;
        inputs.push_back(mp(val[x], x));
    }
    int hoge = 0;
    REP(i, inputs.size()) {
        hoge += max(0LL, inputs[i].first);
    }
    REP(i, inputs.size()) {
        int now_val = back_win + hoge;
        if (inputs[i].first >= 0) {
            now_val -= inputs[i].first;
        }
        sol_dfs(inputs[i].second, now, max(now_val, 0LL));
    }
}

void solve() {
    int n;
    cin >> n;
    REP(i, n) {
        cin >> color[i];
        if (color[i] == 0) {
            color[i] = -1;
        }
    }
    REP(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        vertexs[a].push_back(b);
        vertexs[b].push_back(a);
    }
    dfs(0, -1);
    sol_dfs(0, -1, 0);
    REP(i, n) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
#undef int
int main() {
    init();
    solve();
}