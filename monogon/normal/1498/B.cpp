
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
    int n; ll W;
    cin >> n >> W;
    vector<ll> cnt(20, 0);
    rep(i, 0, n) {
        int a;
        cin >> a;
        int k = 0;
        while((1 << k) < a) k++;
        cnt[k]++;
    }
    int h = 1;
    while(true) {
        ll w = W;
        for(int i = 19; i >= 0; i--) {
            int amt = min(cnt[i], w / (1 << i));
            n -= amt;
            cnt[i] -= amt;
            w -= amt * (1 << i);
        }
        if(n == 0) {
            cout << h << '\n';
            return;
        }
        h++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}