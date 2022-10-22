#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

ll gcd(ll x, ll y) {
    return !x ? y : gcd(y % x, x);
}

struct Stack {
    vector<pll> st;

    void push(ll x) {
        ll g = st.empty() ? 0ll : st.back().second;
        g = gcd(g, x);
        st.emplace_back(x, g);
    }

    ll pop() {
        ll res = st.back().first;
        st.pop_back();
        return res;
    }
    
    bool empty() {
        return st.empty();
    }

    ll query() {
        return st.empty() ? 0ll : st.back().second;
    }
};

struct Queue {
    Stack L, R;

    Queue() = default;

    void push(ll x) {
        R.push(x);
    }

    void pop() {
        if (L.empty()) while (!R.empty()) L.push(R.pop());
        L.pop();
    }

    ll query() {
        return gcd(L.query(), R.query());
    }
};

int fast(int n, vector<ll> a) {
    int res = 1;
    Queue q;
    for (int l = 1, r = 1; r <= n; r++) {
        if (r > l) q.push(abs(a[r] - a[r - 1]));
        while (l < r && q.query() == 1) q.pop(), l++;
        res = max(res, r - l + 1);
    }
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int res = fast(n, a);
        cout << res << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}