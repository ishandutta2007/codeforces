/*
    author:  Maksim1744
    created: 20.05.2021 18:03:26
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

const int N = 1005;
array<array<array<array<int, 2>, 2>, N>, N> score;

void test_case(int test) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mid = (s.size() % 2 == 1 && s[s.size() / 2] == '0');
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n - i - 1; ++i) {
        if (s[i] != s[n - i - 1]) {
            ++c2;
            continue;
        }
        if (s[i] == '0') {
            ++c1;
        }
    }
    int sc = score[c1][c2][1][mid];
    if (sc > 0)
        cout << "BOB\n";
    else if (sc < 0)
        cout << "ALICE\n";
    else
        cout << "DRAW\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 2; ++i) {
        score[0][0][i][0] = 0;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int can = 0; can < 2; ++can) {
                for (int mid = 0; mid < 2; ++mid) {
                    if (i == 0 && j == 0 && mid == 0) continue;
                    auto &sc = score[i][j][can][mid];
                    score[i][j][can][mid] = 1e9;
                    if (j != 0 && can) {
                        umin(sc, -score[i][j][0][mid]);
                    }
                    if (i && j + 1 < N) {
                        umin(sc, 1 - score[i - 1][j + 1][1][mid]);
                    }
                    if (j) {
                        umin(sc, 1 - score[i][j - 1][1][mid]);
                    }
                    if (mid) {
                        umin(sc, 1 - score[i][j][1][0]);
                    }
                }
            }
        }
    }

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}