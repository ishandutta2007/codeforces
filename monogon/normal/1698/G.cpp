
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

struct binmat {
    int n;
    vector<ll> a;
    binmat(int n) : n(n), a(n) {}
    void eye() {
        rep(i, 0, n) {
            a[i] = (1ll << i);
        }
    }
    void set(int i, int j, bool b) {
        if((a[i] >> j & 1) != b) {
            a[i] ^= (1ll << j);
        }
    }
    bool get(int i, int j) const {
        return a[i] >> j & 1;
    }
    binmat transpose() const {
        binmat B(n);
        rep(i, 0, n) rep(j, 0, n) {
            B.set(j, i, get(i, j));
        }
        return B;
    }
    ll operator*(ll vec) const {
        ll ans = 0;
        rep(i, 0, n) {
            bool b = 0;
            rep(k, 0, n) {
                b ^= get(i, k) && (vec >> k & 1);
            }
            if(b) ans ^= (1ll << i);
        }
        return ans;
    }
    binmat operator*(const binmat &o) const {
        assert(n == o.n);
        binmat B(n);
        binmat oT = o.transpose();
        rep(i, 0, n) {
            rep(j, 0, n) {
                B.set(i, j, __builtin_popcountll(a[i] & oT.a[j]) % 2);
            }
        }
        return B;
    }
    bool invert() {
        binmat R(n);
        R.eye();
        rep(i, 0, n) {
            int p = -1;
            rep(j, i, n) {
                if(get(j, i)) {
                    p = j;
                    break;
                }
            }
            if(p == -1) return false;
            swap(a[i], a[p]);
            swap(R.a[i], R.a[p]);
            rep(j, i + 1, n) {
                if(get(j, i)) {
                    a[j] ^= a[i];
                    R.a[j] ^= R.a[i];
                }
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            rep(j, 0, i) {
                if(get(j, i)) {
                    a[j] ^= a[i];
                    R.a[j] ^= R.a[i];
                }
            }
        }
        *this = R;
        return true;
    }
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int offset = 1;
    while(!s.empty() && s[0] == '0') {
        s.erase(s.begin());
        offset++;
    }
    while(!s.empty() && s.back() == '0') {
        s.pop_back();
    }
    if(s.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    int n = s.length() - 1;
    if(n <= 1) {
        cout << offset << ' ' << offset + 1 << '\n';
        return 0;
    }
    binmat B(n);
    rep(i, 1, n) {
        B.set(i, i - 1, 1);
    }
    rep(i, 0, n) {
        B.set(i, n - 1, s[i] == '1');
    }
    binmat Binv = B;
    Binv.invert();
    unordered_map<ll, int, custom_hash> fuck;

    ll ans = LLONG_MAX;
    ll vec = 1;
    rep(i, 0, 1 << (n / 2)) {
        if(fuck.count(vec) == 0) {
            fuck[vec] = i;
        }
        if(vec == 1 && i > 0) {
            ans = min(ans, (ll)i);
        }
        vec = Binv * vec;
    }

    rep(i, 0, n / 2) {
        B = B * B;
    }
    vec = 1;
    rep(i, 0, 1 << ((n + 1) / 2)) {
        if(fuck.count(vec)) {
            ll val = 1ll * fuck[vec] + i * (1ll << (n / 2));
            if(val != 0) {
                ans = min(ans, val);
            }
        }
        vec = B * vec;
    }
    cout << offset << ' ' << offset + ans << '\n';
}