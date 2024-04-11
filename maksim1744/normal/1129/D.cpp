/*
    author:  Maksim1744
    created: 11.05.2019 00:10:10
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
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

#ifdef HOME
const int K = 3;
#else
const int K = 317;
#endif

const ll mod = 998244353;

array<ll, K * K> dp;

struct Block {
    int ind;
    array<int, K> b;
    array<ll, 2 * K + 1> sms;
    int sm = 0;

    Block(int i = -1) : ind(i) {
        b.fill(0);
        sms.fill(0);
    }

    void reset() {
        sms.fill(0);
        sm = 0;
        for (int i = K - 1; i >= 0; --i) {
            sm += b[i];
            if (ind == 0 && i == 0)
                sms[K + sm]++;
            else
                sms[K + sm] += dp[ind * K + i - 1];
        }
        for (int i = 1; i < sms.size(); ++i)
            sms[i] = (sms[i] + sms[i - 1]) % mod;
        sms[0] %= mod;
    }

    ll ask(int u) {
        if (u + K < 0)
            return 0;
        else if (u + K >= sms.size())
            return sms.back();
        else
            return sms[u + K];
    }

    void change(int ind, int k) {
        b[ind] = k;
        reset();
    }
};

#ifdef TAG_LENGTH
string to_string(Block b) {
    return "[b = " + to_string(b.b) + ", sms = " + to_string(b.sms) + ", sm = " + to_string(b.sm) +  "]";
}
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<Block> blocks(K);
    for (int i = 0; i < K; ++i) {
        blocks[i].ind = i;
    }
    int n, k;
    cin >> n >> k;
    vector<int> vv(n);
    cin >> vv;
    vector<int> lst(n + 1, -1);
    vector<int> prev(n);
    for (int i = 0; i < n; ++i) {
        prev[i] = lst[vv[i]];
        lst[vv[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        blocks[i / K].change(i % K, 1);
        if (prev[i] != -1) {
            if (prev[prev[i]] != -1) {
                blocks[prev[prev[i]] / K].change(prev[prev[i]] % K, 0);
            }
            blocks[prev[i] / K].change(prev[i] % K, -1);
        }
        showt(i, blocks);
        int s = 0;
        for (int j = i; j >= i / K * K; --j) {
            s += blocks[i / K].b[j % K];
            if (s <= k)
                dp[i] += (j == 0 ? 1 : dp[j - 1]);
        }
        for (int j = i / K - 1; j >= 0; --j) {
            // show(j, k, s);
            dp[i] += blocks[j].ask(k - s);
            s += blocks[j].sm;
        }
        dp[i] %= mod;
        if (i % K == 0)
            blocks[i / K].reset();
    }
    shows;
    show(dp);
    cout << dp[n - 1] << '\n';
    return 0;
}