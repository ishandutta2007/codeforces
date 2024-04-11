
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
    int n, k, m;
    cin >> n >> k >> m;
    map<string, int> ma;
    vector<ll> a(n), A(k, LLONG_MAX);
    vector<string> s(n);
    rep(i, 0, n) {
        cin >> s[i];
        ma[s[i]] = i;
    }
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, k) {
        int x;
        cin >> x;
        rep(j, 0, x) {
            int idx;
            cin >> idx;
            idx--;
            ma[s[idx]] = i;
            A[i] = min(A[i], a[idx]);
        }
    }
    ll ans = 0;
    rep(i, 0, m) {
        string S;
        cin >> S;
        ans += A[ma[S]];
    }
    cout << ans << '\n';
}