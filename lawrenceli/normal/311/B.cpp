#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <deque>

using namespace std;

typedef long long ll;

const int MAXN = 100100;
const int MAXP = 105;
const ll INF = 1e15;

int n, m, p, d[MAXN], hd[MAXN], h[MAXN], t[MAXN];
ll x[MAXN], pre[MAXN], dp[MAXP][MAXN];

struct line {
    ll m, b;
    ll val(ll x) { return m*x + b; }
    line() {}
    line(ll m, ll b) : m(m), b(b) {}
};

deque<line> dq;

bool del(line l3) {
    line l1 = dq[dq.size()-2], l2 = dq[dq.size()-1];
    return (l3.b - l1.b) * (l2.m - l1.m) > (l2.b - l1.b) * (l3.m - l1.m);
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n >> m >> p;
    for (int i=0; i<n-1; i++) {
        cin >> d[i];
        hd[i+1] = hd[i] + d[i];
    }
    for (int i=0; i<m; i++) {
        cin >> h[i] >> t[i]; h[i]--;
        x[i] = t[i] - hd[h[i]];
    }

    sort(x, x + m);
    for (int i=0; i<m; i++)
        pre[i+1] = pre[i] + x[i];

    dp[0][0] = 0;
    for (int i=1; i<=p; i++) {
        dq.clear();
        dp[i][0] = 0;
        for (int j=1; j<=m; j++) {
            line l = line(-(j-1), dp[i-1][j-1] + pre[j-1]);
            while (dq.size() >= 2 && del(l)) dq.pop_back();
            if (i > 1 || j == 1) dq.push_back(l);
            while (dq.size() >= 2 && dq[1].val(x[j-1]) <= dq[0].val(x[j-1])) dq.pop_front();
            dp[i][j] = x[j-1] * j - pre[j] + dq[0].val(x[j-1]);
        }
    }

    ll ans = INF;
    for (int i=1; i<=p; i++)
        ans = min(ans, dp[i][m]);

    cout << ans << endl;
    return 0;
}