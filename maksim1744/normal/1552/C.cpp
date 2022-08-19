/*
    author:  Maksim1744
    created: 25.07.2021 17:43:33
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

void test_case(int test) {
    int n, k;
    cin >> n >> k;
    set<int> s;
    for (int i = 0; i < n * 2; ++i) {
        s.insert(i + 1);
    }
    vector<pair<int, int>> lines;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        lines.eb(a, b);
        s.erase(a);
        s.erase(b);
    }
    vector<int> v(s.begin(), s.end());
    for (int i = 0; i < v.size() / 2; ++i) {
        lines.eb(v[i], v[i + v.size() / 2]);
    }

    auto inter = [&](pair<int, int> a, pair<int, int> b) {
        show(a, b);
        if (a.second < a.first) swap(a.first, a.second);
        if (b.second < b.first) swap(b.first, b.second);
        show(a, b);
        if (a.second < b.first) return false;
        show(a, b);
        if (a.first > b.second) return false;
        show(a, b);
        if (a.first < b.first && b.second < a.second) return false;
        show(a, b);
        if (b.first < a.first && a.second < b.second) return false;
        show(a, b);
        return true;
    };

    int ans = 0;
    for (int i = 0; i < lines.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            ans += inter(lines[i], lines[j]);
        }
    }
    cout << ans << '\n';
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