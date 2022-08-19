/*
    author:  Maksim1744
    created: 23.02.2022 14:03:42
*/

#include "bits/stdc++.h"

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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

using A = array<int, 5>;

struct hash_my {
    size_t operator()(int x) const {
        x = ((x >> 16) ^ x) * 0x119de1f3;
        x = ((x >> 16) ^ x) * 0x119de1f3;
        x = (x >> 16) ^ x;
        return x;
    }

    size_t operator()(long long x) const {
        x = (x ^ (x >> 30)) * (0xbf58476d1ce4e5b9ll);
        x = (x ^ (x >> 27)) * (0x94d049bb133111ebll);
        x = x ^ (x >> 31);
        return x;
    }

    template<typename T, typename U>
    size_t operator()(const pair<T, U> &p) const {
        long long h1 = (*this)(p.first);
        long long h2 = (*this)(p.second);
        return (*this)(h1 ^ (h2 << 32) ^ (h2 >> 32));
    }

    size_t operator()(const A &a) const {
        return (*this)(make_pair(make_pair(make_pair(a[0], a[1]), make_pair(a[2], a[3])), a[4]));
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, A>> v(n);
    {
        set<int> unused;
        for (int i = 0; i < n * 5; ++i) {
            unused.insert(i);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> v[i].second[j];
                unused.erase(v[i].second[j]);
            }
            cin >> v[i].first;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = m; j < 5; ++j) {
                v[i].second[j] = *unused.begin();
                unused.erase(unused.begin());
            }
        }
        for (int i = 0; i < n; ++i) {
            sort(v[i].second.begin(), v[i].second.end());
        }
    }
    sort(v.begin(), v.end(), [&](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    int L = -1, R = -1;
    int ans = -1;

    auto upd = [&](int i, int j) {
        int i1 = 0, i2 = 0;
        while (i1 < 5 && i2 < 5) {
            if (v[i].second[i1] == v[j].second[i2]) return;
            if (v[i].second[i1] < v[j].second[i2]) ++i1;
            else ++i2;
        }
        int cur = v[i].first + v[j].first;
        if (ans != -1 && cur >= ans) return;
        ans = cur;
        L = i;
        R = j;
    };

    show(v);

    gp_hash_table<A, int, hash_my> cnt;

    auto get_cnt = [&](const A& a) {
        int cur_cnt = 0;
        for (int mask = 0; mask < 32; ++mask) {
            A cur;
            cur.fill(-1);
            int icur = 0;
            for (int j = 0; j < 5; ++j) {
                if ((mask >> j) & 1)
                    cur[icur++] = a[j];
            }
            int c = cnt[cur];
            if (__builtin_popcount(mask) % 2 == 0) {
                cur_cnt += c;
            } else {
                cur_cnt -= c;
            }
        }
        return cur_cnt;
    };

    for (int i = 0; i < v.size(); ++i) {
        const auto& [w, a] = v[i];
        int cur_cnt = get_cnt(a);
        if (cur_cnt != 0) {
            for (int j = 0; j <= i; ++j) {
                upd(j, i);
                if (ans != -1) break;
            }
            assert(ans != -1);
            break;
        }
        for (int mask = 0; mask < 32; ++mask) {
            A cur;
            cur.fill(-1);
            int icur = 0;
            for (int j = 0; j < 5; ++j) {
                if ((mask >> j) & 1)
                    cur[icur++] = a[j];
            }
            cnt[cur]++;
        }
    }

    for (int i = L + 1; i < R; ++i) {
        const auto& a = v[i].second;
        for (int mask = 0; mask < 32; ++mask) {
            A cur;
            cur.fill(-1);
            int icur = 0;
            for (int j = 0; j < 5; ++j) {
                if ((mask >> j) & 1)
                    cur[icur++] = a[j];
            }
            cnt[cur]--;
        }
    }

    for (int i = R + 1; i < n; ++i) {
        if (get_cnt(v[i].second) == 0) continue;
        do {
            const auto& a = v[L].second;
            for (int mask = 0; mask < 32; ++mask) {
                A cur;
                cur.fill(-1);
                int icur = 0;
                for (int j = 0; j < 5; ++j) {
                    if ((mask >> j) & 1)
                        cur[icur++] = a[j];
                }
                cnt[cur]--;
            }
            --L;
        } while (get_cnt(v[i].second) != 0);
        ans = min(ans, v[i].first + v[L + 1].first);
    }

    cout << ans << '\n';

    return 0;
}