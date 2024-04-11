#include<bits/stdc++.h>
using namespace std;
const int N = 300000 + 5;
using LL = long long;

int n, m;
int p[N];
int ok[N];
int ro_(int o, int k) {
    int ro = o - k;
    if (ro <= 0) ro += n;
    return ro;
}
int vis[N];
int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i += 1)
            cin >> p[i];
        for (int i = 0; i <= n; i += 1) ok[i] = 0;

        for (int i = 1; i <= n; i += 1) {
            int d = p[i] - i;
            if (d < 0) d += n;
            ok[d] ++;
        }
        vector<int> ans;
        for (int k = 0; k <= n - 1; k += 1) {

            if (n - (ok[k] + (n - ok[k]) / 2) <= m) {
                int cir = 0;
                for (int o = 1; o <= n; o += 1) vis[o] = 0;

                for (int o = 1; o <= n; o += 1) {
                    int cur = ro_(o, k);
                    if (vis[cur]) continue;
                    vis[cur] = 1;
                    while (p[cur] != o) {
                        cur = ro_(p[cur], k);
                        vis[cur] = 1;
                    }
                    cir++;
                }

                if (n - cir <= m)
                    ans.push_back((n - k) % n);
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << ' ';
        for (auto x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
/*
ABABABABAB
4433221100
544
*/