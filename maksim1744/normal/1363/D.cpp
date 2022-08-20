/*
    author:  Maksim1744
    created: 31.05.2020 17:55:39
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

int ask(vector<int> v) {
    ++v;
    cout << "? " << v.size() << ' ' << v << endl;
    int ans;
    cin >> ans;
    return ans;
}

void test_case() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> s(k);
    for (int i = 0; i < k; ++i) {
        int c;
        cin >> c;
        s[i].resize(c);
        cin >> s[i];
        --s[i];
    }
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        v.pb(i);
    }
    int mx = ask(v);
    int l = 0, r = n - 1;
    while (r - l != 0) {
        int c = (l + r) / 2;
        v.clear();
        for (int i = l; i <= c; ++i)
            v.pb(i);
        int now = ask(v);
        if (now == mx) {
            r = c;
        } else {
            l = c + 1;
        }
    }
    int badind = -1;
    for (int i = 0; i < k; ++i) {
        for (auto u : s[i]) {
            if (u == l) {
                badind = i;
            }
        }
    }
    vector<int> ans(k, mx);
    if (badind != -1) {
        set<int> st;
        for (int i = 0; i < n; ++i) {
            st.insert(i);
        }
        for (auto u : s[badind]) {
            st.erase(u);
        }
        v.clear();
        for (auto u : st) {
            v.pb(u);
        }
        ans[badind] = ask(v);
    }
    cout << "! " << ans << endl;
    string ss;
    cin >> ss;
    if (ss != "Correct") {
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        test_case();
    }

    return 0;
}