#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1<<17;
const int INF = 1e9 + 5;

int n, s, l, a[MAXN], dp[MAXN], tree[2*MAXN];

deque<pii> dq_min, dq_max;

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) tree[cur] = dp[lt];
    else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        tree[cur] = min(tree[2*cur], tree[2*cur+1]);
    }
}

void update(int cur, int lt, int rt, int p, int v) {
    if (lt + 1 == rt) tree[cur] = v;
    else {
        int mid = (lt + rt) / 2;
        if (p < mid) update(2*cur, lt, mid, p, v);
        else update(2*cur+1, mid, rt, p, v);
        tree[cur] = min(tree[2*cur], tree[2*cur+1]);
    }
}

int query(int cur, int lt, int rt, int ql, int qr) {
    if (rt <= ql || lt >= qr) return INF;
    if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return min(query(2*cur, lt, mid, ql, qr),
                   query(2*cur+1, mid, rt, ql, qr));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> s >> l;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        dp[i] = INF;
    }

    dp[0] = 0;
    dq_min.push_back(pii(0, INF));
    dq_max.push_back(pii(0, -INF));

    init(1, 0, n+1);

    int p = 0;
    for (int i=1; i<=n; i++) {
        while (!dq_min.empty() && dq_min.back().second >= a[i]) dq_min.pop_back();
        dq_min.push_back(pii(i, a[i]));
        while (!dq_max.empty() && dq_max.back().second <= a[i]) dq_max.pop_back();
        dq_max.push_back(pii(i, a[i]));

        while (dq_max[0].second-dq_min[0].second > s) {
            if (dq_min[0].first == p) dq_min.pop_front();
            if (dq_max[0].first == p) dq_max.pop_front();
            p++;
        }

        int lt = p-1, rt = i-l+1;
        if (lt < rt)
            dp[i] = query(1, 0, n+1, lt, rt)+1;
        else dp[i] = INF;
        update(1, 0, n+1, i, dp[i]);
    }

    if (dp[n] >= INF) cout << "-1\n";
    else cout << dp[n] << '\n';
    return 0;
}