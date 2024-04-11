
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

const int N = 2e5 + 5;
int n;
ll T, t[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> T;
    int ans = 0;
    priority_queue<ll> Q;
    rep(i, 1, n + 1) {
        cin >> t[i];
        t[i] = max(0LL, t[i] - i);
        while(!Q.empty() && Q.top() > T - i) Q.pop();
        bool b = (!Q.empty() && Q.top() == T - i);
        Q.push(t[i]);
        while(!Q.empty() && Q.top() > T - i) Q.pop();
        int best = sz(Q);
        if(!Q.empty() && t[i] <= T - i && (b || t[i] == T - i)) best--;
        ans = max(ans, best);
    }
    cout << ans << '\n';
}