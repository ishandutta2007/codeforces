#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXK = 10;
const int MOD = 1e9 + 7;

int n, k, p[MAXK];
bool cyc[MAXK], good[MAXK], bad;
ll ans;

void dfs(int cur) {
    if (bad) return;
    cyc[cur] = 1;
    int nxt = p[cur];
    if (good[nxt]) good[cur] = 1;
    else if (cyc[nxt]) bad = 1;
    else dfs(nxt);
    cyc[cur] = 0;
    good[cur] = 1;
}

void recurse(int cur) {
    if (cur == k) {
        memset(cyc, 0, sizeof(cyc));
        memset(good, 0, sizeof(good));
        bad = 0; good[0] = 1;
        for (int i=0; i<k; i++) {
            if (!good[i]) dfs(i);
            if (bad) return;
        }
        ans ++;
    } else {
        for (int i=0; i<k; i++) {
            p[cur] = i;
            recurse(cur + 1);
        }
    }
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n >> k;

    recurse(0);

    for (int i=0; i<n-k; i++) ans = (ans * (n-k)) % MOD;

    cout << ans << endl;
    return 0;
}