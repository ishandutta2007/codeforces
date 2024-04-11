/*
    author:  Maksim1744
    created: 30.08.2020 17:42:41
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

map<pair<int, vector<int>>, bool> mem;

bool is_win(pair<int, vector<int>> v) {
    if (mem.count(v)) return mem[v];
    bool win = false;
    for (int i = 0; i < v.second.size(); ++i) {
        if (i == v.first) continue;
        auto u = v;
        u.first = -1;
        u.second[i]--;
        int k = u.second[i];
        if (u.second[i] == 0) {
            u.second.erase(u.second.begin() + i);
        }
        else {
            sort(u.second.begin(), u.second.end());
        }
        for (int j = 0; j < u.second.size(); ++j) {
            if (u.second[j] == k) {
                u.first = j;
                break;
            }
        }
        if (!is_win(u)) {
            win = true;
            break;
        }
    }
    mem[v] = win;
    return win;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

bool my_is_win(vector<int> a) {
    sort(a.begin(), a.end());
    if (a.size() == 1) return true;
    if (a.size() == 2) return a[0] != a[1];
    // if (a.size() == 3 && a[0] == 1 && a[1] == a[2]) {
    //     return true;
    // }
    a.back() = min(a.back(), accumulate(a.begin(), a.begin() + (int)a.size() - 1, 0) + 1);
    // a.erase(a.begin());
    // return my_is_win(a) ^ (a[0] % 2 == 1);
    // if (a[0] == 1 && a[1] == 1 && a[2] > 2)
    //     return true;
    return sum(a) % 2 == 1;
}

void test_case(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    if (my_is_win(a)) cout << "T\n";
    else cout << "HL\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // for (int i = 0; i < 1000; ++i) {
    //     int n = rnd(1, 3);
    //     int C = rnd(1, 5);
    //     vector<int> a;
    //     for (int i = 0; i < n; ++i) {
    //         a.pb(rnd(1, C));
    //     }
    //     bool my_res = my_is_win(a);
    //     bool real_res = is_win(mp(-1, a));
    //     if (my_res != real_res) {
    //         show(a);
    //         show(my_res);
    //         show(real_res);
    //         break;
    //     }
    // }
    // int C = 8;
    // for (int a = 1; a <= C; ++a) {
    //     for (int b = a; b <= C; ++b) {
    //         for (int c = b; c <= C; ++c) {
    //             vector<int> v = {a, b, c};
    //             if (is_win(mp(-1, v)) != my_is_win(v))
    //                 cout << v << ": " << is_win(mp(-1, v)) << ' ' << my_is_win(v) << '\n';
    //         }
    //     }
    // }

    // show(is_win(mp(-1, vector<int>{1, 3, 4})))

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}