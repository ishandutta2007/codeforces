#include <bits/stdc++.h>

using namespace std;
typedef pair <pair <int, int>, long long> edge;
int n, m;
int u[300005], v[300005];
long long w[300005];
long long a[100005];
int ans;
vector <edge> ret;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
        a[u[i]] -= w[i];
        a[v[i]] += w[i];
    }
    queue <int> pos, neg;
    for (int i = 1; i <= n; ++i) if (a[i] > 0) pos.push(i); else if (a[i] < 0) neg.push(i);
    while (pos.size() && neg.size()) {
        int x = neg.front(), y = pos.front();
        pos.pop(); neg.pop();
        long long f = min(-a[x], a[y]);
        ret.push_back({{x, y}, f});
        a[x] += f;
        a[y] -= f;
        if (a[x] < 0) neg.push(x);
        if (a[y] > 0) pos.push(y);
    }
    cout << ret.size() << endl;
    for (auto p: ret) cout << p.first.first << ' ' << p.first.second << ' ' << p.second << '\n';
    return 0;
}