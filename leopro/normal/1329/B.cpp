#include <bits/stdc++.h>

//@formatter:off
namespace {
    using namespace std;
#define int long long
    template<typename T>inline bool whitespace(const vector<T> &) { return false; }
    template<typename T>inline bool whitespace(const T &) { return true; }
    inline bool whitespace(const char) { return false; }
    template<typename S, typename T>ostream &operator<<(ostream &os, const pair<S, T> &p){ os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n"; return os;}
    template<typename S, typename T>istream &operator>>(istream &is, pair<S, T> &p){ is >> p.first >> p.second; return is;}
    template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>istream &operator>>(istream &is, deque<T> &v) { for (T &t : v) is >> t; return is; }
    template<typename T>ostream &operator<<(ostream &os, const deque<T> &v) { for (const T &t : v) {os << t << (whitespace(t) ? " " : ""); } os << "\n"; return os; }
    template<typename T>T gcd(T a, T b) { while (b) { T mod = a % b; a = b; b = mod; } return a; }
    template<typename T>T sum(const vector<T> &v) { T s = 0; for (T value : v) s += value; return s; }
    template<typename T>vector<T> prefix_sum(const vector<T> &v) { vector<T> res(v.size()+1); res[0] = 0; for (int i = 0; i < v.size(); ++i) res[i+1] = res[i] + v[i]; return res; }
    template<typename S, typename T>S min(S a, T b){return a < (S)b ? a : b; }
    template<typename S, typename T>S max(S a, T b){return a < (S)b ? b : a; }
    class exit_exception : exception {};
    istream &in = cin; ostream &out = cout;
    template<typename T>void answer(T ans){out << ans << "\n"; throw exit_exception();}
    struct autoint{int x; autoint(){in >> x;} operator int(){return x;} autoint(autoint &i){x = i.x;}
        int operator--(){return --x;} int operator--(signed){return x--;} int operator ++(){return ++x;} int operator++(signed){return x++;} };
    template<typename T> struct autoread : T{template<typename... Args>autoread(Args&&... args): T(args...){ in >> *dynamic_cast<T *>(this);} };
}
//@formatter:on

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}
struct mod_int{
    static int MOD;
    int value;
    mod_int(int i = 0) : value(i % MOD) {} //NOLINT
    mod_int operator+(mod_int m) const { return (value + m.value) % MOD;}
    mod_int operator+=(mod_int m) { value += m.value; return value %= MOD;}
    mod_int operator-(mod_int m) const {return (value - m.value + MOD) % MOD;}
    mod_int operator-=(mod_int m) {value -= (m.value - MOD); return value %= MOD;}
    mod_int operator*(mod_int m) const {return (value * m.value) % MOD;}
    mod_int operator*=(mod_int m) {value *= m.value; return value %= MOD;}
    mod_int power(int exp) {if (exp == 0) return 1; mod_int res = (exp & 1 ? value : 1); mod_int half = power(exp >> 1); return res * half * half; }
    mod_int operator /(mod_int m) const { return *this * m.power(MOD - 2); }
    mod_int operator /=(mod_int m) { return *this *= m.power(MOD - 2); }
    friend std::istream &operator>> (std::istream &is, mod_int &m) { is >> m.value; return is; }
    friend std::ostream &operator<< (std::ostream &os, const mod_int &m) { os << m.value; return os; }
    operator int(){ return value; }  //NOLINT
};

int mod_int::MOD = 0;

int log(int x){
    int ans = 0;
    while (x /= 2) ans++;
    return ans;
}

void solve() {
    int d;
    cin >> d >> mod_int::MOD;
    mod_int ans = 1;
    vector<mod_int> dp(log(d) + 1);
    dp[log(d)] = d - (1ull << log(d)) + 1;
    for (int i = log(d) - 1; i >= 0; --i){
        mod_int cur = (1ull << (i + 1)) - (1ull << i);
        for (int j = i + 1; j < dp.size(); ++j) dp[i] += cur*dp[j];
        dp[i] +=cur;
    }
    cout << accumulate(dp.begin(), dp.end(), mod_int()) << "\n";
}