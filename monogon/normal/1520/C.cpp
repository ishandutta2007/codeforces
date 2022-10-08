
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
    if(n == 1) {
        cout << 1 << '\n';
    }else if(n == 2) {
        cout << -1 << '\n';
    }else {
        vector<vi> a(n, vi(n, 0));
        int c = 1;
        rep(i, 0, n) {
            for(int j = (i % 2 == 0); j < n; j += 2) a[i][j] = c++;
        }
        rep(i, 0, n) {
            for(int j = (i % 2 == 1); j < n; j += 2) a[i][j] = c++;
        }
        rep(i, 0, n) {
            rep(j, 0, n) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}