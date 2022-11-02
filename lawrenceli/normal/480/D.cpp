#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;
const int MAXS = 1005;

int n, S, in[MAXN], out[MAXN], w[MAXN], s[MAXN], v[MAXN], ind[MAXN], nxt[MAXN];
int dp[MAXN][MAXS];
bool good[MAXN][MAXN];

bool cmp(int a, int b) {
    return out[a] < out[b];
}

int calc(int i, int x) {
    if (x<0) return 0;
    int& ret = dp[i][x];
    if (ret != -1) return ret;
    vector<int> dp2 (n+1);
    dp2[0] = v[i];
    for (int j1=0; j1<n; j1++) {
        int j = ind[j1];
        if (good[i][j]) {
            dp2[j1+1] = max(dp2[j1], dp2[nxt[j1+1]]+calc(j, min(s[j], x-w[j])));
        } else {
            dp2[j1+1] = dp2[j1];
        }
    }
    return ret = dp2[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));

    cin >> n >> S;
    for (int i=0; i<n; i++) {
        cin >> in[i] >> out[i] >> w[i] >> s[i] >> v[i];
        ind[i] = i;
    }
    in[n] = -1, out[n] = 2*MAXN, w[n] = 0, s[n] = S, v[n] = 0;
    n++;
    sort(ind, ind+n, cmp);
    for (int i=0; i<n; i++)
        for (int j=i-1; j>=0; j--)
            if (out[ind[j]] <= in[ind[i]]) {
                nxt[i+1] = j+1; break;
            }

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (i != j)
                good[i][j] = in[i] <= in[j] && out[i] >= out[j];

    cout << calc(n-1, S) << '\n';
}