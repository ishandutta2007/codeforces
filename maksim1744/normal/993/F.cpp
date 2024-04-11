/*
    author:  Maksim1744
    created: 14.05.2021 21:16:39
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

using B = bitset<55>;

template<typename F>
void cliques(vector<B>& eds, F f, B P = ~B(), B X={}, B R={}) {
    if (!P.any()) { if (!X.any()) f(R); return; }
    auto q = (P | X)._Find_first();
    auto cands = P & ~eds[q];
    for (int i = 0; i < eds.size(); ++i) if (cands[i]) {
        R[i] = 1;
        cliques(eds, f, P & eds[i], X & eds[i], R);
        R[i] = P[i] = 0; X[i] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    struct func {
        vector<int> inputs;
        vector<int> values1;
        vector<int> values2;
        int op1, op2;
        string name;
    };
    vector<pair<string, pair<int, int>>> ops;
    for (int i = 0; i < m; ++i) {
        string name, s;
        cin >> name >> s;
        vector<int> tmp;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == 'x')
                tmp.pb(j);
        }
        assert(tmp.size() == 2);
        ops.eb(name, mp(tmp[0], tmp[1]));
    }

    auto eval_op1 = [&](const string &f, int v1, int v2) {
        if (f == "and") return (v1 && v2);
        else if (f == "nand") return !(v1 && v2);
        else if (f == "or") return (v1 || v2);
        else if (f == "nor") return !(v1 || v2);
        assert(false);
    };
    auto eval_op2 = [&](const string &f, int v1, int v2) {
        if (f == "nand") return (v1 && v2);
        else if (f == "and") return !(v1 && v2);
        else if (f == "nor") return (v1 || v2);
        else if (f == "or") return !(v1 || v2);
        assert(false);
    };

    vector<func> funcs;
    for (int i = 0; i < k; ++i) {
        string name, s;
        cin >> name >> s;
        vector<int> tmp;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == 'x')
                tmp.pb(j);
        }
        assert(tmp.size() == 2);
        func f;
        f.name = name;
        f.op1 = tmp[0];
        f.op2 = tmp[1];
        f.inputs.pb(ops[f.op1].second.first);
        f.inputs.pb(ops[f.op1].second.second);
        f.inputs.pb(ops[f.op2].second.first);
        f.inputs.pb(ops[f.op2].second.second);
        sort(f.inputs.begin(), f.inputs.end());
        f.inputs.erase(unique(f.inputs.begin(), f.inputs.end()), f.inputs.end());
        for (int m = 0; m < (1 << f.inputs.size()); ++m) {
            map<int, int> mm;
            for (int j = 0; j < f.inputs.size(); ++j) {
                mm[f.inputs[j]] = ((m >> j) & 1);
            }
            f.values1.push_back(eval_op1(name,
                eval_op1(ops[f.op1].first, mm[ops[f.op1].second.first], mm[ops[f.op1].second.second]),
                eval_op1(ops[f.op2].first, mm[ops[f.op2].second.first], mm[ops[f.op2].second.second])));
            f.values2.push_back(eval_op2(name,
                eval_op2(ops[f.op1].first, mm[ops[f.op1].second.first], mm[ops[f.op1].second.second]),
                eval_op2(ops[f.op2].first, mm[ops[f.op2].second.first], mm[ops[f.op2].second.second])));
        }
        bool ok = true;
        for (int i = 0; i < f.values1.size(); ++i) {
            if (f.values1[i] && f.values2[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        funcs.pb(f);
    }

    if (funcs.empty()) {
        cout << -1 << '\n';
        return 0;
    }

    int ans = 0;
    show(funcs.size());

    vector<vector<int>> g(funcs.size());

    for (int i = 0; i < funcs.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            auto f1 = funcs[i];
            auto f2 = funcs[j];
            vector<int> vars = f1.inputs;
            for (int k : f2.inputs)
                vars.pb(k);
            sort(vars.begin(), vars.end());
            vars.erase(unique(vars.begin(), vars.end()), vars.end());
            map<int, int> mm;
            for (int m = 0; m < (1 << vars.size()); ++m) {
                for (int k = 0; k < vars.size(); ++k) {
                    mm[vars[k]] = ((m >> k) & 1);
                }

                int v11 = (eval_op1(f1.name,
                    eval_op1(ops[f1.op1].first, mm[ops[f1.op1].second.first], mm[ops[f1.op1].second.second]),
                    eval_op1(ops[f1.op2].first, mm[ops[f1.op2].second.first], mm[ops[f1.op2].second.second])));
                int v12 = (eval_op2(f1.name,
                    eval_op2(ops[f1.op1].first, mm[ops[f1.op1].second.first], mm[ops[f1.op1].second.second]),
                    eval_op2(ops[f1.op2].first, mm[ops[f1.op2].second.first], mm[ops[f1.op2].second.second])));
                int v21 = (eval_op1(f2.name,
                    eval_op1(ops[f2.op1].first, mm[ops[f2.op1].second.first], mm[ops[f2.op1].second.second]),
                    eval_op1(ops[f2.op2].first, mm[ops[f2.op2].second.first], mm[ops[f2.op2].second.second])));
                int v22 = (eval_op2(f2.name,
                    eval_op2(ops[f2.op1].first, mm[ops[f2.op1].second.first], mm[ops[f2.op1].second.second]),
                    eval_op2(ops[f2.op2].first, mm[ops[f2.op2].second.first], mm[ops[f2.op2].second.second])));

                if ((v11 || v21) && (v12 || v22)) {
                    g[i].pb(j);
                    g[j].pb(i);
                    break;
                }
            }
        }
    }

    vector<B> eds(g.size());
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g.size(); ++j) {
            eds[i][j] = 1;
        }
        eds[i][i] = 0;
        for (int j : g[i])
            eds[i][j] = 0;
    }

    show(eds);
    show(g);

    auto f = [&](B m) {
        show(m);
        bool ok = true;
        for (int i = 0; i < funcs.size(); ++i) {
            for (int j : g[i]) {
                if (m[i] && m[j]) {
                    ok = false;
                }
            }
        }
        if (!ok) return;
        vector<int> vars;
        for (int i = 0; i < funcs.size(); ++i) {
            if (m[i]) {
                for (int k : funcs[i].inputs)
                    vars.pb(k);
            }
        }
        sort(vars.begin(), vars.end());
        vars.erase(unique(vars.begin(), vars.end()), vars.end());
        vector<int> vals(n);
        for (int i = 0; i < (1 << vars.size()); ++i) {
            for (int j = 0; j < vars.size(); ++j) {
                vals[vars[j]] = ((i >> j) & 1);
            }
            bool all0 = true;
            for (int j = 0; j < funcs.size(); ++j) {
                if (m[j] & 1) {
                    auto f = funcs[j];
                    int v11 = (eval_op1(f.name,
                        eval_op1(ops[f.op1].first, vals[ops[f.op1].second.first], vals[ops[f.op1].second.second]),
                        eval_op1(ops[f.op2].first, vals[ops[f.op2].second.first], vals[ops[f.op2].second.second])));
                    int v12 = (eval_op2(f.name,
                        eval_op2(ops[f.op1].first, vals[ops[f.op1].second.first], vals[ops[f.op1].second.second]),
                        eval_op2(ops[f.op2].first, vals[ops[f.op2].second.first], vals[ops[f.op2].second.second])));
                    if (v11 == 0 && v12 == 0) continue;
                    all0 = false;
                }
            }
            if (all0) {
                ok = false;
                break;
            }
        }
        if (!ok) return;
        ans = max(ans, (int)m.count());
    };
    cliques(eds, f);
    ans = k - ans;
    if (ans == k) ans = -1;
    cout << ans << endl;

    return 0;
}