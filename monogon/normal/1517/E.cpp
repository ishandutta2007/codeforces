
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

template<typename T>
struct bit {
    size_t n, lg;
    vector<T> a;
    bit(size_t n) : n(n) {
        a.assign(n, T());
        lg = 0;
        while(2 * (1u << lg) < n) lg++;
    }
    void add(size_t i, T x) {
        while(i < n) {
            a[i] = a[i] + x;
            i += i & -i;
        }
    }
    T get(size_t i) {
        T x = T();
        while(i > 0) {
            x = x + a[i];
            i -= i & -i;
        }
        return x;
    }
    size_t lower_bound(T val) {
        size_t i = 0;
        T sum = T();
        for(size_t k = lg; ; k--) {
            if(i + (1 << k) < n && sum + a[i + (1 << k)] < val) {
                i += (1 << k);
                sum = sum + a[i];
            }
            if(k == 0) return i + 1;
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1), pre(n + 1);
    ll sum = 0;
    rep(i, 1, n + 1) {
        cin >> a[i];
        sum += a[i];
        pre[i] = a[i] + pre[i - 1];
    }
    base cnt = 0;
    rep(i, 1, n + 1) {
        cnt += (pre[i] > sum - pre[i]);
    }

    ll pref = 0;
    vector<pair<ll, int>> A, B;
    rep(i, 1, n) {
        A.push_back({pref - pre[i - 1], i});
        if(i > 1) {
            A.push_back({pref - pre[i - 1] + a[1] * 2, i});
        }
        pref = -a[i] - pref;
    }
    pref = 0;
    rep(i, 1, n) {
        B.push_back({pref + pre[n] - pre[i] - a[i], i});
        if(i < n - 1) {
            B.push_back({pref + pre[n - 1] - pre[i] - a[i] - a[n], i});
        }
        pref = a[i] - pref;
    }
    vector<pair<ll, int>> Ae, Ao, Be, Bo;
    for(auto &pa : A) {
        (pa.second % 2 == 0 ? Ae : Ao).push_back({-pa.first, pa.second});
    }
    for(auto &pb : B) {
        (pb.second % 2 == 0 ? Be : Bo).push_back(pb);
    }

    auto da = [&](const vector<pair<ll, int>> &A, const vector<pair<ll, int>> &B) {
        vector<tuple<ll, int, int>> ve;
        for(auto &pa : A) {
            ve.push_back({pa.first, 1, pa.second});
        }
        for(auto &pb : B){ 
            ve.push_back({pb.first, 0, pb.second});
        }
        sort(all(ve));
        bit<int> D(n + 1);
        for(auto &T : ve) {
            ll x; int idx; int ty;
            tie(x, ty, idx) = T;
            if(ty == 0) {
                // B
                cnt += D.get(idx);
            }else {
                // A
                D.add(idx, 1);
            }
        }
        // for(auto &pa : A) {
        //     for(auto &pb : B) {
        //         if(pa.second <= pb.second && pa.first + pb.first > 0) {
        //             cnt += 1;
        //         }
        //     }
        // }
    };

    da(Ae, Be);
    da(Ao, Bo);

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}