/*
    author:  Maksim1744
    created: 20.12.2020 18:39:21
*/

#include "bits/stdc++.h"

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

    int n;
    cin >> n;
    ll T;
    cin >> T;
    string s;
    cin >> s;
    vector<ll> p2(60);
    p2[0] = 1;
    for (int i = 1; i < p2.size(); ++i)
        p2[i] = p2[i - 1] * 2;

    vector<ll> opts(60, 0);

    ll have = 0;
    for (int i = 0; i < n - 2; ++i) {
        have -= p2[s[i] - 'a'];
        opts[s[i] - 'a' + 1]++;
    }
    have += p2[s[n - 1] - 'a'];
    have -= p2[s[n - 2] - 'a'];
    for (int i = 0; i + 1 < opts.size(); ++i) {
        if (opts[i] < 3) continue;
        ll cnt = opts[i] / 2;
        while (opts[i] - cnt * 2 < 1) --cnt;
        opts[i + 1] += cnt;
        opts[i] -= cnt * 2;
    }

    if (T < have) {
        cout << "No\n";
        return 0;
    }
    T -= have;
    if (T == 0) {
        cout << "Yes\n";
        return 0;
    }

    for (int i = 0; i + 1 < opts.size(); ++i) {
        if (T == 0) {
            cout << "Yes\n";
            return 0;
        }
        if (T % 2 == 1) {
            if (opts[i] == 0) {
                cout << "No\n";
                return 0;
            }
            opts[i]--;
            T--;
        }
        T /= 2;
        opts[i + 1] += opts[i] / 2;
    }
    cout << "No\n";

    return 0;
}