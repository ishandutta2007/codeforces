
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
    vi cnt(n + 1);
    rep(i, 0, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    priority_queue<int> Q;
    ll ops = 0;
    bool flag = false;
    rep(i, 0, n + 1) {
        if(flag) {
            cout << -1 << ' ';
        }else {
            cout << ops + cnt[i] << ' ';
        }
        if(cnt[i] == 0) {
            if(Q.empty()) {
                flag = true;
            }else {
                ops += i - Q.top();
                Q.pop();
            }
        }else {
            rep(j, 0, cnt[i] - 1) {
                Q.push(i);
            }
        }
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