/*
    author:  Maksim1744
    created: 20.12.2020 19:31:51
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

const ll mod = 1e9 + 7;

void test_case(int test) {
    int n;
    cin >> n;
    vector<int> p(n);
    cin >> p;
    --p;
    vector<int> lens;
    vector<bool> u(n, false);
    for (int i = 0; i < n; ++i) {
        if (u[i]) continue;
        int x = i;
        int ln = 0;
        while (!u[x]) {
            u[x] = true;
            ++ln;
            x = p[x];
        }
        lens.pb(ln);
    }
    int c1 = 0, c2 = 0, c4 = 0, ans = 0;
    for (auto ln : lens) {
        if (ln % 3 == 0) {
            ans += ln / 3 - 1;
        } else if (ln % 3 == 1) {
            while (ln >= 7) {
                ln -= 3;
                ans++;
            }
            if (ln == 1) ++c1;
            else ++c4;
        } else if (ln % 3 == 2) {
            while (ln - 3 > 0) {
                ln -= 3;
                ++ans;
            }
            c2++;
        }
    }

    auto calc_zero = [&](int c1, int c2, int c4) {
        int ans = 0;
        while (c4) {
            // 4 -> 3 + 1
            ++c1;
            ++ans;
            --c4;
        }
        while (c2 >= 1 && c1 >= 1) {
            --c1;
            --c2;
            ++ans;
        }
        if (c1 != 0) {
            assert(c1 % 3 == 0);
            ans += c1 / 3 * 2;
        } else if (c2 != 0) {
            assert(c2 % 3 == 0);
            ans += c2 / 3 * 3;
        }
        return ans;
    };

    if (n % 3 == 0) {
        ans += calc_zero(c1, c2, c4);
    } else if (n % 3 == 1) {
        int cur = 1e9;

        if (c1 != 0 && c1 + c2 * 2 + c4 * 4 != n)
            cur = min(cur, calc_zero(c1 - 1, c2, c4) + 1);

        if (c4 >= 1) {
            cur = min(cur, calc_zero(c1, c2, c4 - 1));
        }
        if (c2 >= 2) {
            cur = min(cur, calc_zero(c1, c2 - 2, c4));
        }
        if (c1 >= 4) {
            cur = min(cur, calc_zero(c1 - 4, c2, c4) + 2);
        }
        if (c1 >= 2 && c2 >= 1) {
            cur = min(cur, calc_zero(c1 - 2, c2 - 1, c4) + 1);
        }
        assert(cur != 1e9);
        ans += cur;
    } else {
        int cur = 1e9;

        if (c2 >= 1)
            cur = min(cur, calc_zero(c1, c2 - 1, c4));
        if (c1 >= 2)
            cur = min(cur, calc_zero(c1 - 2, c2, c4) + 1);
        if (c4 >= 1)
            cur = min(cur, calc_zero(c1, c2 + 1, c4 - 1) + 1);

        assert(cur != 1e9);

        ans += cur;
    }

    ll cnt = 1;
    ll nn = n;
    while (nn >= 5) {
        nn -= 3;
        cnt = cnt * 3 % mod;
    }
    cnt = cnt * nn % mod;

    cout << cnt << ' ' << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}