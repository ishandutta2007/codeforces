
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
    rep(i, 0, n) cin >> a[i];
    rep(mask, 1, 1 << n) {
        for(int s = mask; s > 0; s = (s - 1) & mask) {
            int sum = 0;
            rep(i, 0, n) {
                if(mask >> i & 1) {
                    if(s >> i & 1) sum += a[i];
                    else sum -= a[i];
                }
            }
            if(sum == 0) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}