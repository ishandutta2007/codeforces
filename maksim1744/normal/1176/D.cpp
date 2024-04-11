/*
    author:  Maksim1744
    created: 17.08.2020 15:35:35
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
const int N = 1e6 * 3;
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
const int N = 1e6 * 3;
#endif


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> b(n * 2);
    cin >> b;
    vector<bool> isp(N, true); isp[0] = isp[1] = false;
    vector<int> mind(N, -1);
    for (int i = 2; i * i < N; ++i) {
        if (isp[i]) {
            for (int j = i * i; j < N; j += i) {
                isp[j] = false;
                if (mind[j] == -1)
                    mind[j] = i;
            }
        }
    }
    // show(mind);
    vector<int> num(N, 0);
    for (int i = 1; i < N; ++i) {
        num[i] = num[i - 1] + isp[i];
    }

    multiset<int> primes, other;
    for (int i = 0; i < b.size(); ++i) {
        if (isp[b[i]]) primes.insert(b[i]);
        else other.insert(b[i]);
    }

    vector<int> a;
    while (!other.empty()) {
        int x = *--other.end();
        other.erase(--other.end());
        int u = x / mind[x];
        a.pb(x);
        if (isp[u]) primes.erase(primes.find(u));
        else other.erase(other.find(u));
    }

    while (!primes.empty()) {
        int p = *--primes.end();
        primes.erase(--primes.end());
        a.pb(num[p]);
        primes.erase(primes.find(num[p]));
    }

    cout << a << '\n';

    return 0;
}