/*
    author:  Maksim1744
    created: 15.08.2020 15:01:32
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

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

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

const int inf = 100;

pair<ll, ll> turn(pair<ll, ll> p, pair<ll, ll> cent) {
    p.first -= cent.first;
    p.second -= cent.second;

    swap(p.first, p.second);
    p.first = -p.first;

    p.first += cent.first;
    p.second += cent.second;
    return p;
}

bool check(vector<pair<ll, ll>> v) {
    vector<int> p = {0, 1, 2, 3};
    // sort(v.begin(), v.end());
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[i] == v[j]) return false;
        }
    }
    do {
        pair<ll, ll> s1 = v[p[1]] - v[p[0]];
        if (s1 != v[p[3]] - v[p[2]]) continue;
        pair<ll, ll> s2 = v[p[2]] - v[p[0]];
        if (s2 != v[p[3]] - v[p[1]]) continue;
        // if (s1 == pair<ll, ll>{0, 0}) continue;
        // if (s2 == pair<ll, ll>{0, 0}) continue;
        s1 = turn(s1, mp(0, 0));
        if (s1 == s2) return true;
        s1 = turn(s1, mp(0, 0));
        s1 = turn(s1, mp(0, 0));
        if (s1 == s2) return true;
    } while (next_permutation(p.begin(), p.end()));
    return false;
}

void test_case(int test) {
    vector<pair<ll, ll>> pts(4);
    vector<pair<ll, ll>> cent(4);
    for (int i = 0; i < 4; ++i) {
        cin >> pts[i] >> cent[i];
    }
    int ans = inf;
    int xxx = 4 * 4 * 4 * 4;
    set<vector<int>> s;
    for (int i = 0; i < xxx; ++i) {
        int x = i;
        vector<int> turns;
        for (int j = 0; j < 4; ++j) {
            turns.pb(x % 4);
            x /= 4;
        }
        s.insert(turns);
        vector<pair<ll, ll>> ress;
        for (int k = 0; k < 4; ++k) {
            pair<ll, ll> p = pts[k];
            for (int j = 0; j < turns[k]; ++j) {
                p = turn(p, cent[k]);
            }
            ress.pb(p);
        }
        if (check(ress)) {
            int u = 0;
            for (auto y : turns) {
                u += y;
            }
            ans = min(ans, u);
        }
    }
    assert(s.size() == xxx);
    if (ans == inf) ans = -1;
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