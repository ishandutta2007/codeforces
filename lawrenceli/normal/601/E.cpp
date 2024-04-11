#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ios>
#include <vector>

using namespace std;

typedef long long ll;

const int maxn = 1<<15;
const int P = 1e7 + 19;
const int Q = 1e9 + 7;

int n, k, q;
int v[maxn], w[maxn], st[maxn], nd[maxn];
vector<int> qlist[2 * maxn];

void upd(int cur, int lt, int rt, int i) {
    if (rt <= st[i] || lt >= nd[i]) return;
    else if (lt >= st[i] && rt <= nd[i]) qlist[cur].push_back(i);
    else {
        int mid = (lt + rt) / 2;
        upd(2 * cur, lt, mid, i);
        upd(2 * cur + 1, mid, rt, i);
    }
}

int ans[maxn];

void process(int cur, int lt, int rt, vector<int> dp) {
    for (int i : qlist[cur])
        for (int j = k - w[i]; j >= 0; j--)
            dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);

    if (lt + 1 == rt) {
        for (int i = k; i >= 1; i--) {
            ans[lt] = ll(ans[lt]) * P % Q;
            ans[lt] = (ans[lt] + dp[i]) % Q;
        }
    } else {
        int mid = (lt + rt) / 2;
        process(2 * cur, lt, mid, dp);
        process(2 * cur + 1, mid, rt, dp);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i];
    cin >> q;

    memset(nd, -1, sizeof(nd));
    int cnt = 0;
    for (int i = 0; i < q; i++) {
        int qtype; cin >> qtype;
        if (qtype == 1) {
            cin >> v[n] >> w[n];
            st[n] = cnt;
            n++;
        } else if (qtype == 2) {
            int x;
            cin >> x;
            x--;
            nd[x] = cnt;
        } else cnt++;
    }

    for (int i = 0; i < n; i++)
        if (nd[i] == -1) nd[i] = cnt;

    for (int i = 0; i < n; i++)
        upd(1, 0, cnt, i);

    vector<int> dp (k + 1, 0);
    process(1, 0, cnt, dp);

    for (int i = 0; i < cnt; i++)
        cout << ans[i] << '\n';
}