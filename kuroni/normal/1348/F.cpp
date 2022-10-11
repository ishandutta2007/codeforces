#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, af[N], l[N], r[N], a[N], pos[N];
vector<pair<int, int>> eve[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        eve[l[i]].push_back({r[i], i});
    }
    for (int i = 1; i <= n; i++) {
        for (pair<int, int>& cur : eve[i]) {
            pq.push(cur);
        }
        auto [r, ind] = pq.top(); pq.pop();
        a[ind] = i;
        pos[i] = ind;
        if (!pq.empty()) {
            af[ind] = pq.top().second;
        }
    }
    for (int i = 1; i <= n; i++) {
        int cur = i, nxt = af[i];
        if (nxt != 0 && l[cur] <= a[nxt] && a[nxt] <= r[cur] && l[nxt] <= a[cur] && a[cur] <= r[nxt]) {
            cout << "NO\n";
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " \n"[i == n];
            }
            swap(a[cur], a[nxt]);
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " \n"[i == n];
            }
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}