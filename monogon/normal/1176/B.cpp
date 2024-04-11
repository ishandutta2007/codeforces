
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
    array<int, 3> cnt = {0};
    rep(i, 0, n) {
        int a;
        cin >> a;
        cnt[a % 3]++;
    }    
    int ans = cnt[0];
    int amt = min(cnt[1], cnt[2]);
    ans += amt;
    cnt[1] -= amt;
    cnt[2] -= amt;
    ans += cnt[1] / 3 + cnt[2] / 3;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}