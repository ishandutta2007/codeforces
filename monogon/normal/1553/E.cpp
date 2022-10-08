
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
    int n, m;
    cin >> n >> m;
    vi cnt(n, 0), p(n);
    rep(i, 0, n) {
        cin >> p[i];
        cnt[(p[i] - 1 - i + n) % n]++;
    }
    vi ans;
    rep(s, 0, n) {
        if(cnt[s] * 3 >= n) {
            vi p2(n);
            rep(i, 0, n) p2[(i + s) % n] = p[i] - 1;
            vector<bool> vis(n);
            int c = 0;
            rep(i, 0, n) {
                if(!vis[i]) {
                    int x = i;
                    c++;
                    while(!vis[x]) {
                        vis[x] = true;
                        x = p2[x];
                    }
                }
            }
            if(c >= n - m) {
                ans.push_back((n - s) % n);
            }
        }
    }
    sort(all(ans));
    cout << sz(ans) << ' ';
    for(int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}