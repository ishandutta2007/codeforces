
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
    const int G = 720720;
    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
    rep(i, 0, n) {
        rep(j, 0, m) {
            if((i + j) % 2) {
                cout << G << ' ';
            }else {
                cout << G - 1LL * a[i][j] * a[i][j] * a[i][j] * a[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}