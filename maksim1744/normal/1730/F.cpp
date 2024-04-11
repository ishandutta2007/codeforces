/*
    author:  Maksim1744
    created: 25.09.2022 18:48:32
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

const int K = 8;
array<int, 1 << (K * 2)> dp, nx;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    cin >> p;
    --p;
    vector<int> ind(n);
    for (int i = 0; i < n; ++i) {
        ind[p[i]] = i;
    }
    vector<int> far(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i - k * 2 - 1; ++j) {
            if (ind[j] > ind[i])
                far[i]++;
        }
    }

    {
        int bad = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                bad += (p[j] > p[i] + k);
        if (bad == 0) {
            cout << 0 << '\n';
            return 0;
        }
    }

    const int inf = 1e9;
    dp.fill(inf);
    nx.fill(inf);

    int shift = k - 1;
    for (int i = 0; i < n && i <= k; ++i)
        dp[1 << (i + shift)] = 0;

    ll ie = 0;

    for (int i = 1; i < n; ++i) {
        if (i % 100 == 0)
            cerr << i << ' ' << ie << ' ' << ie / i << endl;
        for (int j = 0; j < (1 << (k * 2)); ++j) {
            nx[j] = inf;
        }
        shows;
        for (int mask = 0; mask < (1 << (k * 2)); ++mask) {
            show(mask);
            int cur = dp[mask];
            if (cur == inf) continue;
            ++ie;
            int L = max(i - k, 0);
            int R = min(i + k, n - 1);
            if (mask) {
                int ind = (k * 2);
                while (!(mask >> ind)) --ind;
                int val = i - 1 + ind - shift;
                L = max(L, val - k);
            }
            {
                int ind = 0;
                while (i - 1 + ind - shift < 0) ++ind;
                while ((mask >> ind) & 1) ++ind;
                int val = i - 1 + ind - shift;
                R = min(R, val + k);
            }
            for (int j = L; j <= R; ++j) {
                // int nmask = (mask >> 1);
                // int bit = j - i + shift;
                // show(bit, k);
                // assert(bit >= -1 && bit < k * 2);
                // if (bit != -1 && (nmask & (1 << bit))) continue;
                // if (bit >= 0) nmask |= (1 << bit);
                // int inv = 0;
                show(j);


                int nmask = mask;
                int bit = j - i + shift;
                assert(bit >= -1 && bit < k * 2);
                ++bit;
                show(nmask, bit);
                if ((nmask >> bit) & 1) continue;
                nmask |= (1 << bit);
                show(bit, k, nmask);
                if (i - k >= 0 && !(nmask & 1)) continue;
                nmask >>= 1;
                int inv = 0;


                for (int x = 0; x < (k * 2); ++x) {
                    if ((mask >> x) & 1) {
                        assert(i - 1 + x - shift <= j + k);
                        inv += (ind[i - 1 + x - shift] > ind[j]);
                        show(j, x, inv);
                    }
                }
                assert(j - k * 2 <= (i - 1) - (k - 1));
                for (int x = max(0, j - k * 2); x < (i - 1) - (k - 1); ++x) {
                    inv += (ind[x] > ind[j]);
                    show(j, x, inv);
                }
                // show(nmask, cur + inv);
                show(mask, nmask, cur, inv, j);
                nx[nmask] = min(nx[nmask], cur + inv + far[j]);
            }
        }
        swap(nx, dp);
        show(i, dp);
    }

    cerr << ie << endl;
    cout << dp[(1 << k) - 1] << '\n';

    return 0;
}