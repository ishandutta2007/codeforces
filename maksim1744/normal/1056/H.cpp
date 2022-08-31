/*
    author:  Maksim1744
    created: 07.06.2021 11:15:46
*/

#include "bits/stdc++.h"

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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

const uint32_t p = 1e9 + 7;

void test_case(int test) {
    int n;
    cin >> n;
    int q;
    cin >> q;
    const int B = 400;
    vector<vector<int>> paths(q);
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        paths[i].resize(k);
        cin >> paths[i];
        --paths[i];
    }
    vector<gp_hash_table<int, uint32_t>> has(n);
    vector<int> u(n, -1);
    int ustep = 0;
    vector<int> ord(n);
    for (int i = 0; i < q; ++i) {
        if (paths[i].size() <= B) {
            for (int j = 0; j < paths[i].size(); ++j) {
                int s = paths[i][j];
                uint32_t cur = s;
                for (int k = j + 1; k < paths[i].size(); ++k) {
                    int t = paths[i][k];
                    cur = cur * p + t;
                    auto it = has[s].find(t);
                    if (it == has[s].end()) {
                        has[s][t] = cur;
                    } else if (it->second != cur) {
                        cout << "Human\n";
                        return;
                    }
                }
            }
        } else {
            ++ustep;
            for (int k = 0; k < paths[i].size(); ++k) {
                u[paths[i][k]] = ustep;
                ord[paths[i][k]] = k;
            }
            for (int j = 0; j < q; ++j) {
                if (j < i && paths[j].size() > B) continue;
                int last = 1e9;
                for (int v : paths[j]) {
                    if (u[v] != ustep) continue;
                    if (ord[v] > last + 1) {
                        cout << "Human\n";
                        return;
                    }
                    last = ord[v];
                }
            }
        }
    }
    cout << "Robot\n";
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