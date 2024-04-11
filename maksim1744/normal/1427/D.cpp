/*
    author:  Maksim1744
    created: 10.10.2020 18:14:15
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

    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;

    vector<vector<int>> ans;

    auto apply = [&](vector<int> szs) {
        {
            vector<int> tmp;
            for (auto k : szs) {
                if (k != 0)
                    tmp.pb(k);
            }
            swap(tmp, szs);
        }
        ans.pb(szs);
        vector<vector<int>> segs;
        int ind = 0;
        for (auto k : szs) {
            segs.eb();
            for (int i = 0; i < k; ++i) {
                segs.back().pb(v[ind]);
                ++ind;
            }
        }
        reverse(segs.begin(), segs.end());
        v.clear();
        for (auto s : segs) {
            for (auto k : s) {
                v.pb(k);
            }
        }
    };

    while (true) {
        vector<bool> can(n, false);
        bool sth = false;
        for (int i = 0; i < n - 1; ++i) {
            if (v[i] + 1 != v[i + 1]) {
                can[i] = true;
                sth = true;
            }
        }
        if (!sth) break;
        int i0 = 0;

        show(v);

        vector<int> ch;
        if (v[0] == 1) {
            int ind = 0;
            while (ind < v.size() && v[ind] == ind + 1)
                ++ind;
            assert(ind != v.size());
            i0 = ind;
            ch.pb(i0);
        }

        show(can);
        show(i0);

        int ind = -1;
        for (int i = i0; i < n; ++i) {
            if (v[i] == v[i0] - 1) {
                ind = i;
                break;
            }
        }
        show(ind);
        assert(ind != -1);
        int imid = -1;
        for (int i = i0; i < ind; ++i) {
            if (can[i]) {
                imid = i;
                break;
            }
        }
        show(imid);
        assert(imid != -1);

        show(ch);

        ch.pb(imid - i0 + 1);
        ch.pb(ind - imid);
        ch.pb(n - (ind + 1));
        apply(ch);
    }

    cout << ans.size() << '\n';
    for (auto s : ans) {
        cout << s.size() << ' ' << s << '\n';
    }

    return 0;
}