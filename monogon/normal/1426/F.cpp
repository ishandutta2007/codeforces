
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    s = "$" + s;
    n++;
    vector<base> dpa(n), dpab(n), dpabc(n), dpaq(n), dpabq(n), dpabqq(n), dpabcq(n), dpabcqq(n), dpabcqqq(n), pow3(n);
    pow3[0] = 1;
    int k = 0;
    rep(i, 1, n) {
        dpa[i] = dpa[i - 1] + (s[i] == 'a');
        dpab[i] = dpab[i - 1] + (s[i] == 'b' ? dpa[i - 1] : 0);
        dpabc[i] = dpabc[i - 1] + (s[i] == 'c' ? dpab[i - 1] : 0);
        dpaq[i] = dpaq[i - 1] + (s[i] == '?');
        dpabq[i] = dpabq[i - 1] + (s[i] == 'b' ? dpaq[i - 1] : 0) + (s[i] == '?' ? dpa[i - 1] : 0);
        dpabqq[i] = dpabqq[i - 1] + (s[i] == '?' ? dpaq[i - 1] : 0);
        dpabcq[i] = dpabcq[i - 1] + (s[i] == 'c' ? dpabq[i - 1] : 0) + (s[i] == '?' ? dpab[i - 1] : 0);
        dpabcqq[i] = dpabcqq[i - 1] + (s[i] == 'c' ? dpabqq[i - 1] : 0) + (s[i] == '?' ? dpabq[i - 1] : 0);
        dpabcqqq[i] = dpabcqqq[i - 1] + (s[i] == '?' ? dpabqq[i - 1] : 0);
        pow3[i] = pow3[i - 1] * 3;
        k += (s[i] == '?');
    }
    n--;
    base ans = dpabc[n] * pow3[k];
    if(k > 0) ans += dpabcq[n] * pow3[k - 1];
    if(k > 1) ans += dpabcqq[n] * pow3[k - 2];
    if(k > 2) ans += dpabcqqq[n] * pow3[k - 3];
    cout << ans << '\n';
}