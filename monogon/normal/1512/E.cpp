
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
    int n, l, r;
    ll s;
    cin >> n >> l >> r >> s;
    vector<int> ve, ve2;
    int len = r - l + 1;
    for(int i = n; i >= 1; i--) {
        if(s - i >= 1LL * (len - 1) * len / 2 && len > 0) {
            ve.push_back(i);
            len--;
            s -= i;
        }else {
            ve2.push_back(i);
        }
    }
    if(s > 0) {
        cout << -1 << '\n';
        return;
    }
    rep(i, 0, l - 1) {
        cout << ve2.back() << ' ';
        ve2.pop_back();
    }
    for(int x : ve) {
        cout << x << ' ';
    }
    for(int x : ve2) {
        cout << x << ' ';
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