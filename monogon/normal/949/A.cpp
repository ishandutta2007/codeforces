
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
    vi ve[2];
    string s;
    int n;
    cin >> s;
    n = s.length();
    vi pre(n, -1);
    rep(i, 0, n) {
        bool b = (s[i] == '0');
        if(!ve[!b].empty()) {
            pre[i] = ve[!b].back();
            ve[b].push_back(i);
            ve[!b].pop_back();
        }else {
            if(!b) {
                cout << -1 << '\n';
                return 0;
            }
            ve[b].push_back(i);
        }
    }
    if(!ve[0].empty()) {
        cout << -1 << '\n';
        return 0;
    }
    vector<vi> ans;
    vector<bool> vis(n, false);
    for(int i = n - 1; i >= 0; i--) {
        if(vis[i]) continue;
        int idx = i;
        vi v;
        while(idx != -1) {
            vis[idx] = true;
            v.push_back(idx);
            idx = pre[idx];
        }

        reverse(all(v));
        ans.push_back(v);
    }
    cout << sz(ans) << '\n';
    for(vi &v : ans) {
        cout << sz(v) << ' ';
        for(int x : v) cout << x+1 << ' ';
        cout << '\n';
    }
}