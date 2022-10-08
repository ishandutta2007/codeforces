
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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    vector<bool> vis(n + 2);
    vi suffmex(n + 1);
    suffmex[n] = 0;
    int mex = 0;
    for(int i = n - 1; i >= 0; i--) {
        vis[a[i]] = true;
        while(vis[mex]) mex++;
        suffmex[i] = mex;
    }
    vi ans;
    int i = 0;
    while(i < n) {
        int mex = suffmex[i];
        ans.push_back(mex);
        fill(vis.begin(), vis.begin() + mex, false);
        int pref = 0;
        int cnt = 0;
        while(pref < mex) {
            assert(i < n);
            vis[a[i]] = true;
            while(vis[pref]) pref++;
            i++;
            cnt++;
        }
        if(cnt == 0) i++;
    }

    cout << sz(ans) << '\n';
    for(int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}