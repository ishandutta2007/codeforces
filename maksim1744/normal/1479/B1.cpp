/*
    author:  Maksim1744
    created: 07.02.2021 17:48:16
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
    vector<int> a(n);
    cin >> a;
    vector<pair<int, int>> b;
    for (auto k : a) {
        if (b.empty() || b.back().first != k)
            b.eb(k, 0);
        b.back().second++;
    }

    vector<int> inds = {-1};
    int ans = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (b[i].second >= 2) {
            ans += 2;
            inds.pb(i);
        }
    }
    inds.pb(b.size());
    for (int i = 0; i + 1 < inds.size(); ++i) {
        int l = inds[i], r = inds[i + 1];
        int x, y;
        if (l == -1) x = -1;
        else x = b[l].first;
        if (r == b.size()) y = -2;
        else y = b[r].first;

        if (x != y) {
            ans += r - l - 1;
            continue;
        }

        vector<int> cur;
        for (int j = l + 1; j <= r - 1; ++j)
            cur.pb(b[j].first);

        if (cur.empty()) {
            assert(false);
        }

        if (cur.size() == 1) {
            continue;
        }

        bool left = false;
        int last = x;
        ans += r - l - 1;
        for (int k : cur) {
            if (last == x && k != x) {
                last = k;
            } else if (last != x && k == x) {
                last = x;
            } else {
                left = true;
            }
        }

        if (!left) --ans;
    }

    cout << ans << '\n';

    return 0;
}