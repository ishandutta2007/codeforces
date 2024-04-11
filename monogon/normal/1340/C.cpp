#include <bits/stdc++.h>

#define ll long long
using namespace std;

// vertex is (i, t), 0 <= i < m, and 0 <= t <= g
// store as (m * t + i)
// 0-1 BFS

const int M = 1e4 + 5, G = 1005;
int n, m, g, r, d[M];
ll dist[M * G];
bool vis[M * G];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> d[i];
    }
    sort(d, d + m);
    cin >> g >> r;
    deque<int> q;
    q.push_back(0);
    vis[0] = true;
    ll ans = LLONG_MAX;
    while(!q.empty()) {
        int x = q.front(); q.pop_front();
        int i = x % m, t = x / m;
        auto check = [&] (int y) {
            if(!vis[y]) {
                bool b = (y < m);
                vis[y] = true;
                dist[y] = dist[x] + b;
                if(b) q.push_back(y);
                else q.push_front(y);
                if(y % m == m - 1) {
                    if(y / m == 0) {
                        ans = min(ans, dist[y] * (g + r) - r);
                    }else {
                        ans = min(ans, dist[y] * (g + r) + (y / m));
                    }
                }
            }
        };
        if(i > 0 && t + d[i] - d[i - 1] <= g) {
            check(m * ((t + d[i] - d[i - 1]) % g) + i - 1);
        }
        if(i < m - 1 && t + d[i + 1] - d[i] <= g) {
            check(m * ((t + d[i + 1] - d[i]) % g) + i + 1);
        }
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
}