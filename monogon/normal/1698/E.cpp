
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

const int M = 998244353;
using base = mod<M>;

bool check1(vi &a, int s) {
    int n = sz(a);
    vi ainv(n);
    rep(i, 0, n) ainv[a[i]] = i;
    rep(i, 0, n) {
        if(a[i] > i + s) {
            return false;
        }
    }
    return true;
}

bool check2(vi a, int s) {
    int n = sz(a);
    vi ainv(n);
    rep(i, 0, n) ainv[a[i]] = i;
    rep(i, 0, n) {
        int j = ainv[i];
        if(a[i] < i || a[i] > i + s) {
            return false;
        }
        swap(ainv[a[i]], ainv[a[j]]);
        swap(a[i], a[j]);
    }
    rep(i, 0, n) assert(a[i] == i);
    return true;
}

void solve() {
    int n, s;
    cin >> n >> s;
    base ans = 1;
    vi a(n + 1), b(n + 1);
    vector<bool> vis(n + 1), vis2(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    rep(i, 1, n + 1) {
        cin >> b[i];
        if(b[i] != -1) {
            vis[a[i]] = true;
            vis2[b[i]] = true;
            if(b[i] < a[i] - s) {
                ans = 0;
            }
        }
    }
    int j = n;
    int cnt = 0;
    for(int i = n; i >= 1; i--) {
        while(j >= max(1, i - s)) {
            cnt += !vis2[j];
            j--;
        }
        if(!vis[i]) {
            ans *= cnt;
            cnt--;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int te;
    cin >> te;
    while(te--) solve();

    // int n;
    // cin >> n;
    // vi a(n);
    // rep(i, 0, n) a[i] = i;
    // do {
    //     if(check1(a) != check2(a)) {
    //         cout << "bad\n";
    //         rep(i, 0, n) {
    //             cout << a[i] << ' ';
    //         }
    //         cout << '\n';
    //         check2(a);
    //         return 0;
    //     }
    // }while(next_permutation(all(a)));
}