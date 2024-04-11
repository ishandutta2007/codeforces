/*
    author:  Maksim1744
    created: 16.08.2020 19:34:03
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

    int n, m, k;
    cin >> n >> m >> k;
    string as, bs;
    cin >> as >> bs;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        // if (v[i].first > v[i].second) swap(v[i].first, v[i].second);
        --v[i].first;
        --v[i].second;
    }
    vector<int> va(n), vb(n);
    vector<int> p(k);
    for (int i = 0; i < k; ++i) {
        p[i] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        swap(p[v[i].first], p[v[i].second]);
        for (int j = 0; j < k; ++j) {
            va[i] += int(as[j] == '1') << p[j];
        }
    }
    for (int i = 0; i < k; ++i) {
        p[i] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < k; ++j) {
            vb[i] += int(bs[j] == '1') << p[j];
        }
        swap(p[v[i].first], p[v[i].second]);
    }
    int p2 = (1 << k);
    vector<int> ans(p2, -1);
    vector<int> restore(p2, -1);
    int all1 = (1 << k) - 1;
    auto add = [&](int mask, int ind) {
        if (ans[mask] == __builtin_popcount(mask)) {
            return;
        }
        // for (int i = 0; i < p2; ++i) {
        //     int can = __builtin_popcount(i & mask);
        //     if (ans[i] < can) {
        //         ans[i] = can;
        //         restore[i] = ind;
        //     }
        // }
        function<void(int)> dfs_down = [&](int cur) {
            if (ans[cur] >= __builtin_popcount(cur & mask)) return;
            ans[cur] = __builtin_popcount(cur & mask);
            restore[cur] = ind;
            int check = ((cur & mask));
            while (check) {
                int last1 = (check ^ (check & (check - 1)));
                check ^= last1;
                dfs_down(cur ^ last1);
            }
        };
        function<void(int)> dfs_up = [&](int cur) {
            if (ans[cur] >= __builtin_popcount(cur & mask)) return;
            ans[cur] = __builtin_popcount(cur & mask);
            restore[cur] = ind;
            int neg = (all1 ^ (cur | mask));
            while (neg) {
                int last1 = (neg ^ (neg & (neg - 1)));
                neg ^= last1;
                dfs_up(cur ^ last1);
            }
            int check = ((cur & mask));
            while (check) {
                int last1 = (check ^ (check & (check - 1)));
                check ^= last1;
                dfs_down(cur ^ last1);
            }
        };
        dfs_up(mask);
    };
    int bestl = 1, bestr = m;
    int best = -1;
    for (int l = n - 1; l >= 0; --l) {
        if (l + m - 1 <= n - 1) {
            add(vb[l + m - 1], l + m - 1);
            int cur = ans[va[l]];
            if (cur > best) {
                best = cur;
                bestr = restore[va[l]];
                bestl = l;
            }
        }
    }
    cout << best + (k - (int)count(as.begin(), as.end(), '1') - (int)count(bs.begin(), bs.end(), '1') + best) << '\n';
    cout << bestl + 1 << ' ' << bestr + 1 << '\n';

    return 0;
}