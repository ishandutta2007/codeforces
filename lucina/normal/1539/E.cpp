#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5 + 10;
int n, m;
set <int> dp[2];
int last_val = 0;
pair <int, int> specific[nax][2];
int samp[nax][2];
int sk[nax];

bool in_range(int x, int l, int r) {
    return x >= l && x <= r;
}

void clear_set(set <int> &s, int l, int r) {
    while (!s.empty() && *s.begin() < l) s.erase(s.begin());
    while (!s.empty() && *prev(s.end()) > r) s.erase(prev(s.end()));
}

void query(int id) {
    int k, a[2], b[2];
    cin >> k >> a[0] >> b[0] >> a[1] >> b[1];
    sk[id] = k;
    int can[2];
    bool inher[2];
    memset(inher, false, sizeof(inher));
    memset(can, -1, sizeof(can));

    for (int i = 0 ; i < 2 ; ++ i) {
        if (dp[i].empty()) continue;
        if (in_range(k, a[i], b[i]))
            inher[i] = true;
        if (in_range(last_val, a[i], b[i]) && in_range(k, a[i ^ 1], b[i ^ 1]))
            can[i ^ 1] = last_val;
    }

    for (int i = 0 ; i < 2 ; ++ i) {
        if (!inher[i]) dp[i].clear();
        else clear_set(dp[i], a[i ^ 1], b[i ^ 1]);
    }

    for (int i = 0 ; i < 2 ; ++ i)
        if (can[i] != -1) {
                dp[i].insert(last_val);
                if (i == 0) specific[id][i] = make_pair(k, last_val);
                else specific[id][i] = make_pair(last_val, k);
        }

    for (int i = 0 ; i < 2 ; ++ i) {
        if (!dp[i].empty()) samp[id][i] = *dp[i].begin();
    }

    last_val = k;
}


void restore(int cur, int i, int x, int y) {
    if (cur == 0) return;
    auto [u, v] = specific[cur][i];
    if (u == x && v == y) {
        int t = samp[cur - 1][i ^ 1];
        if (i == 0) restore(cur - 1, i ^ 1, t, y);
        else restore(cur - 1, i ^ 1, x, t);
    } else {
        if (i == 0) restore(cur - 1, i, sk[cur - 1], y);
        else restore(cur - 1, i, x, sk[cur - 1]);
    }
    cout << i << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;

    dp[0].insert(1);
    dp[1].insert(1);

    for (int i = 0 ; i < n ; ++ i) {
        query(i + 1);
    }

    if (dp[0].empty() && dp[1].empty()) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        if (!dp[0].empty()) restore(n, 0, last_val, *dp[0].begin());
        else restore(n, 1, *dp[1].begin(), last_val);
    }
}