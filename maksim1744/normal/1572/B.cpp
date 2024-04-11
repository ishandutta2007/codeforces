/*
    author:  Maksim1744
    created: 18.09.2021 17:55:39
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
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

void test_case(int test) {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    if (count(a.begin(), a.end(), 0) == 0 || sum(a) % 2 == 1) {
        cout << "NO\n";
        return;
    }
    vector<int> ans;

    auto apply = [&](int i) {
        assert(i >= 0);
        assert(i + 2 < n);
        int x = a[i] ^ a[i + 1] ^ a[i + 2];
        a[i] = a[i + 1] = a[i + 2] = x;
        ans.pb(i + 1);
    };

    if (a[0] == 1) {
        int ind = 0;
        while (true) {
            if (ind + 2 >= n) break;
            int x = a[ind] ^ a[ind + 1] ^ a[ind + 2];
            if (x == 0) {
                for (int i = ind; i >= 0; i -= 2) {
                    apply(i);
                }
                break;
            }
            if (a[ind + 1] == 0) {
                apply(ind);
            }
            ind += 2;
        }
    }

    if (a[0] == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    int ind = 0;
    while (ind < n) {
        while (ind < n && a[ind] == 0) ++ind;
        if (ind == n) break;
        if (a[ind + 1] == 1) {
            apply(ind - 1);
        } else {
            apply(ind);
        }
    }

    assert(count(a.begin(), a.end(), 1) == 0);
    assert(ans.size() <= n);
    cout << ans.size() << '\n';
    cout << ans << '\n';
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