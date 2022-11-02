#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 25;

int n, xs, ys, x[MAXN], y[MAXN];
int dp[1<<MAXN], par[1<<MAXN];

int dist1[MAXN], dist[MAXN][MAXN];

void init() {
    for (int i=0; i<n; i++)
        dist1[i] = (xs - x[i]) * (xs - x[i]) + (ys - y[i]) * (ys - y[i]);

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            dist[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int calc(int cur) {
    int& ret = dp[cur], &nxt = par[cur];
    if (ret != -1) return ret;
    ret = -1U >> 1;
    for (int i=0; i<n; i++)
        if (!(cur & 1<<i)) {
            int res = calc(cur ^ 1<<i) + 2*dist1[i];
            if (res < ret)
                ret = res, nxt = cur ^ 1<<i;
            break;
        }

    for (int i=0; i<n; i++)
        if (!(cur & 1<<i)) {
            for (int j=0; j<n; j++)
                if (i != j && !(cur & 1<<j)) {
                    int ncur = cur ^ 1<<i ^ 1<<j;
                    int res = calc(ncur) + dist1[i] + dist1[j] + dist[i][j];
                    if (res < ret)
                        ret = res, nxt = ncur;
                }
            break;
        }

    return ret;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> xs >> ys;
    cin >> n;
    for (int i=0; i<n; i++) cin >> x[i] >> y[i];

    memset(dp, -1, sizeof(dp));
    dp[(1<<n) - 1] = 0;

    init();

    cout << calc(0) << '\n';

    int cur = 0;
    vector<int> v;

    while (cur != ((1<<n) - 1)) {
        v.push_back(0);
        int p = par[cur];
        for (int i=0; i<n; i++)
            if ((p & 1<<i) && !(cur & 1<<i))
                v.push_back(i+1);
        cur = p;
    }
    v.push_back(0);

    for (int i=v.size()-1; i>=0; i--) cout << v[i] << ' ';

    return 0;
}