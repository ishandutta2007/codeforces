
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
    map<int, int> cnt;
    rep(i, 0, n) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int mx = 0;
    for(auto &pa : cnt) {
        mx = max(mx, pa.second);
    }
    if(mx * 2 >= n) {
        cout << 2 * mx - n << '\n';
        return;
    }
    cout << (n % 2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}