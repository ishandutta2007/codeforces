
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

int a[4][4] = {
    {1, 0, 0, 1},
    {0, 1, 1, 0},
    {0, 1, 1, 0},
    {1, 0, 0, 1},
};

void solve() {
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) rep(j, 0, m) {
        cout << a[i % 4][j % 4] << ' ';
        if(j == m - 1) cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}