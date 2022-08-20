/*
    author:  Maksim1744
    created: 20.10.2019 12:19:40
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

#ifdef HOMEn
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
#endif

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (auto c : s) {
        if (c == '(')
            ++cnt;
    }
    if (cnt * 2 != n) {
        cout << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        return 0;
    }
    vector<int> with(n, -1);
    int ok = 0;
    int ind = 0;
    stack<pair<int, char>> st;
    while (ok != n / 2) {
        if (with[ind] == -1) {
            // show(with, ind);
            if (!st.empty() && st.top().second == '(' && s[ind] == ')') {
                with[ind] = st.top().first;
                with[st.top().first] = ind;
                ++ok;
                st.pop();
            } else {
                st.emplace(ind, s[ind]);
            }
        }
        ++ind;
        ind %= n;
    }
    show(with);
    int start = -1;
    int mxl = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            int ln = (with[i] - i + n) % n;
            if (ln > mxl) {
                mxl = ln;
                start = i;
            }
        }
    }
    s = s.substr(start, n) + s.substr(0, start);
    vector<int> nwith;
    for (int i = start; i < n; ++i)
        nwith.pb(with[i]);
    for (int i = 0; i < start; ++i)
        nwith.pb(with[i]);
    for (int i = 0; i < n; ++i)
        nwith[i] = (nwith[i] - start + n) % n;
    swap(with, nwith);
    show(s);
    vector<int> inside(n, 0);
    stack<int> sti;
    vector<bool> glob(n, false);
    vector<bool> glob2(n, false);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        if (!sti.empty() && s[i] == '(') {
            inside[sti.top()]++;
        }
        if (s[i] == ')') {
            sti.pop();
        } else {
            if (sti.empty()) {
                glob[i] = true;
                ++tot;
            }
            sti.push(i);
        }
    }
    while (!sti.empty())
        sti.pop();
    for (int i = 0; i < n; ++i) {
        if (s[i] == ')') {
            sti.pop();
        } else {
            if (!sti.empty() && glob[sti.top()])
                glob2[i] = true;
            sti.push(i);
        }
    }
    show(inside);
    show(glob);
    int mxi = -1;
    int mx = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(' && glob2[i] && inside[i] > mx) {
            mx = inside[i];
            mxi = i;
        }
    }
    mx += tot + 1;
    show(mx, mxi);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(' && glob[i] && inside[i] + 1 > mx) {
            mx = inside[i] + 1;
            mxi = i;
        }
    }
    show(mx, mxi);
    show(with);
    pair<int, int> sw = {1, 1};
    if (mx != 0 && mxi != -1) {
        sw = {(mxi + start) % n + 1, (with[mxi] + start) % n + 1};
        swap(s[mxi], s[with[mxi]]);
    }
    show(sw);
    show(s);
    while (!sti.empty())
        sti.pop();
    // int ans = 0;
    // for (int i = 0; i < n; ++i) {
    //     if (!sti.empty() && s[i] == '(') {
    //         inside[sti.top()]++;
    //     }
    //     if (s[i] == ')') {
    //         sti.pop();
    //     } else {
    //         if (sti.empty())
    //             ++ans;
    //         sti.push(i);
    //     }
    // }
    cout << mx << '\n';
    cout << sw.first << ' ' << sw.second << '\n';
    return 0;
}