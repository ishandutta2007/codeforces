/*
    author:  Maksim1744
    created: 10.06.2021 17:48:06
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

int calc(const string &s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i)
        cnt += (s.substr(i, 4) == "haha");
    return cnt;
}

struct str {
    ll cnt = 0;
    string pref, suf;

    str() {}
    str(const string &s) {
        cnt = calc(s);
        pref = s.substr(0, 3);
        suf = s.substr(max(0, (int)s.size() - 3), s.size());
    }
};

ostream &operator << (ostream &o, const str &s) {
    o << "[" << s.pref << " - " << s.suf << ", " << s.cnt << "]";
    return o;
}

str mrg(str a, str b) {
    str res;
    res.cnt = a.cnt + b.cnt + calc(a.suf + b.pref);
    res.pref = a.pref;
    res.suf = b.suf;
    if (res.pref.size() < 3) {
        res.pref += b.pref;
        if (res.pref.size() > 3)
            res.pref.resize(3);
    }
    if (res.suf.size() < 3) {
        res.suf = a.suf + b.suf;
        if (res.suf.size() > 3)
            res.suf = res.suf.substr(res.suf.size() - 3, res.suf.size());
    }
    return res;
}

void test_case(int test) {
    map<string, str> vars;
    int n;
    cin >> n;
    string last;
    for (int i = 0; i < n; ++i) {
        string n1, op;
        cin >> n1 >> op;
        last = n1;
        if (op == ":=") {
            string s;
            cin >> s;
            vars[n1] = str(s);
        } else {
            string n2, n3;
            cin >> n2 >> n3 >> n3;
            vars[n1] = mrg(vars[n2], vars[n3]);
        }
        show(vars);
    }
    cout << vars[last].cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}