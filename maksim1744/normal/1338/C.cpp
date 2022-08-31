/*
    author:  Maksim1744
    created: 12.04.2020 17:34:44
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        if (n <= 3) {
            cout << n << '\n';
            continue;
        }
        ll bl = 0;
        ll sm = 0;
        while (n > sm + ((1ll << (bl * 2)) + (1ll << (bl * 2 + 1)))) {
            sm += ((1ll << (bl * 2)) + (1ll << (bl * 2 + 1)));
            ++bl;
        }
        ll ln = ((1ll << (bl * 2)) + (1ll << (bl * 2 + 1)));
        n -= sm;
        n--;
        ll num = n / 3;
        ll n0 = num + (1ll << (bl * 2));
        ll n1 = 0, n2 = 0;
        for (int i = 0; i < bl; ++i) {
            ll k = (n0 >> (i * 2)) & 3ll;
            if (k == 0) {
        
                
                n1 += 0;
                n2 += 0;
            } else if (k == 1) {
                n1 += (2ll) << (i * 2);
                n2 += (3ll) << (i * 2);
            } else if (k == 2) {
                n1 += (3ll) << (i * 2);
                n2 += (1ll) << (i * 2);
            } else {
                n1 += (1ll) << (i * 2);
                n2 += (2ll) << (i * 2);
            }
        }
        n1 += (1ll << (bl * 2 + 1));
        n2 += (1ll << (bl * 2 + 1)) + (1ll << (bl * 2));
        vector<ll> vn = {n0, n1, n2};
        cout << vn[n % 3] << '\n';
    }

    return 0;
}