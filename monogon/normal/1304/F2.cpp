
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 55, M = 2e4 + 5;
int n, m, k, a[N][M];
ll dp[N][M], pref[N][M], prefmax[M], suffmax[M];

int range(int i, int j) {
    return pref[i][j + k - 1] - pref[i][j - 1];
}

struct window {
    int l, r;
    ll a[M];
    deque<int> q;
    window(): l(1), r(1) {}
    void left() {
        if(!q.empty() && q.front() == l) q.pop_front();
        l++;
    }
    void right() {
        while(!q.empty() && a[q.back()] <= a[r]) q.pop_back();
        q.push_back(r++);
    }
    ll getmax(int L, int R) {
        assert(l <= L);
        assert(r <= R);
        while(r < R) right();
        while(l < L) left();
        return q.empty() ? LLONG_MIN : a[q.front()];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pref[i][j] = pref[i][j - 1] + a[i][j];
        }
    }
    for(int i = 2; i <= n + 1; i++) {
        for(int j = 1; j <= m - k + 1; j++) {
            prefmax[j] = max(prefmax[j - 1], range(i - 1, j) + range(i, j) + dp[i - 1][j]);
        }
        for(int j = m - k + 1; j >= 1; j--) {
            suffmax[j] = max(suffmax[j + 1], range(i - 1, j) + range(i, j) + dp[i - 1][j]);
        }
        window w1, w2;
        for(int j = 1; j <= m - k + 1; j++) {
            w1.a[j] = range(i - 1, j) + pref[i][j + k - 1] + dp[i - 1][j];
            w2.a[j] = range(i - 1, j) - pref[i][j - 1] + dp[i - 1][j];
        }
        for(int j = 1; j <= m - k + 1; j++) {
            dp[i][j] = max({
                prefmax[max(0, j - k)],
                suffmax[min(j + k, m - k + 2)],
                -pref[i][j + k - 1] + w1.getmax(j, min(j + k, m - k + 2)),
                pref[i][j - 1] + w2.getmax(max(1, j - k + 1), j)
            });
        }
    }
    cout << dp[n + 1][1] << endl;
}