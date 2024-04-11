#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1000 * 1000 + 10;

int len[N];
vector<int> dist[N];
vector<ll> sum[N];
int n;

void build(int v) {
    dist[v].push_back(0);
    vector<int> L[2];
    for (int i = 0; i < 2; i++)
        if (2 * v + i <= n) {
            build(2 * v + i);
            L[i] = dist[2 * v + i];
            for (int& d : L[i])
                d += len[2 * v + i];
        }
    merge(L[0].begin(), L[0].end(), L[1].begin(), L[1].end(), back_inserter(dist[v]));
    sum[v].resize(dist[v].size());
    sum[v][0] = dist[v][0];
    for (size_t i = 1; i < dist[v].size(); i++)
        sum[v][i] = sum[v][i - 1] + dist[v][i];
}

ll calc_ans(int v, ll cur, ll h) {
    if (v > n)
        return 0;
    auto it = upper_bound(dist[v].begin(), dist[v].end(), h - cur);
    if (it == dist[v].begin())
        return 0;
    ll cnt = it - dist[v].begin();
    return cnt * (h - cur) - sum[v][cnt - 1];
}

ll solve(int v, ll h) {
    ll ans = calc_ans(v, 0, h);  
    ll cur = 0;
    for (;v > 1; v /= 2) {
        cur += len[v];
        if (cur < h)
            ans += h - cur;
        int other = v ^ 1;
        ans += calc_ans(other, cur + len[other], h);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
        cin >> len[i];
    build(1);
    for (int i = 0; i < m; i++) {
        int a, h;
        cin >> a >> h;
        cout << solve(a, h) << "\n";
    }
    
}