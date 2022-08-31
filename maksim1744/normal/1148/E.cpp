/*
    author:  Maksim1744
    created: 01.06.2019 19:09:58
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
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

struct MV {
    int i;
    int j;
    ll d;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> vs(n), vt(n);
    cin >> vs >> vt;
    sort(vt.begin(), vt.end());
    ll s1 = 0;
    for (ll u : vs) {
        s1 += u;
    }
    for (ll u : vt) {
        s1 -= u;
    }
    if (s1 != 0) {
        cout << "NO\n";
        return 0;
    }
    vector<pair<ll, int>> s;
    for (int i = 0; i < n; ++i) {
        s.eb(vs[i], i);
    }
    sort(s.begin(), s.end());
    vector<MV> ans;
    vector<ll> ch(n);
    for (int i = 0; i < n; ++i) {
        ch[i] = vt[i] - s[i].first;
    }
    // show(s, vt);
    // show(ch);
    vector<int> st;
    for (int i = 0; i < n; ++i) {
        // show(st);
        if (ch[i] > 0) {
            st.pb(i);
        } else {
            while (st.size() > 0 && ch[i] < 0) {
                ll d = min(-ch[i], ch[st.back()]);
                ans.pb(MV{s[st.back()].second, s[i].second, d});
                ch[i] += d;
                ch[st.back()] -= d;
                if (ch[st.back()] == 0)
                    st.pop_back();
            }
            if (ch[i] < 0) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto m : ans) {
        cout << m.i + 1 << ' ' << m.j + 1 << ' ' << m.d << '\n';
    }
    return 0;
}