
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
    int n, x;
    cin >> n >> x;
    vi w(n);
    rep(i, 0, n) cin >> w[i];
    sort(all(w));
    int s = 0;
    rep(i, 0, n - 1) {
        s += w[i];
        if(s == x) {
            s -= w[i];
            swap(w[i], w[i + 1]);
            s += w[i];
        }
    }
    s += w[n - 1];
    if(s == x) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
        for(int a : w) cout << a << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}