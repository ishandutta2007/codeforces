
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
    vi a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    int m;
    cin >> m;
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        if(x > 1) a[x - 1] += y - 1;
        if(x < n) a[x + 1] += a[x] - y;
        a[x] = 0;
    }
    rep(i, 1, n + 1) cout << a[i] << '\n';
}