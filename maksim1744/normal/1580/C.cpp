/*
    author:  Maksim1744
    created: 30.09.2021 14:13:50
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
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v(n);
    cin >> v;

    map<int, int> ar;

    vector<int> pref(m + 1, 0);
    auto add_long = [&](int l, int r) {
        if (l > r) return;
        pref[l]++;
        pref[r + 1]--;
    };

    const int B = 300;
    vector<vector<vector<int>>> prefs(B + 1);
    for (int i = 1; i <= B; ++i) {
        prefs[i].resize(i);
        for (auto& v : prefs[i])
            v.reserve(m / i + 3);
        for (int j = 0; j < m; ++j)
            prefs[i][j % i].pb(0);
        for (auto& v : prefs[i])
            v.pb(0);
    }

    auto add_short = [&](int C, int rem, int l, int r) {
        if (l > r) return;
        show(C, rem, l, r);
        prefs[C][rem][l]++;
        prefs[C][rem][r + 1]--;
    };

    vector<int> total(m, 0);

    auto add_train = [&](int L, int R, int k) {
        int x = v[k].first;
        int y = v[k].second;
        show(L, R, x, y);
        if (x + y > B || (R - L + 1) / (x + y) < n / B) {
            for (int st = L; st <= R; st += x + y) {
                add_long(st + x, min(st + x + y - 1, R));
            }
        } else {
            int C = x + y;
            while ((R - L + 1) % C != 0) {
                int rem = (R - L) % C;
                if (rem >= x)
                    total[R]++;
                --R;
            }
            if (R < L) return;
            int count = (R - L + 1) / C;
            for (int rem = x; rem < C; ++rem) {
                int real_rem = (L + rem) % C;
                int il = (L + rem) / C;
                int ir = il + count - 1;
                add_short(C, real_rem, il, ir);
            }
        }
    };

    for (int i = 0; i < m; ++i) {
        int op, k;
        cin >> op >> k;
        --k;
        if (op == 1) {
            ar[k] = i;
        } else {
            add_train(ar[k], i - 1, k);
            ar.erase(k);
        }
    }
    for (auto [k, i] : ar) {
        add_train(i, m - 1, k);
    }

    auto make_prefs = [&](vector<int>& v) {
        for (int i = 1; i < v.size(); ++i)
            v[i] += v[i - 1];
    };
    make_prefs(pref);
    for (int i = 0; i < m; ++i)
        total[i] += pref[i];

    for (int i = 1; i < prefs.size(); ++i) {
        for (int j = 0; j < prefs[i].size(); ++j) {
            make_prefs(prefs[i][j]);
            for (int k = 0; k * i + j < m; ++k) {
                total[k * i + j] += prefs[i][j][k];
            }
        }
    }

    for (int k : total)
        cout << k << '\n';

    return 0;
}