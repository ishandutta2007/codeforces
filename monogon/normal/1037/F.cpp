
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

const int N = 1e6 + 5, M = 1e9 + 7;
int n;
ll k;
ll a[N];
ll le[N], ri[N];

ll func(ll L, ll R, ll k) {
    ll A = L / k, B = R / k;
    ll a = L % k, b = R % k;
    return (((A * B) % M) * k + max(0LL, a + b - k + 1) + ((a + 1) * B) % M + (A * (b + 1)) % M) % M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> a[i];
    }
    stack<int> st;
    rep(i, 0, n) {
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        le[i] = (st.empty() ? i : i - st.top() - 1);
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        ri[i] = (st.empty() ? n - i - 1 : st.top() - i - 1);
        st.push(i);
    }
    ll ans = 0;
    rep(i, 0, n) {
        ll x = func(le[i], ri[i], k - 1);
        ans = (ans + a[i] * x) % M;
    }
    cout << ans << '\n';
}