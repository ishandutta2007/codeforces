/*
    author:  Maksim1744
    created: 07.05.2019 23:49:44
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
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    int n;
    cin >> n;
    vector<long long> l(n);
    // for (int i = 0; i < n; ++i) {
    //     l[i] *= 2;
    // }
    cin >> l;
    string s;
    cin >> s;
    ll energy = 0;
    ll time = 0;
    ll water = 0;
    ll grass = 0;
    bool was_water = false;
    for (int i = 0; i < n; ++i) {
        energy -= l[i];
        time += l[i];
        if (s[i] == 'W') {
            water += l[i] * 2;
            was_water = true;
        } else if (s[i] == 'G') {
            grass += l[i] * 2;
        }
        if (energy < 0) {
            ll k = min(-energy, water);
            energy += k;
            water -= k;
            time += k;
        }
        if (energy < 0) {
            ll k = min(-energy, grass);
            energy += k;
            grass -= k;
            time += k * 2;
        }
        if (energy < 0) {
            if (was_water) {
                time += -energy * 3;
                energy = 0;
            } else {
                time += -energy * 5;
                energy = 0;
            }
        }
    }
    // assert(time % 2 == 0);
    cout << time << '\n';
    return 0;
}