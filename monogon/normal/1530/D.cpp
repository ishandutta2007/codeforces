
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
    vi a(n + 1), b(n + 1);
    vector<bool> vis(n + 1, false);
    int cnt = 0;
    rep(i, 1, n + 1) {
        cin >> a[i];
        if(!vis[a[i]]) {
            cnt++;
            b[i] = a[i];
            vis[a[i]] = true;
        }
    }
    cout << cnt << '\n';
    int j = n;
    rep(i, 1, n + 1) {
        if(b[i] == 0) {
            while(vis[j]) j--;
            b[i] = j;
            j--;
        }
    }
    rep(i, 1, n + 1) {
        if(b[i] == i) {
            b[i] = a[i];
            rep(j, 1, n + 1) {
                if(j != i && b[j] == a[i]) {
                    b[j] = i;
                }
            }
            break;
        }
    }
    rep(i, 1, n + 1) {
        cout << b[i] << ' ';
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