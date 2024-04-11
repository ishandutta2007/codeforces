#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int block = 314;
vector<int> ed[N];
vector<int> big[N];
int n, q;
double p[N], sum[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u++; v++;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        for (auto to: ed[i]) sum[i] += 1 -  p[to];
        for (auto to: ed[i])
            if (ed[to].size() > block) big[i].push_back(to);
    }
    double global = 0;
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        global += p[i];
        ans -= sum[i] * (1 - p[i]);
        ans += ed[i].size();
    }
    cin >> q;
    for (; q >= 1; q--) {
        int v; double c;
        scanf("%d%lf", &v, &c); v++;
        global += c - p[v];
        if (ed[v].size() <= block) {
            for (auto to: ed[v]) ans += 2 * (1 - p[to]) * (c - p[v]);
            for (auto to: big[v]) {
                sum[to] -= (1 - p[v]);
                sum[to] += (1 - c);
            }
            p[v] = c;
        }
        else {
            ans += 2 * (1 - p[v]) * sum[v];
            ans -= 2 * (1 - c) * sum[v];
            for (auto to: big[v]) {
                sum[to] -= (1 - p[v]);
                sum[to] += (1 - c);
            }
        }
        printf("%.5lf\n", ans / 2 + 1 - global);
    }
    return 0;
}