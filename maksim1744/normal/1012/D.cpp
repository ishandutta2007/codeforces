/*
    author:  Maksim1744
    created: 13.04.2021 00:44:33
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
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    vector<pair<int, int>> result(2e6);

    auto upd = [&](vector<pair<int, int>> preans) {
        vector<pair<int, int>> best_ans;
        for (int ii = 0; ii < 2; ++ii) {
            vector<pair<int, int>> ans;

            a.pb('a');
            b.pb('b');

            int ia = a.size() - 2;
            int ib = b.size() - 2;

            string sa = "a";
            string sb = "b";

            while (ia >= 0 || ib >= 0) {
                while (ia >= 0 && a[ia] == a[ia + 1]) {
                    sa.pb(a[ia]);
                    --ia;
                }
                while (ib >= 0 && b[ib] == b[ib + 1]) {
                    sb.pb(b[ib]);
                    --ib;
                }
                if (ia < 0 && ib < 0) break;
                show(sa, sb, a, b, ia, ib);
                ans.eb(ia, ib);
                swap(a, b);
                swap(ia, ib);
                if (ia >= 0)
                    sa.pb(a[ia]);
                if (ib >= 0)
                    sb.pb(b[ib]);
                if (ia >= 0)
                    --ia;
                if (ib >= 0)
                    --ib;
            }

            reverse(sa.begin(), sa.end());
            reverse(sb.begin(), sb.end());

            show(a, b);
            show(sa, sb);
            show(ans);

            if (a.back() != 'a') swap(a, b);

            a.pop_back();
            b.pop_back();

            if (ii == 0 || ans.size() < best_ans.size()) {
                if (ii == 1) {
                    for (int i = 0; i < ans.size(); ++i) {
                        swap(ans[i].first, ans[i].second);
                    }
                }
                swap(ans, best_ans);
            }
            swap(a, b);
        }
        for (auto x : best_ans)
            preans.pb(x);
        if (result.size() > preans.size())
            swap(preans, result);
    };

    upd({});
    vector<int> pa = {0}, pb = {0};
    for (int i = 0; i + 1 < a.size(); ++i)
        if (a[i] != a[i + 1])
            pa.pb(i + 1);
    for (int i = 0; i + 1 < b.size(); ++i)
        if (b[i] != b[i + 1])
            pb.pb(i + 1);
    pa.pb(a.size());
    pb.pb(b.size());

    for (int ii = 0; ii < 2; ++ii) {
        int sa = pa.size();
        int sb = pb.size();
        for (int i = (sa - sb) / 2 - 5; i < (sa - sb) / 2 + 5; ++i) {
            if (i < 0) continue;
            if (i >= pa.size()) continue;
            for (int j = 0; j < 5; ++j) {
                if (j >= pb.size()) continue;
                shows;
                show(a, b);
                string s;
                string t;
                vector<pair<int, int>> preans;
                if (pa[i] != 0 || pb[j] != 0) {
                    preans.eb(pa[i] - 1, pb[j] - 1);
                    if (ii == 1)
                        swap(preans.back().first, preans.back().second);
                }
                s = b.substr(0, pb[j]) + a.substr(pa[i], a.size());
                t = a.substr(0, pa[i]) + b.substr(pb[j], b.size());
                show(pb[j], pa[i]);
                show(s, t);
                swap(s, a);
                swap(t, b);
                if (ii == 1) swap(a, b);
                upd(preans);
                if (ii == 1) swap(a, b);
                swap(s, a);
                swap(t, b);
            }
        }

        swap(a, b);
        swap(pa, pb);
    }

    cout << result.size() << '\n';
    for (auto [a, b] : result) {
        cout << a + 1 << ' ' << b + 1 << '\n';
    }

    return 0;
}