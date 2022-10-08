
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
    int te;
    cin >> te;
    while(te--) {
        int n;
        ll W;
        cin >> n >> W;
        vi ans;
        ll sum = 0;
        vector<ll> w(n);
        rep(i, 0, n) cin >> w[i];
        rep(i, 0, n) {
            if(w[i] > W) continue;
            if(2 * w[i] >= W) {
                cout << 1 << '\n' << i + 1 << '\n';
                goto hell;
            }else if(sum + w[i] <= W) {
                sum += w[i];
                ans.push_back(i + 1);
            }
        }
        if(2 * sum >= W) {
            cout << sz(ans) << '\n';
            for(int i : ans) cout << i << ' ';
            cout << '\n';
        }else {
            cout << -1 << '\n';
        }
        hell:;
    }
}