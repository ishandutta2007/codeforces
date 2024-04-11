
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
    cin >> n >> l >> r;
    vector<vi> cnt(n + 1, vi(2, 0));
    rep(i, 0, l) {
        int c;
        cin >> c;
        cnt[c][0]++;
    }
    rep(i, 0, r) {
        int c;
        cin >> c;
        cnt[c][1]++;
    }
    int L = 0, R = 0;
    ll cost = 0;
    rep(i, 1, n + 1) {
        int m = min(cnt[i][0], cnt[i][1]);
        cnt[i][0] -= m;
        cnt[i][1] -= m;
        L += cnt[i][0];
        R += cnt[i][1];
    }
    rep(i, 1, n + 1) {
        if(L > R) {
            int m = min(L - R, cnt[i][0]);
            if(m % 2 == 1) m--;
            cost += m / 2;
            L -= m;
        }else {
            int m = min(R - L, cnt[i][1]);
            if(m % 2 == 1) m--;
            cost += m / 2;
            R -= m;
        }
    }
    cost += min(L, R) + abs(L - R);
    cout << cost << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}