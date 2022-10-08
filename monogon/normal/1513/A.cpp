
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
    int n, k;
    cin >> n >> k;
    if(k > (n - 1) / 2) {
        cout << -1 << '\n';
        return;
    }
    vi a(n);
    int p = n;
    int idx = 1;
    while(k > 0) {
        a[idx] = p;
        idx += 2;
        k--;
        p--;
    }
    rep(i, 0, n) {
        if(a[i] == 0) {
            a[i] = p;
            p--;
        }
        cout << a[i] << ' ';
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