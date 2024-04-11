
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
    int n;
    cin >> n;
    vi p(n + 1);
    rep(i, 1, n + 1) cin >> p[i];
    vector<bool> vis(n + 1, false);
    rep(i, 1, n + 1) {
        fill(all(vis), false);
        int x = i;
        while(!vis[x]) {
            vis[x] = true;
            x = p[x];
        }
        cout << x << ' ';
    }
    cout << '\n';
}