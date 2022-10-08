
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
    int cnt[3] = {0, 0, 0};
    rep(i, 0, n) {
        int a;
        cin >> a;
        cnt[a % 3]++;
    }
    int amt = n / 3;
    int ans = 0;
    rep(it, 0, 2) {
        rep(i, 0, 3) {
            if(cnt[i] > amt) {
                ans += cnt[i] - amt;
                cnt[(i + 1) % 3] += cnt[i] - amt;
                cnt[i] = amt;
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}