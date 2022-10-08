
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi c(n * k + 1);
    vector<vi> ve(n + 1);
    rep(i, 1, n * k + 1) {
        cin >> c[i];
        ve[c[i]].push_back(i);
    }
    vector<pii> ans(n + 1, {-1, -1});
    vi vis(n + 1, -1);
    for(int i = 1; i <= n; i += k - 1) {
        int i2 = min(i + k - 1, n + 1);
        vi hmm;
        rep(j, i, i2) {
            hmm.insert(hmm.end(), all(ve[j]));
        }
        sort(all(hmm));
        rep(j, i, i2) vis[j] = -1;
        for(int k : hmm) {
            if(ans[c[k]].first != -1) continue;
            if(vis[c[k]] != -1) {
                ans[c[k]] = {vis[c[k]], k};
                rep(j, i, i2) vis[j] = -1;
            }else {
                vis[c[k]] = k;
            }
        }
    }
    ans.erase(ans.begin());
    for(auto &pa : ans) {
        cout << pa.first << ' ' << pa.second << '\n';
    }
}