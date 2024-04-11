/*
    author:  Maksim1744
    created: 16.11.2021 03:12:03
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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

namespace small_vec_ns {

template<typename T, int N>
struct small_vec {
    array<T, N> data;
    int size_ = 0;

    small_vec(int n = 0, const T& value = T()) : size_(n) {
        fill(data.begin(), data.begin() + n, value);
    }
    template<typename It>
    small_vec(It begin, It end) {
        while (begin != end) data[size_++] = *(begin++);
    }
    small_vec(const std::initializer_list<T>& list) : small_vec(list.begin(), list.end()) {}

    void assign(int n, const T& value) {
        size_ = n;
        for (int i = 0; i < n; ++i) data[i] = value;
    }
    void resize(int n, const T& value = T()) {
        if (n > size_) fill(data.begin() + size_, data.begin() + n, value);
        size_ = n;
    }

    int  size () const { return size_;      }
    bool empty() const { return size_ == 0; }

    auto begin () const { return data.begin();         }
    auto end   () const { return data.begin() + size_; }
    auto begin ()       { return data.begin();         }
    auto end   ()       { return data.begin() + size_; }
    auto rbegin() const { return data.rend () - size_; }
    auto rend  () const { return data.rend ();         }
    auto rbegin()       { return data.rend () - size_; }
    auto rend  ()       { return data.rend ();         }

    void push_back(const T&  value) { data[size_++] = value; }
    void push_back(      T&& value) { data[size_++] = std::move(value); }
    template<typename... Args> void emplace_back(Args&&... args) { data[size_++] = T(args...);; }
    void pop_back() { --size_; }

    template<typename It>
    void insert(It pos, T value) {
        while (pos <= end()) { swap(*(pos++), value); }
        ++size_;
    }
    template<typename It>
    void erase(It pos) {
        while (next(pos) < end()) { auto nx = next(pos); swap(*(pos++), *nx); }
        --size_;
    }

          T& operator[] (int i)       { return data[i]; }
    const T& operator[] (int i) const { return data[i]; }

          T& front()       { return data[0];         }
          T& back ()       { return data[size_ - 1]; }
    const T& front() const { return data[0];         }
    const T& back () const { return data[size_ - 1]; }

    bool operator < (const small_vec<T, N>& other) const {
        for (int i = 0; i < min(size_, other.size_); ++i)
            if (data[i] != other.data[i])
                return data[i] < other.data[i];
        return size_ < other.size_;
    }
    bool operator >  (const small_vec<T, N>& other) const { return other < *this; }
    bool operator <= (const small_vec<T, N>& other) const { return !(other < *this); }
    bool operator >= (const small_vec<T, N>& other) const { return !(*this < other); }
    bool operator == (const small_vec<T, N>& other) const {
        if (size_ != other.size_) return false;
        for (int i = 0; i < size_; ++i)
            if (data[i] != other.data[i])
                return false;
        return true;
    }
    bool operator != (const small_vec<T, N>& other) const { return !(*this == other); }

    vector<T> to_vector() const { return vector<T>(begin(), end()); }
};

template<typename T, int N> string _to_string_(const small_vec<T, N>& v) { return _to_string_(v.to_vector()); }
}
using namespace small_vec_ns;

using state_t = small_vec<char, 10>;
// using state_t = vector<int>;

void test_case(int test) {
    int n;
    cin >> n;
    vector<string> v(n);
    cin >> v;

    map<char, vector<vector<int>>> where;
    for (int i = 0; i < 26; ++i) {
        where['a' + i].resize(n);
        where['A' + i].resize(n);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            where[v[i][j]][i].pb(j);
        }
    }

    vector<state_t> states;
    for (auto& [c, v] : where) {
        int cnt = 1;
        for (auto& x : v)
            cnt *= x.size();
        for (int it = 0; it < cnt; ++it) {
            int x = it;
            state_t cur;
            for (auto& vv : v) {
                cur.pb(vv[x % vv.size()]);
                x /= vv.size();
            }
            states.pb(cur);
        }
    }

    sort(states.begin(), states.end());

    map<state_t, state_t> par;
    map<state_t, int> ans;

    for (auto& state : states) {
        int& cur = ans[state];
        auto& p = par[state];
        for (const auto& [c, w] : where) {
            if (c == v[0][state[0]]) {
                for (int i = 0; i < n; ++i) {
                    if (w[i][0] != state[i]) {
                        state[i] = w[i][0];
                        int aans = ans[state];
                        if (aans > cur) {
                            cur = max(cur, aans);
                            p = state;
                        }
                        state[i] = w[i][1];
                    }
                }
            }

            state_t last(n);
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                int ind = (int)w[i].size() - 1;
                while (ind >= 0 && w[i][ind] >= state[i])
                    --ind;
                if (ind < 0) {
                    ok = false;
                    break;
                }
                last[i] = w[i][ind];
            }
            if (ok) {
                int prev = ans[last];
                if (prev + 1 > cur) {
                    cur = prev + 1;
                    p = last;
                }
            }
        }
    }

    int mx = -1;
    state_t best;
    for (const auto& [state, res] : ans) {
        if (res > mx) {
            mx = res;
            best = state;
        }
    }
    ++mx;

    show(par);
    show(ans);

    vector<state_t> path;
    while (!best.empty()) {
        path.pb(best);
        best = par[best];
    }
    show(path);
    reverse(path.begin(), path.end());
    string s;
    for (int i = 0; i < path.size(); ++i)
        if (i + 1 == path.size() || ans[path[i]] != ans[path[i + 1]])
            s.pb(v[0][path[i][0]]);

    cout << mx << '\n';
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}