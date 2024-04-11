#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long
    using ll = long long;

    template<typename T>
    inline bool whitespace(const vector<T> &) { return false; }

    template<typename T>
    inline bool whitespace(const T &) { return true; }

    inline bool whitespace(const char) { return false; }

    template<typename F, typename S>
    inline bool whitespace(const pair<F, S> &) { return false; }

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n";
        return os;
    }

    template<typename F, typename S>
    istream &operator>>(istream &is, pair<F, S> &p) {
        is >> p.first >> p.second;
        return is;
    }

    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
        os << "\n";
        return os;
    }

    template<typename T>
    istream &operator>>(istream &is, deque<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const deque<T> &v) {
        for (const T &t : v) {
            os << t << (whitespace(t) ? " " : "");
        }
        os << "\n";
        return os;
    }

    class exit_exception : exception {
    };

    void answer() {}

    template<typename First, typename... Args>
    void answer(First &&val, Args &&... ans) {
        cout << val << "\n";
        answer(ans...);
        throw exit_exception();
    }

    struct autoint {
        int x;

        autoint(int i) : x(i) {}

        autoint() : x(0) { cin >> x; }

        operator int() { return x; }                                               //NOLINT
        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };   //NOLINT
    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            T mod = a % b;
            a = b;
            b = mod;
        }
        return a;
    }

    template<typename T>
    vector<T> prefix_sum(const vector<T> &v, int from = 0) {
        vector<T> res(v.size() + 1 - from);
        res[0] = 0;
        for (int i = from; i < v.size(); ++i) res[i + 1 - from] = res[i - from] + v[i];
        return res;
    }
}

void solve();

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

struct mod_int{
    static const int MOD = 998244353;
    int value;
    mod_int(int i = 0) : value(i % MOD) {} //NOLINT
    mod_int operator+(mod_int m) const { return (value + m.value) % MOD;}
    mod_int operator+(int i) const { return (value + i) % MOD;}
    mod_int operator+=(mod_int m) { value += m.value; return value %= MOD;}
    mod_int operator-(mod_int m) const {return (value - m.value + MOD) % MOD;}
    mod_int operator-(int i) const {return ((value - i) % MOD + MOD) % MOD;}
    mod_int operator-=(mod_int m) {value -= (m.value - MOD); return value %= MOD;}
    mod_int operator*(mod_int m) const {return (value * m.value) % MOD;}
    mod_int operator*(int i) const {return (value * i) % MOD;}
    mod_int operator*=(mod_int m) {value *= m.value; return value %= MOD;}
    mod_int power(int exp) {if (exp == 0) return 1; mod_int res = (exp & 1 ? value : 1); mod_int half = power(exp >> 1); return res * half * half; }
    mod_int operator /(mod_int m) const { return *this * m.power(MOD - 2); }
    mod_int operator /(int i) const { return *this / mod_int(i); }
    mod_int operator /=(mod_int m) { return *this *= m.power(MOD - 2); }
    friend std::istream &operator>> (std::istream &is, mod_int &m) { is >> m.value; return is; }
    friend std::ostream &operator<< (std::ostream &os, const mod_int &m) { os << m.value; return os; }
    operator int(){ return value; }  //NOLINT
};
vector<mod_int> fact;

mod_int C(mod_int n, mod_int k) {
    if (k < 0 || n < k) return 0;
    return fact[n] / fact[k] / fact[n - k];
}

#define l first
#define r second
using segment = pair<int, int>;

void set_comp(const vector<vector<int>> &g, vector<int> &comp, int cur, int c) {
    if (comp[cur] == c) return;
    comp[cur] = c;
    for (int next : g[cur]) set_comp(g, comp, next, c);
}

void solve() {
    autoint n, m;
    fact.assign(n + 1, 1);
    for (int i = 2; i < fact.size(); ++i) fact[i] = fact[i - 1] * i;
    vector<segment> s(n);
    cin >> s;
    vector<vector<int>> haters(n);
    for (int j = 0; j < m; ++j) {
        autoint a, b;
        --a, --b;
        haters[a].push_back(b);
        haters[b].push_back(a);
    }
    vector<int> comp(n, -1);
    int c = 0;
    for (int i = 0; i < n; ++i) if (comp[i] == -1) set_comp(haters, comp, i, c++);
    vector<vector<int>> r(c);
    for (int i = 0; i < n; ++i) r[comp[i]].push_back(i);
    vector<int> count(n + 2);
    vector<vector<vector<int>>> big_count;
    for (int i = 0; i < c; ++i) {
        if (r[i].size() == 1) {
            count[s[r[i][0]].l]++;
            count[s[r[i][0]].r + 1]--;
        } else {
            big_count.emplace_back(r[i].size() + 1, vector<int>(n + 2));
            for (int mask = 1; mask < (1 << r[i].size()); ++mask) {
                int low = 0, high = n, cnt = 0;
                for (int p = 0; p < r[i].size(); ++p) {
                    if ((mask >> p) & 1) {
                        cnt++;
                        low = max(low, s[r[i][p]].l);
                        high = min(high, s[r[i][p]].r);
                        for (int bit = 0; bit < r[i].size(); ++bit)
                            if (((mask >> bit) & 1) && find(haters[r[i][p]].begin(), haters[r[i][p]].end(), r[i][bit]) != haters[r[i][p]].end())
                                low = n + 1;
                    }
                }
                if (low <= high) {
                    big_count.back()[cnt][low]++;
                    big_count.back()[cnt][high + 1]--;
                }
            }
            for (int cnt = 0; cnt <= r[i].size(); ++cnt){
                for (int i = 1; i <= n + 1; ++i) big_count.back()[cnt][i] += big_count.back()[cnt][i - 1];
            }
        }
    }
    for (int i = 1; i <= n + 1; ++i) {
        count[i] += count[i - 1];
    }
    mod_int ans = 0;
    for (int amount = 1; amount <= n; ++amount) {
        vector<mod_int> counts(2 * m + 1);
        counts[0] = 1;
        for (auto &g : big_count){
            vector<mod_int> tmp = counts;
            for (int cnt = 0; cnt < g.size(); ++cnt){
                for (int cur = 0; cur + cnt <= 2 * m; ++cur){
                    counts[cur + cnt] += tmp[cur] * g[cnt][amount];
                }
            }
        }
        for (int t = 0; t < counts.size(); ++t){
            ans += counts[t] * C(count[amount], amount - t);
        }
    }
    answer(ans);
}