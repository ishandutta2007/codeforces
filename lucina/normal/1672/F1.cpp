#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];
int cnt[nax];
int ans[nax];

void solve() {
    cin >> n;
    fill(cnt, cnt + n + 1, 0);
    int mx_cnt = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        cnt[a[i]] += 1;
        mx_cnt = max(mx_cnt, cnt[a[i]]);
    }
    vector <array<int, 3>> f;
    for (int i = 1 ; i <= n ; ++ i) {
        f.push_back({cnt[a[i]], a[i], i});
    }
    sort(f.begin(), f.end());

    for (int i = 0 ; i < n ; ++ i) {
        int to = (i + mx_cnt) % n;
        ans[f[i][2]] = f[to][1];
    }
    for (int i = 1 ; i <= n ; ++ i)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    int T;
    cin.tie(0)->sync_with_stdio(false);
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    long time no rated round
*/