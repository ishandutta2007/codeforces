
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

// const int N = 3e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi h(n);
    vector<ll> b(n);
    rep(i, 0, n) {
        cin >> h[i];
    }
    rep(i, 0, n) {
        cin >> b[i];
    }
    vector<ll> dp(n, 0);
    stack<int> st;
    stack<ll> stdp, stmax;
    stmax.push(LLONG_MIN);
    rep(i, 0, n) {
        ll mx = LLONG_MIN;
        while(!st.empty() && h[st.top()] > h[i]) {
            st.pop();
            mx = max(mx, stdp.top());
            stdp.pop();
            stmax.pop();
        }
        stdp.push(max(mx, i == 0 ? 0 : dp[i - 1]));
        stmax.push(max(stmax.top(), stdp.top() + b[i]));
        dp[i] = stmax.top();
        st.push(i);
    }
    cout << dp[n - 1] << '\n';
}