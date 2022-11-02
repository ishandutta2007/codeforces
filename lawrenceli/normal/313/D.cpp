#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1<<9;
const int MAXM = 100100;
const ll INF = 1e18;

int N, M, K;
struct data {
    int l, r, c;
    data() {}
    data(int _l, int _r, int _c) : l(_l), r(_r), c(_c) {}
};
vector<data> v[MAXN];
ll mi[MAXN][MAXN], dp[MAXN][MAXN];
ll tree[MAXN][2*MAXN];

void setmin(ll& a, ll b) { if (a > b) a = b; }

void update(int c, int p, ll v, int cur=1, int lt=0, int rt=N+1) {
    if (lt + 1 == rt) setmin(tree[c][cur], v);
    else {
        int mid = (lt + rt) / 2;
        if (p < mid) update(c, p, v, 2*cur, lt, mid);
        else update(c, p, v, 2*cur+1, mid, rt);
        tree[c][cur] = min(tree[c][2*cur], tree[c][2*cur+1]);
    }
}

ll query(int c, int ql, int qr, int cur=1, int lt=0, int rt=N+1) {
    if (rt <= ql || lt >= qr) return INF;
    if (lt >= ql && rt <= qr) return tree[c][cur];
    else {
        int mid = (lt + rt) / 2;
        return min(query(c, ql, qr, 2*cur, lt, mid),
                   query(c, ql, qr, 2*cur+1, mid, rt));
    }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &N, &M, &K);
    for (int i=0; i<M; i++) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        v[r].push_back(data(l, r, c));
    }

    for (int i=0; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            mi[i][j] = dp[i][j] = INF;

    for (int r=1; r<=N; r++)
        for (int i=0; i<v[r].size(); i++) {
            int l = v[r][i].l, c = v[r][i].c;
            for (int l1=l; l1<=r; l1++)
                setmin(mi[l1][r], c);
        }

    dp[0][0] = 0;
    for (int i=1; i<=N; i++)
        for (int k=0; k<=N; k++) {
            setmin(dp[i][k], dp[i-1][k]);
            for (int j=0; j<i; j++)
                if (k-(i-j)>=0)
                    setmin(dp[i][k], dp[j][k-(i-j)]+mi[j+1][i]);
        }

    ll ans = INF;
    for (int i=1; i<=N; i++)
        for (int k=K; k<=N; k++) {
            setmin(ans, dp[i][k]);
        }

    if (ans == INF) {
        printf("-1\n");
        return 0;
    }
    printf("%I64d\n", ans);
    return 0;
}