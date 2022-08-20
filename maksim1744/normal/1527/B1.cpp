/*
    author:  Maksim1744
    created: 20.05.2021 17:43:14
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

void test_case(int test) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> res(2, 0);
    int who = 0;
    vector<pair<int, int>> p01, p00;
    for (int i = 0; i < n - i - 1; ++i) {
        if (s[i] == '0' && s[n - i - 1] == '0') {
            p00.eb(i, n - i - 1);
        } else if (s[i] == '0' && s[n - i - 1] == '1') {
            p01.eb(i, n - i - 1);
        } else if (s[i] == '1' && s[n - i - 1] == '0') {
            p01.eb(i, n - i - 1);
        }
    }
    int moves = count(s.begin(), s.end(), '0');
    string t = s;
    bool can = true;
    while (moves) {
        show(res);
        if (!p01.empty() && moves != 1 && p01.size() == 1) {
            p01.pop_back();
            res[who]++;
            --moves;
            who ^= 1;
            can = true;
            continue;
        }
        if (!p01.empty() && can) {
            who ^= 1;
            can = false;
            continue;
        }
        if (s.size() % 2 == 1 && s[s.size() / 2] == '0') {
            --moves;
            res[who]++;
            s[s.size() / 2] = '1';
            who ^= 1;
            can = true;
            continue;
        }
        if (!p01.empty()) {
            p01.pop_back();
            res[who]++;
            --moves;
            who ^= 1;
            can = true;
            continue;
        }
        if (!p00.empty()) {
            p00.pop_back();
            p01.eb(-1, -1);
            res[who]++;
            --moves;
            who ^= 1;
            can = true;
            continue;
        }
        assert(false);
    }
    show(res);
    if (res[0] > res[1]) {
        cout << "BOB\n";
    } else if (res[0] < res[1]) {
        cout << "ALICE\n";
    } else {
        cout << "DRAW\n";
    }
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