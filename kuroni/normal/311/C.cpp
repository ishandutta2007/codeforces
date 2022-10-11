#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 1E5 + 5, K = 1E4 + 5;

long long h, x, p[N], dst[K];
int n, q, k, t, y, u, c[N];
set<pair<int, int>> se;
vector<long long> add;

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

void dijkstra() {
    fill(dst, dst + k, h + 1);
    pq.push({dst[0] = 0, 0});
    while (!pq.empty()) {
        pair<long long, int> u = pq.top(); pq.pop();
        if (dst[u.se] < u.fi) {
            continue;
        }
        for (long long &v : add) {
            long long tmp = u.fi + v;
            if (dst[tmp % k] > tmp) {
                pq.push({dst[tmp % k] = tmp, tmp % k});
            }
        }
    }
    se.clear();
    for (int i = 1; i <= n; i++) {
        if (p[i] != -1 && dst[p[i] % k] <= p[i]) {
            se.insert({c[i], -i});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> n >> q >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> c[i];
        p[i]--;
    }
    dijkstra();
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            add.push_back(x);
            dijkstra();
        } else if (t == 2) {
            cin >> u >> y;
            if (p[u] != -1 && dst[p[u] % k] <= p[u]) {
                se.erase({c[u], -u});
            }
            c[u] -= y;
            if (p[u] != -1 && dst[p[u] % k] <= p[u]) {
                se.insert({c[u], -u});
            }
        } else  {
            if (se.empty()) {
                cout << "0\n";
            } else {
                cout << se.rbegin()->first << '\n';
                p[-se.rbegin()->second] = -1;
                se.erase(prev(se.end()));
            }
        }
    }
}