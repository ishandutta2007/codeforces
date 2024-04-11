/*
    author:  Maksim1744
    created: 05.01.2021 17:48:07
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

vector<int> primes;

void test_case(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    map<vector<int>, int> cnt;
    for (int i = 0; i < n; ++i) {
        vector<int> res;
        int k = a[i];
        for (auto p : primes) {
            if (p * p > k) break;
            if (k % p == 0) {
                int c = 0;
                while (k % p == 0) {
                    k /= p;
                    ++c;
                }
                if (c % 2 == 1)
                    res.pb(p);
            }
        }
        if (k != 1)
            res.pb(k);
        sort(res.begin(), res.end());
        cnt[res]++;
    }
    int q;
    cin >> q;

    int ans0 = 0, ans1 = 0;
    int cnt_zero = 0;
    for (auto [a, b] : cnt) {
        ans0 = max(ans0, b);
        if (b % 2 == 0 || a.empty())
            cnt_zero += b;
    }
    ans1 = max(ans0, cnt_zero);

    show(cnt);

    while (q--) {
        ll w;
        cin >> w;
        cout << (w == 0 ? ans0 : ans1) << '\n';
    }
}

const int N = 1e6 + 20;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<bool> isp(N, true); isp[0] = isp[1] = false;
    for (int i = 2; i * i < N; ++i)
        if (isp[i])
            for (int j = i * i; j < N; j += i)
                isp[j] = false;

    for (int i = 0; i < N; ++i)
        if (isp[i])
            primes.pb(i);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}