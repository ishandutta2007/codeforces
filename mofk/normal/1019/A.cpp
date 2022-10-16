#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <long long> v[3005];

long long calc(int x) {
    long long ret = 0;
    int need = x - v[1].size();
    priority_queue <long long> q;
    for (int i = 2; i <= m; ++i) {
        int ptr = 0;
        while (v[i].size() - ptr >= x) {
            ret += v[i][ptr];
            ++ptr;
            --need;
        }
        for (; ptr < v[i].size(); ++ptr) q.push(-v[i][ptr]);
    }
    while (need > 0) {
        ret -= q.top();
        q.pop();
        --need;
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int id, p;
        cin >> id >> p;
        v[id].push_back(p);
    }
    if (m == 1) return cout << 0 << endl, 0;
    for (int i = 1; i <= m; ++i) sort(v[i].begin(), v[i].end());
    long long ans = 1e18;
    for (int i = max(1, (int)v[1].size()); i <= n; ++i) ans = min(ans, calc(i));
    cout << ans << endl;
    return 0;
}