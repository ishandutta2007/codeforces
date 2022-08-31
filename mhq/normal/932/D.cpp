#include <bits/stdc++.h>
using namespace std;
int q;
long long lst;
const int maxN = 5 * (int)1e5;
int cnt = 1;
int prv[maxN];
long long up_max[maxN][22];
int to[maxN][22];
int val[maxN];
int n_prv[maxN];
long long n_up[maxN][22];
int n_to[maxN][22];
void go(int v, int w) {
    int curv = cnt;
    prv[curv] = v;
    up_max[curv][0] = w;
    to[curv][0] = curv;
    val[curv] = w;
    for (int i = 0; i <= 19; i++) {
        if (to[curv][i] == -1) continue;
        int nxt = prv[to[curv][i]];
        if (nxt == -1 || to[nxt][i] == -1) continue;
        up_max[curv][i + 1] = max(up_max[curv][i], up_max[nxt][i]);
        to[curv][i + 1] = to[nxt][i];
    };
    curv = v;
    for (int i = 20; i >= 0; i--) {
        if (curv == -1) continue;
        if (to[curv][i] == -1) continue;
        if (up_max[curv][i] >= w) continue;
        curv = prv[to[curv][i]];
    }
    n_prv[cnt] = curv;
    n_up[cnt][0] = w;
    n_to[cnt][0] = cnt;
    for (int i = 0; i <= 19; i++) {
        if (n_to[cnt][i] == -1) continue;
        int nxt = n_prv[n_to[cnt][i]];
        if (nxt == -1 || n_to[nxt][i] == -1) continue;
        n_up[cnt][i + 1] = n_up[cnt][i] + n_up[nxt][i];
        n_to[cnt][i + 1] = n_to[nxt][i];
    }
}
int ask(int v, long long w) {
    int ans = 0;
    for (int i = 20; i >= 0; i--) {
        if (v == -1) continue;
        if (n_to[v][i] == -1) continue;
        if (n_up[v][i] > w) continue;
        w = w - n_up[v][i];
        v = n_prv[n_to[v][i]];
        ans += (1 << i);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    memset(n_to, -1, sizeof n_to);
    memset(to, -1, sizeof to);
    memset(prv, -1, sizeof prv);
    memset(n_prv, -1, sizeof n_prv);
    val[1] = 0;
    to[1][0] = 1;
    n_to[1][0] = 1;
    n_up[1][0] = 0;
    up_max[1][0] = 0;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int type;
        long long x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            cnt++;
            x = x ^ lst;
            y = y ^ lst;
            go(x, y);
        }
        else {
            x = x ^ lst;
            y = y ^ lst;
            lst = ask(x, y);
            cout << lst << endl;
        }
    }
    //cout << n_prv[2] << endl;
    return 0;
}