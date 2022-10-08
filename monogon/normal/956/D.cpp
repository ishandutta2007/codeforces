
#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())

using namespace std;

const int bits = 16;
const long long base = (1LL << bits), len = 8;

struct bigint {
    unsigned long long a[len];
    bigint(long long x) {
        for(int i = 0; i < 4; i++) {
            a[i] = (x >> (i * bits)) & (base - 1);
        }
        for(int i = 4; i < len; i++) {
            a[i] = (x < 0 ? base - 1 : 0);
        }
    }
    bigint() {
        fill(a, a + len, 0);
    }
    bigint(const bigint &o) {
        for(int i = 0; i < len; i++) {
            a[i] = o.a[i];
        }
    }
    bigint operator~() const {
        bigint ret(*this);
        for(int i = 0; i < len; i++) {
            ret.a[i] = ((~(ret.a[i])) & (base - 1));
        }
        return ret;
    }
    bigint operator+(const bigint &o) const {
        unsigned long long carry = 0;
        bigint ret(0);
        for(int i = 0; i < len; i++) {
            unsigned long long x = carry + a[i] + o.a[i];
            ret.a[i] = (x & (base - 1));
            carry = (x >> bits);
        }
        return ret;
    }
    bigint &operator++() {
        return *this = *this + 1;
    }
    bigint operator++(int) {
        bigint tmp(*this);
        operator++();
        return tmp;
    }
    bigint &operator--() {
        return *this = *this - 1;
    }
    bigint operator--(int) {
        bigint tmp(*this);
        operator--();
        return tmp;
    }
    bigint &operator+=(const bigint &o) {
        return *this = *this + o;
    }
    bigint &operator-=(const bigint &o) {
        return *this = *this - o;
    }
    bigint operator-() const {
        return bigint(1) + ~(*this);
    }
    bigint operator-(const bigint &o) const {
        return (*this) + (-o);
    }
    bigint operator*(const bigint &o) const {
        bigint ret(0);
        unsigned long long carry = 0;
        for(int i = 0; i < len; i++) {
            unsigned long long sum = carry;
            for(int j = 0; j <= i; j++) {
                int k = i - j;
                sum += a[j] * o.a[k];
            }
            ret.a[i] = (sum & (base - 1));
            carry = (sum >> bits);
        }
        return ret;
    }
    bigint operator*=(const bigint &o) {
        return *this = *this * o;
    }
    bool neg() const {
        return (a[len - 1] >> (bits - 1)) & 1;
    }
    bigint abs() const {
        return neg() ? -(*this) : (*this);
    }
    bool operator==(const bigint &o) const {
        for(int i = 0; i < len; i++) {
            if(a[i] != o.a[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const bigint &o) const {
        return !(*this == o);
    }
    bool operator<(const bigint &o) const {
        bool b1 = neg(), b2 = o.neg();
        if(b1 != b2) return b1;
        if(b1 && b2) return (-o) < (-(*this));
        for(int i = len - 1; i >= 0; i--) {
            if(a[i] != o.a[i]) return a[i] < o.a[i];
        }
        return false;
    }
    bool operator<=(const bigint &o) const {
        return !(o < (*this));
    }
    bool operator>(const bigint &o) const {
        return o < *this;
    }
    bool operator>=(const bigint &o) const {
        return !(*this < o);
    }
    void put(int pos, int val) {
        int i = pos / bits;
        int j = pos % bits;
        if(((a[i] >> j) & 1) != (val & 1)) {
            a[i] ^= (1 << j);
        }
    }
    int get(int pos) const {
        int i = pos / bits;
        int j = pos % bits;
        return (a[i] >> j) & 1;
    }
    bigint operator<<(int shift) const {
        bigint ans(0);
        for(int i = shift; i < bits * len; i++) {
            ans.put(i, get(i - shift));
        }
        return ans;
    }
    pair<bigint, bigint> div(const bigint &o) const {
        bool b1 = neg(), b2 = o.neg();
        bigint Q = 0, R = 0;
        if(b1 || b2) {
            tie(Q, R) = abs().div(o.abs());
            if(b1 != b2) {
                if(R == 0) {
                    return {-Q, 0};
                }else {
                    return {-Q, -R + o.abs()};
                }
            }else {
                return {Q, R};
            }
        }
        if(o == 0) {
            throw runtime_error("division by zero error");
        }
        for(int i = bits * len - 1; i >= 0; i--) {
            R = (R << 1);
            R.put(0, get(i));
            if(o <= R) {
                R = R - o;
                Q.put(i, 1);
            }
        }
        return {Q, R};
    }
    bigint operator/(const bigint &o) const {
        return div(o).first;
    }
    bigint operator/=(const bigint &o) {
        return *this = *this / o;
    }
    bigint operator%(const bigint &o) const {
        return div(o).second;
    }
    bigint operator%=(const bigint &o) {
        return *this = *this % o;
    }
    bigint operator&(const bigint &o) const {
        bigint ans(0);
        for(int i = 0; i < len; i++) {
            ans.a[i] = a[i] & o.a[i];
        }
        return ans;
    }
    bigint operator&=(const bigint &o) {
        return *this = (*this & o);
    }
    bigint operator|(const bigint &o) const {
        bigint ans(0);
        for(int i = 0; i < len; i++) {
            ans.a[i] = a[i] | o.a[i];
        }
        return ans;
    }
    bigint operator|=(const bigint &o) {
        return *this = (*this | o);
    }
    bigint operator^(const bigint &o) const {
        bigint ans(0);
        for(int i = 0; i < len; i++) {
            ans.a[i] = a[i] ^ o.a[i];
        }
        return ans;
    }
    bigint operator^=(const bigint &o) {
        return *this = (*this ^ o);
    }
    int popcount() const {
        int ans = 0;
        for(int i = 0; i < len; i++) {
            ans += __builtin_popcount(a[i]);
        }
        return ans;
    }
    string toString() const {
        if(neg()) return "-" + (-(*this)).toString();
        if((*this) == 0) return "0";
        string s = "";
        bigint N = *this;
        bigint Q = 0, R = 0;
        while(bigint(0) < N) {
            tie(Q, R) = N.div(10);
            N = Q;
            s.push_back('0' + R.a[0]);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

struct frac {
    bigint a, b;
    frac(bigint A = 0, bigint B = 1) {
        a = A; b = B;
        if(b < 0) {
            a = -a;
            b = -b;
        }/*
        ll g = gcd(abs(a), b);
        a /= g;
        b /= g;*/
    }
    frac operator+(const frac &o) const {
        return frac(a * o.b + b * o.a, b * o.b);
    }
    bool operator<(const frac &o) const {
        return a * o.b < o.a * b;
    }
    bool operator<=(const frac &o) const {
        return a * o.b <= o.a * b;
    }
};

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<frac, null_type, less_equal<frac>, rb_tree_tag, tree_order_statistics_node_update> ord;

int n;
ll w;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> w;
    ll ans = 0;
    vector<pair<frac, frac>> ve;
    rep(i, 0, n) {
        ll x, v;
        cin >> x >> v;
        ve.emplace_back(frac(x, w + v), frac(x, w - v));
    }
    sort(all(ve));
    ord s;
    for(auto &pa : ve) {
        frac F = pa.second;
        ans += s.order_of_key(F + frac(1, 1e18));
        s.insert(F);
    }
    cout << ans << '\n';
}