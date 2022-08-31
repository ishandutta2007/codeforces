/*
    author:  Maksim1744
    created: 03.03.2020 18:31:46
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

const int N = 1e6 + 20;

mt19937 rng(1298739192);
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<bool> isp(N, true);
    // vector<int> mnp(N, 1);
    isp[0] = isp[1] = false;
    for (int i = 2; i < N; ++i) {
        if (isp[i]) {
            // mnp[i] = i;
            if ((ll)i * i < N) {
                for (int j = i * i; j < N; j += i) {
                    isp[j] = false;
                    // mnp[j] = i;
                }
            }
        }
    }

    vector<ll> primes;
    for (int i = 2; i < N; ++i) {
        if (isp[i])
            primes.pb(i);
    }

    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    ll ans = n;
    for (int j = 0; j < 20; ++j) {
        ll cur = 0;
        for (int i = 0; i < n; ++i) {
            ll rem = a[i] % primes[j];
            if (a[i] == rem)
                cur += primes[j] - rem;
            else
                cur += min(rem, primes[j] - rem);
        }
        ans = min(ans, cur);
    }
    set<ll> was;
    for (int iii = 0; iii < 65; ++iii) {
        ll kk = a[rng() % n];
        for (ll k : {kk - 1, kk, kk + 1}) {
            if (k <= 2) continue;
            if (was.count(k))
                continue;
            was.insert(k);
            vector<ll> vp;
            // show(k);
            for (auto p : primes) {
                if (p * p > k)
                    break;
                if (k % p == 0) {
                    vp.pb(p);
                    while (k % p == 0)
                        k /= p;
                }
            }
            if (k != 1)
                vp.pb(k);
            for (ll t : vp) {
                ll cur = 0;
                for (int i = 0; i < n; ++i) {
                    ll rem = a[i] % t;
                    if (a[i] == rem)
                        cur += t - rem;
                    else
                        cur += min(rem, t - rem);
                    if (cur > ans)
                        break;
                }
                ans = min(cur, ans);
            }
            // sort(vp.begin(), vp.end());
            // vp.erase(unique(vp.begin(), vp.end()), vp.end());
        }
    }
    cout << ans << endl;

    return 0;
}