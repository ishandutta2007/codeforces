
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// choose k intervals, maximizing intersection
// scan a value x. We should only consider intervals with l[i] <= x.
// when considering a new interval, only insert it if we kick out
// a different interval so that the size increases.
// pop interval with minimum r value.
// if size < k, don't pop and just insert. Otherwise, consider both and record answer

const int N = 3e5 + 5;
int n, k;
ll l[N], r[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    vector<tuple<ll, ll, int>> ve;
    rep(i, 1, n + 1) {
        cin >> l[i] >> r[i];
        ve.emplace_back(l[i], r[i], i);
    }
    sort(all(ve));
    minpq<ll> Q;
    ll ans = 0;
    rep(i, 0, n) {
        ll L, R;
        tie(L, R, ignore) = ve[i];
        if(sz(Q) < k) {
            Q.push(R);
        }else {
            if(Q.top() < R) {
                Q.pop();
                Q.push(R);
            }
        }
        if(sz(Q) == k) {
            ans = max(ans, Q.top() - L + 1);
        }
    }
    cout << ans << '\n';
    minpq<pair<ll, int>> Q2;
    rep(i, 0, n) {
        auto [L, R, I] = ve[i];
        if(sz(Q2) < k) {
            Q2.emplace(R, I);
        }else {
            if(Q2.top().fi < R) {
                Q2.pop();
                Q2.emplace(R, I);
            }
        }
        if(sz(Q2) == k && (Q2.top().fi - L + 1 == ans || ans == 0)) {
            while(!Q2.empty()) {
                int j = Q2.top().se; Q2.pop();
                cout << j << ' ';
            }
            cout << '\n';
            return 0;
        }
    }
}