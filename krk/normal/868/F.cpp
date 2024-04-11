#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const ll Inf = 4000000000000000000ll;
const int Maxn = 100005;
const int Maxp = 600;
const int Maxk = 22;

int n, k;
int a[Maxn];
vector <int> inds[Maxn];
vector <ii> seq;
int curbig, bigind[Maxn];
int B[Maxp][Maxn];
ll dp[Maxk][Maxn];

int Get(int v, int lef, int rig)
{
    if (bigind[v]) return B[bigind[v]][rig] - B[bigind[v]][lef - 1];
    auto L = lower_bound(inds[v].begin(), inds[v].end(), lef);
    auto R = upper_bound(L, inds[v].end(), rig);
    return R - L;
}

struct pos {
    int l, r;
    ll cost;
    void increaseLeft() {
        cost += Get(a[l - 1], l, r);
        l--;
    }
    void decreaseLeft() {
        l++;
        cost -= Get(a[l - 1], l, r);
    }
    void increaseRight() {
        cost += Get(a[r + 1], l, r);
        r++;
    }
    void decreaseRight() {
        r--;
        cost -= Get(a[r + 1], l, r);
    }
};

void Solve(int k, int l, int r, const pos &L, const pos &R)
{
    int m = l + r >> 1;
    pos my = L;
    while (my.r < m) my.increaseRight();
    ll cur = dp[k - 1][my.l - 1] + my.cost;
    pos wth = my;
    int to = min(m, R.l);
    for (int i = my.l + 1; i <= to; i++) {
        my.decreaseLeft();
        ll cand = dp[k - 1][my.l - 1] + my.cost;
        if (cand < cur) {
            cur = cand;
            wth = my;
        }
    }
    dp[k][m] = cur;
    if (l < m) Solve(k, l, m - 1, L, wth);
    if (m < r) Solve(k, m + 1, r, wth, R);
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        inds[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) if (!inds[i].empty()) {
        seq.push_back(ii(inds[i].size(), i));
    }
    sort(seq.rbegin(), seq.rend());
    for (int z = 0; z < seq.size() && z + 1 < Maxp; z++) {
        int i = seq[z].second;
        bigind[i] = ++curbig;
        int pnt = 0;
        for (int j = 1; j <= n; j++) {
            B[curbig][j] = B[curbig][j - 1];
            if (pnt < inds[i].size() && inds[i][pnt] == j) {
                B[curbig][j]++;
                pnt++;
            }
        }
    }
    fill(dp[0] + 1, dp[0] + Maxn, Inf);
    for (int i = 1; i <= k; i++)
        Solve(i, 1, n, {1, 1, 0ll}, {n, n, 0ll});
    cout << dp[k][n] << endl;
    return 0;
}