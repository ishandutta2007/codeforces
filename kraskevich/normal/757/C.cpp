#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int N = (int)2e6;

const ll MOD = 1000 * 1000 * 1000 + 7;
ll f[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> p(m);
    for (int i = 0; i < n; i++) {
        int g;
        cin >> g;
        map<int, int> cnt;
        for (int j = 0; j < g; j++) {
            int x;
            cin >> x;
            x--;
            cnt[x]++;
        }
        for (auto kv : cnt)
            p[kv.first].push_back(pii(i, kv.second));    
    }
    sort(p.begin(), p.end());
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = f[i - 1] * i % MOD;
    int cur = 0;
    ll res = 1;
    for (int i = 0; i < m; i++) {
        cur++;
        if (i == m - 1 || p[i] != p[i + 1]) {
            res = (res * f[cur]) % MOD;      
            cur = 0;
        }
    }
    cout << res << endl;
}