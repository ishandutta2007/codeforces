
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

pair<bool, ll> check(int s, ll sum, const vector<ll> &a, const vector<ll> &b, const vector<ll> &c, int idx) {
    ll add = sum * s;
    int I = 0, J = 0;
    rep(i, 0, idx) {
        ll val1 = c[i] * a[I];
        ll val2 = c[i] * b[J];
        if(J == idx - s || (I < s && val1 >= val2)) {
            add += val1;
            I++;
        }else {
            add += val2;
            J++;
        }
    }
    return make_pair(I == s, add);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> c(n);
    rep(i, 0, n) cin >> c[i];
    sort(all(c));
    int idx = lower_bound(all(c), 0) - c.begin();
    if(k == 0) idx = 0;
    ll ans = 0, sum = 0;
    rep(i, idx, n) {
        ans += c[i] * (i - idx);
        sum += c[i];
    }
    if(k == 0) {
        cout << ans << '\n';
        return 0;
    }
    vector<ll> a(n + 1), b(n + 1);
    rep(i, 0, n + 1) {
        a[i] = i;
        b[i] = i / k;
    }
    ll A = LLONG_MIN;
    int L = 0, R = n;
    while(R - L > 3) {
        int m1 = L + (R - L) / 3;
        int m2 = L + 2 * (R - L) / 3;
        auto pa1 = check(m1, sum, a, b, c, idx);
        auto pa2 = check(m2, sum, a, b, c, idx);
        if(!pa2.first || pa1.second >= pa2.second) {
            R = m2;
        }else {
            L = m1;
        }
    }
    rep(i, L, R + 1) {
        auto pa = check(i, sum, a, b, c, idx);
        if(pa.first) A = max(A, pa.second + ans);
    }
    cout << A << '\n';
}