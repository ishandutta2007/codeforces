
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

template<int m>
struct mod {
    long long x;
    mod() : x(0) {}
    mod(long long xx) : x(xx) {
        if(abs(x) >= m) x %= m;
        if(x < 0) x += m;
    }
    mod operator+(const mod &a) const {
        mod n;
        n.x = x + a.x;
        if(n.x >= m) n.x -= m;
        return n;
    }
    mod operator-(const mod &a) const {
        mod n;
        n.x = x - a.x;
        if(n.x < 0) n.x += m;
        return n;
    }
    mod operator*(const mod &a) const {
        return x * a.x;
    }
    mod operator+=(const mod &a) {
        x += a.x;
        if(x >= m) x -= m;
        return *this;
    }
    mod operator-=(const mod &a) {
        x -= a.x;
        if(x < 0) x += m;
        return *this;
    }
    mod operator*=(const mod &a) {
        x = (x * a.x) % m;
        return *this;
    }
    mod pow(long long b) const {
        mod ans = 1;
        mod a = *this;
        while(b > 0) {
            if(b & 1) ans *= a;
            a *= a;
            b /= 2;
        }
        return ans;
    }
    mod inv() const {
        return pow(m - 2);
    }
    mod operator/(const mod &a) const {
        return (*this) * a.inv();
    }
    mod operator/=(const mod &a) {
        return (*this) *= a.inv();
    }
    bool operator==(const mod &o) const {
        return x == o.x;
    }
    bool operator!=(const mod &o) const {
        return x != o.x;
    }
    long long operator()() const {
        return x;
    }
};

template<int m>
istream &operator>>(istream &is, mod<m> &n) {
    long long x;
    is >> x;
    n = x;
    return is;
}

template<int m>
ostream &operator<<(ostream &os, const mod<m> &n) {
    return os << n();
}

const int M = 1e9 + 7;
using base = mod<M>;

map<string, int> ma;
vector<base> dp(60);

int k;

struct node {
    int col = -1;
    node *left = NULL, *right = NULL;
    node() {}
    node(int col) : col(col) {}
};

int lg(ll x) {
    return 63 - __builtin_clzll(x);
}

void add(node *r, ll i, ll idx, int c, int layer = k) {
    if(i == idx) {
        r->col = c;
        return;
    }
    if((~idx >> (lg(idx) + layer - k - 1)) & 1) {
        if(r->left == NULL) r->left = new node;
        add(r->left, 2 * i, idx, c, layer - 1);
    }else {
        if(r->right == NULL) r->right = new node;
        add(r->right, 2 * i + 1, idx, c, layer - 1);
    }
}

array<base, 3> solve(node *r, ll i, int layer = k) {
    array<base, 3> a = {0, 0, 0};
    if(r == NULL) {
        a[0] = a[1] = a[2] = dp[layer - 1] * 2;
        return a;
    }
    if(layer == 1) {
        if(r->col == -1) a[0] = a[1] = a[2] = 2;
        else a[r->col] = 1;
        return a;
    }
    auto b = solve(r->left, 2 * i, layer - 1);
    auto c = solve(r->right, 2 * i + 1, layer - 1);
    rep(i, 0, 3) {
        int ii = (i + 1) % 3;
        int iii = (i + 2) % 3;
        if(r->col != -1 && r->col != i) {
            a[i] = 0;
            continue;
        }
        a[i] = (b[ii] + b[iii]) * (c[ii] + c[iii]);
        if(r->col == -1) a[i] *= 2;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ma["white"] = ma["yellow"] = 0;
    ma["red"] = ma["orange"] = 1;
    ma["green"] = ma["blue"] = 2;
    cin >> k;
    dp[0] = 1;
    rep(i, 1, k) {
        dp[i] = dp[i - 1] * dp[i - 1] * 4 * 4;
    }
    int n; cin >> n;
    node *root = new node();
    rep(i, 0, n) {
        ll idx; string s;
        cin >> idx >> s;
        int c = ma[s];
        add(root, 1, idx, c);
    }
    auto a = solve(root, 1);
    cout << a[0] + a[1] + a[2] << '\n';
}