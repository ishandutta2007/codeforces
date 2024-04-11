
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

const int N = 3005, T = 1e6 + 5;
int n, k, t[N];
vector<ll> a[N];

struct update {
    bool type;
    int idx;
    update(int idx): idx(idx) {
        type = 0;
    }
};

struct sack {
    stack<array<ll, N>> st;
    sack() {
        array<ll, N> dp;
        fill(all(dp), -1);
        dp[0] = 0;
        st.push(dp);
    }
    void push(const update &u) {
        int idx = u.idx;
        array<ll, N> dp;
        rep(i, 0, N) dp[i] = st.top()[i];
        int s = min(k, t[idx]);
        ll val = a[idx][s];
        for(int i = N - 1; i >= s; i--) {
            if(dp[i - s] != -1 && dp[i - s] + val > dp[i]) {
                dp[i] = dp[i - s] + val;
            }
        }
        st.push(dp);
    }
    ll operator[](int i) {
        return st.top()[i];
    }
    void pop() {
        st.pop();
    }
};

template<typename D, typename U>
struct noam : public D {
    vector<U> s;
    void push(const U &u) {
        D::push(u);
        s.push_back(u);
    }
    void pop() {
        auto i = s.end();
        int c = 0;
        do {
            c += (--i)->type ? 1 : -1;
            D::pop();
        }while(c < 0 && i != s.begin());
        auto j = stable_partition(i, s.end(), [](auto &x) { return !x.type; });
        if(i == s.begin()) {
            reverse(i, j);
            for_each(i, j, [](auto &x) { x.type = 1; });
        }
        s.pop_back();
        while(i != s.end()) D::push(*i), i++;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 1, n + 1) {
        cin >> t[i];
        a[i].assign(t[i] + 1, 0);
        rep(j, 1, t[i] + 1) {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1];
        }
    }
    ll best = -1;
    noam<sack, update> Q;
    rep(i, 1, n + 1) {
        Q.push(i);
    }
    rep(i, 1, n + 1) {
        Q.pop();
        rep(j, 0, min(k, t[i]) + 1) {
            ll val = Q[k - j];
            if(val != -1) {
                best = max(best, a[i][j] + val);
            }
        }
        Q.push(i);
    }
    cout << best << '\n';
}