
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
    vector<bool> h(n, false);
    rep(i, 0, n) {
        cin >> a[i];
    }
    if(n < 3) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    auto hill = [&](int a, int b, int c) {
        return (a > b && b < c) || (a < b && b > c);
    };
    rep(i, 1, n - 1) {
        if(hill(a[i - 1], a[i], a[i + 1])) {
            ans++;
            h[i] = true;
        }
    }
    int ans1 = ans;
    if(hill(a[0], a[1], a[2])) ans = min(ans, ans1 - 1);
    if(hill(a[n - 3], a[n - 2], a[n - 1])) ans = min(ans, ans1 - 1);
    rep(i, 1, n - 1) {
        int hmm = ans1 - h[i - 1] - h[i + 1] - h[i];
        int tmp = a[i];
        for(int j : {-1, (int) 1e9 + 5, a[i - 1], a[i + 1]}) {
            a[i] = j;
            ans = min(ans, hmm + (i - 2 >= 0 ? hill(a[i - 2], a[i - 1], a[i]) : 0)
                    + hill(a[i - 1], a[i], a[i + 1])
                    + (i + 2 < n ? hill(a[i], a[i + 1], a[i + 2]) : 0));
        }
        a[i] = tmp;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}