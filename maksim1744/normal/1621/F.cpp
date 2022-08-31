/*
    author:  Maksim1744
    created: 03.01.2022 18:42:08
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

void test_case(int test) {
    int n;
    ll a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    if (count(s.begin(), s.end(), '1') == 0) {
        cout << a << '\n';
        return;
    }

    int av1 = 0, av0 = 0;
    vector<int> segs;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            if (s[i] == '0') ++av0;
            else ++av1;
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == '1' && s[i + 1] == '0') {
            int j = i + 1;
            while (j < n && s[j] == '0')
                ++j;
            if (j == n) continue;
            segs.pb(j - i - 1);
        }
    }

    int ends = 0;
    if (s[0] == '0') ++ends;
    if (s.back() == '0') ++ends;

    ll ans = 0;
    auto first1 = [&](int av0, int av1, int ends, vector<int> segs) -> ll {
        ll ans = 0;
        if (!av1) return ans;
        ll cur = 0;

        int canadd = 0;
        sort(segs.begin(), segs.end());
        reverse(segs.begin(), segs.end());

        while (!segs.empty() && segs.back() == 1) {
            segs.pop_back();
            ++canadd;
        }

        while (av1) {
            show(av0, av1, canadd, ends, cur);
            --av1;
            cur += b;
            ans = max(ans, cur);

            if (av1 == 0) {
                if (av0) {
                    ans = max(ans, cur + a);
                }
                if (canadd) {
                    cur -= c;
                    --canadd;
                    ++av1;
                } else {
                    break;
                }
            } else {
                if (av0) {
                    --av0;
                    cur += a;
                    ans = max(ans, cur);
                    if (!segs.empty()) {
                        segs.back()--;
                        if (segs.back() == 1) {
                            segs.pop_back();
                            ++canadd;
                        }
                    }
                } else if (canadd) {
                    --canadd;
                    cur -= c;
                    ++av1;
                } else if (ends) {
                    --ends;
                    cur -= c;
                } else {
                    break;
                }
            }
        }
        show(ans);
        return ans;
    };

    shows;
    ans = max(ans, first1(av0, av1, ends, segs));
    shows;
    ans = max(ans, first1(av0, av1 + 1, ends, segs) - b);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}