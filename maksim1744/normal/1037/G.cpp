/*
    author:  Maksim1744
    created: 17.05.2021 19:03:01
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

struct hash_my {
    size_t operator()(int x) const {
        x = ((x >> 16) ^ x) * 0x119de1f3;
        x = ((x >> 16) ^ x) * 0x119de1f3;
        x = (x >> 16) ^ x;
        return x;
    }

    size_t operator()(long long x) const {
        x = (x ^ (x >> 30)) * (0xbf58476d1ce4e5b9ll);
        x = (x ^ (x >> 27)) * (0x94d049bb133111ebll);
        x = x ^ (x >> 31);
        return x;
    }

    template<typename T, typename U>
    size_t operator()(const pair<T, U> &p) const {
        long long h1 = (*this)(p.first);
        long long h2 = (*this)(p.second);
        return (*this)(h1 ^ (h2 << 32) ^ (h2 >> 32));
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;
    vector<vector<int>> next(n, vector<int>(26, n));
    vector<vector<int>> prev(n, vector<int>(26, -1));
    for (int i = 0; i < n; ++i) {
        if (i) prev[i] = prev[i - 1];
        prev[i][s[i] - 'a'] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (i != n - 1) next[i] = next[i + 1];
        next[i][s[i] - 'a'] = i;
    }
    vector<vector<int>> prec(26, vector<int>(n + 1));
    int ops = 0;
    s.pb('z' + 1);
    vector<vector<int>> mem(n, vector<int>(27, -1));
    auto mem2 = mem;
    vector<string> nextc(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            nextc[i].pb('a' + j);
        }
        sort(nextc[i].begin(), nextc[i].end(), [&](const char a, const char b) {
            return next[i][a - 'a'] < next[i][b - 'a'];
        });
    }
    int L = -1, R = -1;
    auto calc = y_combinator([&](auto calc, int l, int r, bool has_prec = true) -> int {
        ++ops;
        if (l > r) return 0;
        pair<int, int> p = {l, r};
        int cr = s[r + 1] - 'a';
        if (mem[l][cr] != -1 && (cr == 26 || next[l][cr] == r + 1)) return mem[l][cr];
        if (p.first == L && mem2[L][cr] != -1) return mem2[p.first][cr];
        int cl = 0;
        if (p.second == R) {
            if (l == 0) cl = 26;
            else cl = s[l - 1] - 'a';
            if (mem2[R][cl] != -1) return mem2[R][cl];
        }
        int st = 0;
        if (!has_prec) {
            for (char c = 'a'; c <= 'z'; ++c) {
                int last = l;
                int cur = 0;
                for (int i = l; i <= r; ++i) {
                    if (s[i] == c) {
                        ++ops;
                        cur ^= calc(last, i - 1, has_prec);
                        last = i + 1;
                    }
                }
                if (last == l) continue;
                cur ^= calc(last, r, has_prec);
                st |= (1 << cur);
            }
        } else {
            for (char c : nextc[l]) {
                int i1 = next[l][c - 'a'];
                if (i1 > r) break;
                int i2 = prev[r][c - 'a'];
                if (l == 0 || s[l - 1] == c) i1 = l - 1;
                if (r == n - 1 || s[r + 1] == c) i2 = r + 1;
                int cur = prec[c - 'a'][i2] ^ (i1 < 0 ? 0 : prec[c - 'a'][i1]);
                if (l <= i1 - 1)
                    cur ^= calc(l, i1 - 1, has_prec);
                if (i2 + 1 <= r)
                    cur ^= calc(i2 + 1, r, has_prec);
                st |= (1 << cur);
            }
        }
        int ans = 0;
        while ((st >> ans) & 1) ++ans;
        if (!has_prec)
            return mem[l][cr] = ans;
        else {
            if (p.first == L) {
                return mem2[L][cr] = ans;
            } else {
                assert(p.second == R);
                return mem2[R][cl] = ans;
            }
        }
    });
    for (int i = 1; i < n; ++i) {
        int ind = prev[i - 1][s[i] - 'a'];
        if (ind == -1) {
            prec[s[i] - 'a'][i] = calc(0, i - 1, false);
        } else {
            prec[s[i] - 'a'][i] = calc(ind + 1, i - 1, false) ^ prec[s[i] - 'a'][ind];
        }
    }
    for (int i = 0; i < 26; ++i) {
        int ind = prev.back()[i];
        if (ind == -1) {
            prec[i].back() = calc(0, n - 1, false);
        } else {
            prec[i].back() = calc(ind + 1, n - 1, false) ^ prec[i][ind];
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        L = l;
        R = r;
        int res = calc(l, r);
        if (res == 0) cout << "Bob\n";
        else cout << "Alice\n";
        mem2[l].assign(mem2[l].size(), -1);
        mem2[r].assign(mem2[r].size(), -1);
    }

    return 0;
}