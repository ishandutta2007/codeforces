/*
    author:  Maksim1744
    created: 08.05.2019 00:16:28
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
const int nax = 1000;
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
const int nax = 200020;
#endif


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, f;
    cin >> n >> f;
    vector<int> sieve(nax, 0);
    sieve[0] = sieve[1] = 1;
    for (int i = 2; i < nax; ++i)
        if (!sieve[i] && (ll)i * i < nax)
            for (int j = i * i; j < nax; j += i)
                sieve[j] = i;
    vector<bool> moves(nax, false);
    // vector<int> moves;
    // moves.reserve(63300);
    for (int i = 2; i < nax; ++i)
        if (sieve[i] == 0 || sieve[i / sieve[i]] == 0)
            moves[i] = true;
    moves[f] = false;
    vector<vector<int>> v(100);
    vector<int> fun(nax);
    for (int i = 0; i < nax; ++i) {
        for (int j = 0; j < v.size(); ++j) {
            bool found = false;
            for (auto k : v[j]) {
                if (moves[i - k]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                fun[i] = j;
                v[j].pb(i);
                break;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        res ^= fun[b - a - 1] ^ fun[c - b - 1];
    }
    show(res);
    if (res == 0) {
        cout << "Bob\nAlice\n";
    } else {
        cout << "Alice\nBob\n";
    }
    // show(fun);
    // show(v);
    // vector<int> used(nax + 1, -1);
    // int step = 0;
    // for (int i = 1; i < nax; ++i) {
    //     ++step;
    //     for (auto p : moves) {
    //         if (p > i)
    //             break;
    //         used[fun[i - p]] = step;
    //     }
    //     int j;
    //     for (j = 0; used[j] == step; ++j);
    //     fun[i] = j;
    // }
    return 0;
}