#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 1E5 + 5;

int n, m, l, r;
vector<int> ve;
vector<pair<int, int>> que[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> r >> l;
        l = n + 1 - l;
        que[l].push_back({r, i});
    }
    for (int i = 1; i <= n; i++) {
        for (pair<int, int> &v : que[i]) {
            pq.push(v);
        }
        while (!pq.empty() && pq.top().fi < i) {
            pq.pop();
        }
        if (!pq.empty()) {
            ve.push_back(pq.top().se);
            pq.pop();
        }
    }
    cout << ve.size() << '\n';
    for (int &v : ve) {
        cout << v << " ";
    }
}