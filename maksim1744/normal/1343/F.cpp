/*
    author:  Maksim1744
    created: 21.04.2020 18:55:51
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
#define debug     if (false)
#endif

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> seg(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int k;
        cin >> k;
        seg[i].resize(k);
        cin >> seg[i];
        --seg[i];
    }
    vector<int> cnt0(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        for (auto k : seg[i]) {
            cnt0[k]++;
        }
    }
    vector<vector<int>> pos(n);
    vector<int> with(n, -1);
    auto seg0 = seg;
    vector<bool> u(n, false);
    vector<bool> us(n - 1, false);
    int l = 0, r = n - 1;
    while (l < r) {
        vector<int> cnt(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            if (!us[i]) {
                for (auto k : seg[i]) {
                    cnt[k]++;
                }
            }
        }
        vector<int> now;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 1 && !u[i])
                now.pb(i);
        }
        // show(cnt);
        // show(pos);
        // show(l, r);
        // show(now);
        // shows;
        assert(now.size() == 1 || now.size() == 2);
        if (now.size() == 1) {
            pos[r] = {now[0]};
            --r;
        } else if (now.size() == 2) {
            pos[l] = now;
            pos[r] = now;
            ++l; --r;
            with[l] = r;
            with[r] = l;
        }
        for (auto k : now) {
            u[k] = true;
            for (int i = 0; i < n - 1; ++i) {
                if (!us[i]) {
                    bool ok = true;
                    for (auto o : seg[i]) {
                        if (o == k) ok = false;
                    }
                    if (!ok) {
                        us[i] = true;
                    }
                }
            }
        }
    }
    if (l == r) {
        for (int i = 0; i < n; ++i) {
            if (!u[i])
                pos[l].pb(i);
        }
    } else {
        --l; ++r;
    }
    auto l0 = l, r0 = r;
    vector<int> ans(n);
    auto check = [&]() {
        l = l0;
        r = r0;
        u.assign(n, false);
        ans.assign(n, -1);
        while (true) {
            shows;
            show(ans, l, r);
            show(pos);
            if (pos[r].size() == 1) {
                ans[r] = pos[r][0];
                u[ans[r]] = true;
            } else {
                int has = r - l - 1;
                if (has == 1 || has == 0) {
                    ans[l] = pos[l][0];
                    ans[r] = pos[l][1];
                } else {
                    bool ok = false;
                    for (auto s : seg) {
                        int cg = 0;
                        int g = -1;
                        for (auto k : s) {
                            if (u[k]) {
                                cg++;
                                g = k;
                            }
                        }
                        if (cg == 1 && g == ans[l + 1]) {
                            for (auto k : s) {
                                if (k == pos[l][0]) {
                                    ans[l] = pos[l][0];
                                    ans[r] = pos[l][1];
                                    ok = true;
                                    break;
                                } else if (k == pos[l][1]) {
                                    ans[l] = pos[l][1];
                                    ans[r] = pos[l][0];
                                    ok = true;
                                    break;
                                }
                            }
                            if (!ok) return false;
                            break;
                        }
                    }
                    if (!ok) return false;
                }
                u[pos[r][0]] = true;
                u[pos[r][1]] = true;
            }
            ++r;
            if (r == n) break;
            if (pos[r].size() == 2) --l;
        }
        vector<int> bor(n, 0);
        for (auto s : seg) {
            vector<int> ind;
            for (int i = 0; i < n; ++i) {
                for (auto k : s) {
                    if (ans[i] == k) {
                        ind.pb(i);
                        break;
                    }
                }
            }
            for (int i = 0; i < ind.size() - 1; ++i) {
                if (ind[i] != ind[i + 1] - 1) return false;
            }
            bor[ind.back()]++;
        }
        show(bor);
        if (bor[0] != 0) return false;
        for (int i = 1; i < n; ++i) {
            if (bor[i] != 1) return false;
        }
        return true;
    };
    if (!check()) {
        for (int i = 0; i < n; ++i) {
            reverse(pos[i].begin(), pos[i].end());
        }
        check();
    }
    ++ans;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}