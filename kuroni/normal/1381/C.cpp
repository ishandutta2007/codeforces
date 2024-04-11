#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, x, y, te, emp, a[N], b[N], cnt[N];
vector<int> pos[N];
priority_queue<pair<int, int>> pq;
vector<int> tmp;

void solve() {
    cin >> n >> x >> y; y -= x;
    fill(b + 1, b + n + 1, 0);
    fill(cnt + 1, cnt + n + 2, 0);
    tmp.clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n + 1; i++) {
        pq.push({cnt[i], i});
        if (cnt[i] == 0) {
            emp = i;
        }
    }
    while (x--) {
        auto [v, u] = pq.top(); pq.pop();
        int p = pos[u].back(); pos[u].pop_back();
        b[p] = u;
        pq.push({v - 1, u});
    }
    int mx = pq.top().first;
    while (!pq.empty()) {
        auto [v, u] = pq.top(); pq.pop();
        while (v--) {
            tmp.push_back(pos[u].back());
            pos[u].pop_back();
        }
    }
    int sz = tmp.size();
    for (int i = 0; i < sz && y > 0; i++) {
        if (a[tmp[i]] != a[tmp[(i + mx) % sz]]) {
            b[tmp[i]] = a[tmp[(i + mx) % sz]];
            y--;
        }
    }
    if (y > 0) {
        return void(cout << "NO\n");
    }
    for (int i = 0; i < sz; i++) {
        if (b[tmp[i]] == 0) {
            b[tmp[i]] = emp;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> te;
    while (te--) {
        solve();
    }
}