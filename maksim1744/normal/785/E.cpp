/*
    author:  Maksim1744
    created: 13.01.2021 00:19:46
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

    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }

    const int B = 400;
    vector<vector<pair<int, int>>> blocks((n + B - 1) / B);
    for (int i = 0; i < n; ++i) {
        blocks[i / B].eb(p[i], i);
    }

    for (int i = 0; i < blocks.size(); ++i) {
        sort(blocks[i].begin(), blocks[i].end());
    }

    ll ans = 0;

    auto get_cnt = [&](int l, int r, int a, int b) {
        int L = l / B;
        int R = r / B;
        int res = 0;
        for (int j = L + 1; j <= R - 1; ++j) {
            int ind1 = lowb(blocks[j], mp(a, -1));
            int ind2 = lowb(blocks[j], mp(b, -1));
            res += ind2 - ind1;
        }
        for (int j : set<int>{L, R})
            for (auto [x, ind] : blocks[j])
                if (l <= ind && ind <= r && a <= x && x <= b)
                    ++res;
        return res;
    };

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        if (a != b) {
            if (a > b) swap(a, b);
            int x = p[a], y = p[b];
            int l = a, r = b;
            ++l;
            --r;
            ll cnt = 0;
            // (n/B * log(B) + B)*q
            // n * q / B * log(B) + B * q
            // n = B^2 / log(B)
            if (l <= r) cnt = get_cnt(l, r, min(p[a], p[b]), max(p[a], p[b]));
            if (x < y) {
                ans += cnt * 2 + 1;
            } else {
                ans -= cnt * 2 + 1;
            }

            swap(p[a], p[b]);

            auto modif = [&](int block_ind, int ind, int new_val) {
                for (int i = 0; i < blocks[block_ind].size(); ++i) {
                    if (blocks[block_ind][i].second == ind) {
                        blocks[block_ind][i].first = new_val;
                        int j = i;
                        while (j + 1 < blocks[block_ind].size() && blocks[block_ind][j].first > blocks[block_ind][j + 1].first) {
                            swap(blocks[block_ind][j], blocks[block_ind][j + 1]);
                            ++j;
                        }
                        while (j - 1 >= 0 && blocks[block_ind][j].first < blocks[block_ind][j - 1].first) {
                            swap(blocks[block_ind][j], blocks[block_ind][j - 1]);
                            --j;
                        }
                        return;
                    }
                }
            };

            modif(a / B, a, p[a]);
            modif(b / B, b, p[b]);
        }

        cout << ans << '\n';
    }

    return 0;
}