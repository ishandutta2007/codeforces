/*
    author:  Maksim1744
    created: 09.06.2021 11:56:38
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

struct Node {
    bool end = false;
    map<char, Node*> to;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<string> res(n);
    cin >> res;
    set<string> ress(res.begin(), res.end());

    Node *root = new Node();
    for (string s : res) {
        auto node = root;
        for (char c : s) {
            if (!node->to.count(c))
                node->to[c] = new Node();
            node = node->to[c];
        }
        node->end = true;
    }

    int m;
    cin >> m;
    vector<string> tokens0;
    {
        string s;
        getline(cin, s);
        for (int it = 0; it < m; ++it) {
            getline(cin, s);
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '#') {
                    s.resize(i);
                    break;
                }
            }
            int last = 0;
            for (int i = 0; i <= s.size(); ++i) {
                if (i == s.size() || s[i] == ' ') {
                    if (last != i) {
                        tokens0.pb(s.substr(last, i - last));
                    }
                    last = i + 1;
                }
            }
        }
    }
    show(tokens0);
    vector<pair<string, int>> tokens;

    auto is_let = [&](char c) {
        if ('a' <= c && c <= 'z') return true;
        if ('A' <= c && c <= 'Z') return true;
        if ('0' <= c && c <= '9') return true;
        if (c == '$') return true;
        if (c == '_') return true;
        return false;
    };

    auto parse_tokens = [&](string s) {
        vector<pair<string, int>> tokens;
        int ind = 0;
        while (ind < s.size()) {
            int was = ind;
            auto node = root;
            int best_sz = 0;
            for (int i = ind; i < s.size(); ++i) {
                char c = s[i];
                if (!node->to.count(c)) break;
                node = node->to[c];
                if (node->end)
                    best_sz = i + 1 - ind;
            }
            string best_res = s.substr(ind, best_sz);
            // for (int i = 1; i <= s.size(); ++i)
            //     if (ress.count(s.substr(0, i)))
            //         best_res = s.substr(0, i);
            show(s, best_res, ind);
            if ('0' <= s[ind] && s[ind] <= '9') {
                int it = ind;
                while (it < s.size() && s[it] >= '0' && s[it] <= '9')
                    ++it;
                show(it);
                if (it - ind > best_res.size()) {
                    tokens.eb(s.substr(ind, it - ind), 1);
                    // s = s.substr(it, s.size());
                    ind = it;
                } else {
                    tokens.eb(best_res, 0);
                    // s = s.substr(best_res.size(), s.size());
                    ind += best_res.size();
                }
            } else {
                int it = ind;
                while (it < s.size() && is_let(s[it]))
                    ++it;
                show(it);
                if (it - ind > best_res.size()) {
                    tokens.eb(s.substr(ind, it - ind), 2);
                    // s = s.substr(it, s.size());
                    ind = it;
                } else {
                    tokens.eb(best_res, 0);
                    // s = s.substr(best_res.size(), s.size());
                    ind += best_res.size();
                }
            }
            if (ind <= was) {
                return mp(tokens, false);
            }
            //     cout << ind << ' ' << s << ' ' << endl;
            //     exit(0);
            // }
            // assert(ind > was);
        }
        return mp(tokens, true);
    };
    for (auto s : tokens0) {
        auto v = parse_tokens(s).first;
        for (auto p : v)
            tokens.pb(p);
    }

    set<pair<int, string>> avail_names;
    for (int ln = 1; ln <= 3; ++ln) {
        int cnt = 1;
        for (int i = 0; i < ln; ++i) {
            cnt *= 26;
        }
        for (int i = 0; i < cnt; ++i) {
            string t;
            int x = i;
            for (int j = 0; j < ln; ++j) {
                t.pb('a' + x % 26);
                x /= 26;
            }
            if (ress.count(t)) continue;
            avail_names.emplace(ln, t);
        }
    }

    map<string, string> names;

    for (auto &[s, tp] : tokens) {
        if (tp != 2) continue;
        if (!names.count(s)) {
            names[s] = avail_names.begin()->second;
            avail_names.erase(avail_names.begin());
        }
        s = names[s];
    }

    show(tokens);
    string curs;
    for (int i = 0; i < tokens.size(); ++i) {
        cout << tokens[i].first;
        curs += tokens[i].first;

        if (i + 1 < tokens.size()) {
            auto v1 = parse_tokens(curs).first;
            auto v2 = parse_tokens(tokens[i + 1].first).first;
            for (auto v : v2)
                v1.pb(v);
            auto [v3, res] = parse_tokens(curs + tokens[i + 1].first);
            if (!res || v1 != v3) {
                cout << ' ';
                curs.clear();
            }
        }
    }
    cout << '\n';

    return 0;
}