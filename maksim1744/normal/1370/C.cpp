/*
    author:  Maksim1744
    created: 20.06.2020 17:41:43
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

vector<int> primes;

bool is_prime(int n) {
    for (auto p : primes) {
        if (p * p > n) break;
        if (n % p == 0) return false;
    }
    return true;
}

void test_case() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "Ashishgup\n";
        return;
    }
    if (__builtin_popcount(n) == 1) {
        cout << "FastestFinger\n";
        return;
    }
    if (n % 2 == 1) {
        cout << "Ashishgup\n";
        return;
    } else {
        int cnt = 0;
        while (n % 2 == 0) {
            n /= 2;
            cnt++;
        }
        if (cnt == 1) {
            if (is_prime(n))
                cout << "FastestFinger\n";
            else
                cout << "Ashishgup\n";
        } else {
            cout << "Ashishgup\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N = 1e5;
    vector<bool> isp(N + 1, true); isp[0] = isp[1] = false;
    for (ll i = 0; i * i < isp.size(); ++i)
        if (isp[i])
            for (ll j = i * i; j < isp.size(); j += i)
                isp[j] = false;

    for (int i = 0; i < N; ++i)
        if (isp[i])
            primes.pb(i);

    int T;
    cin >> T;
    while (T--) {
        test_case();
    }

    return 0;
}