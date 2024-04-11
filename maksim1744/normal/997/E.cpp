/*
    author:  Maksim1744
    created: 27.07.2021 21:52:36
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
#include "/home/maksim/cpplibs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

const int N = 250000;
// const int N = 250;

struct ar_counter {
    array<pair<int, int>, N> a;
    int step = 0;

    ar_counter() {
        a.fill({0, -1});
    }

    void reset() {
        ++step;
    }

    int &operator[](int i) {
        if (a[i].second != step) a[i].first = 0;
        a[i].second = step;
        return a[i].first;
    }
};

struct slow_ar_counter {
    map<int, int> m;

    slow_ar_counter() {
    }

    void reset() {
        m.clear();
    }

    int &operator[](int i) {
        return m[i];
    }
};

struct mydeq {
    vector<int> v;
    int start = 0;

    void push(int k) {
        v.pb(k);
    }

    void pop() {
        ++start;
    }

    void clear() {
        v.clear();
        start = 0;
    }

    int calc_at_least(int k) const {
        int sz = v.size() - start;
        if (sz == 0) return 0;
        if (sz == 1) return v[start] >= k;
        if (v[start] < v[start + 1]) {
            return v.size() - (lower_bound(v.begin() + start, v.end(), k) - v.begin());
        } else {
            return sz - (lower_bound(v.rbegin(), v.rbegin() + sz, k) - v.rbegin());
        }
    }

    void push_back(int k) { push(k); }
    void push_front(int k) { push(k); }

    void pop_back() { pop(); }
    void pop_front() { pop(); }
};

struct deq_counter {
    array<mydeq, N> a;
    vector<int> touched;

    deq_counter() {
    }

    void reset() {
        for (int k : touched) {
            a[k].clear();
        }
        touched.clear();
    }

    auto& operator[](int i) {
        touched.pb(i);
        return a[i];
    }
};

ar_counter cnt;
deq_counter cntd;

auto start_time = clock();

mt19937 rng(123234);
int rnd(int l, int r) {
    return rng() % (r - l + 1) + l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n);
    cin >> p;
    --p;

    int M = N / 2;
    vector<int> mn(n);
    vector<int> mx(n);

    auto calc = y_combinator([&](auto calc, const vector<int> &p, int l, int r) -> ll {
        if (l > r) return 0;
        if (l == r) return 1;
        int m = (l + r) / 2;

        mn[m] = mx[m] = p[m];
        mn[m + 1] = mx[m + 1] = p[m + 1];
        for (int i = m - 1; i >= l; --i) {
            mn[i] = min(mn[i + 1], p[i]);
            mx[i] = max(mx[i + 1], p[i]);
        }
        for (int i = m + 2; i <= r; ++i) {
            mn[i] = min(mn[i - 1], p[i]);
            mx[i] = max(mx[i - 1], p[i]);
        }

        ll ans = 0;

        // max on the right, min on the left
        {
            int curmin, curmax;
            curmax = curmin = p[m + 1];
            int L = m + 1, R = m;
            for (int i = m + 1; i <= r; ++i) {
                curmax = max(curmax, p[i]);
                curmin = min(curmin, p[i]);

                while (L - 1 >= l && mx[L - 1] < curmax) {
                    --L;
                    cnt[M - (m - L) - mn[L]]++;
                }
                while (R >= L && mn[R] > curmin) {
                    cnt[M - (m - R) - mn[R]]--;
                    --R;
                }

                ans += cnt[M - (mx[i] - (i - m))];
            }
            cnt.reset();
        }
        // max on the left, min on the right
        {
            int curmin, curmax;
            curmax = curmin = p[m + 1];
            int L = m + 1, R = m;
            for (int i = m + 1; i <= r; ++i) {
                curmax = max(curmax, p[i]);
                curmin = min(curmin, p[i]);

                while (L - 1 >= l && mn[L - 1] > curmin) {
                    --L;
                    cnt[M - (m - L) + mx[L]]++;
                }
                while (R >= L && mx[R] < curmax) {
                    cnt[M - (m - R) + mx[R]]--;
                    --R;
                }

                ans += cnt[M - (-mn[i] - (i - m))];
            }
            cnt.reset();
        }
        // both on the right
        {
            int curmin, curmax;
            curmax = curmin = p[m + 1];
            int L = m + 1;
            for (int i = m + 1; i <= r; ++i) {
                curmax = max(curmax, p[i]);
                curmin = min(curmin, p[i]);

                while (L - 1 >= l && mn[L - 1] > curmin && mx[L - 1] < curmax) {
                    --L;
                    cnt[M - (m - L)]++;
                }

                ans += cnt[M - (-mn[i] + mx[i] - (i - m))];
            }
            cnt.reset();
        }
        // both on the left
        {
            int curmin, curmax;
            curmax = curmin = p[m + 1];
            int L = l, R = m;
            for (int i = l; i <= m; ++i) {
                cnt[M - (m - i) + mx[i] - mn[i]]++;
            }
            for (int i = m + 1; i <= r; ++i) {
                curmax = max(curmax, p[i]);
                curmin = min(curmin, p[i]);

                while (R >= L && (mx[R] < curmax || mn[R] > curmin)) {
                    cnt[M - (m - R) + mx[R] - mn[R]]--;
                    --R;
                }

                ans += cnt[M - (- (i - m))];
            }
            cnt.reset();
        }
        ll ansl = calc(p, l, m);
        ll ansr = calc(p, m + 1, r);
        return ans + ansl + ansr;
    });

    int q;
    cin >> q;

    const int B = 500;
    
    vector<pair<int, int>> que(q);
    cin >> que;
    --que;
    vector<ll> ans(q, 0);

    vector<vector<int>> withmid(n / B + 1);

    for (int i = 0; i < q; ++i) {
        if (que[i].first / B == que[i].second / B) {
            ans[i] = calc(p, que[i].first, que[i].second);
            continue;
        } else {
            withmid[que[i].second / B].pb(i);
        }
    }


    vector<ll> pref(n, 0);

    auto calc_pref = y_combinator([&](auto calc_pref, const vector<int> &p, int l, int r) -> void {
        if (l > r) return;
        if (l == r) {
            pref[l]++;
            return;
        }
        int m = (l + r) / 2;

        mn[m] = mx[m] = p[m];
        mn[m + 1] = mx[m + 1] = p[m + 1];
        for (int i = m - 1; i >= l; --i) {
            mn[i] = min(mn[i + 1], p[i]);
            mx[i] = max(mx[i + 1], p[i]);
        }
        for (int i = m + 2; i <= r; ++i) {
            mn[i] = min(mn[i - 1], p[i]);
            mx[i] = max(mx[i - 1], p[i]);
        }

        // max on the right, min on the left
        {
            int curmin, curmax;
            curmax = curmin = p[m + 1];
            int L = m + 1, R = m;
            for (int i = m + 1; i <= r; ++i) {
                curmax = max(curmax, p[i]);
                curmin = min(curmin, p[i]);

                while (L - 1 >= l && mx[L - 1] < curmax) {
                    --L;
                    cnt[M - (m - L) - mn[L]]++;
                }
                while (R >= L && mn[R] > curmin) {
                    cnt[M - (m - R) - mn[R]]--;
                    --R;
                }

                pref[i] += cnt[M - (mx[i] - (i - m))];
            }
            cnt.reset();
        }
        // max on the left, min on the right
        {
            int curmin, curmax;
            curmax = curmin = p[m + 1];
            int L = m + 1, R = m;
            for (int i = m + 1; i <= r; ++i) {
                curmax = max(curmax, p[i]);
                curmin = min(curmin, p[i]);

                while (L - 1 >= l && mn[L - 1] > curmin) {
                    --L;
                    cnt[M - (m - L) + mx[L]]++;
                }
                while (R >= L && mx[R] < curmax) {
                    cnt[M - (m - R) + mx[R]]--;
                    --R;
                }

                pref[i] += cnt[M - (-mn[i] - (i - m))];
            }
            cnt.reset();
        }
        // both on the right
        {
            int curmin, curmax;
            curmax = curmin = p[m + 1];
            int L = m + 1;
            for (int i = m + 1; i <= r; ++i) {
                curmax = max(curmax, p[i]);
                curmin = min(curmin, p[i]);

                while (L - 1 >= l && mn[L - 1] > curmin && mx[L - 1] < curmax) {
                    --L;
                    cnt[M - (m - L)]++;
                }

                pref[i] += cnt[M - (-mn[i] + mx[i] - (i - m))];
            }
            cnt.reset();
        }
        // both on the left
        {
            int curmin, curmax;
            curmax = curmin = p[m + 1];
            int L = l, R = m;
            for (int i = l; i <= m; ++i) {
                cnt[M - (m - i) + mx[i] - mn[i]]++;
            }
            for (int i = m + 1; i <= r; ++i) {
                curmax = max(curmax, p[i]);
                curmin = min(curmin, p[i]);

                while (R >= L && (mx[R] < curmax || mn[R] > curmin)) {
                    cnt[M - (m - R) + mx[R] - mn[R]]--;
                    --R;
                }

                pref[i] += cnt[M - (- (i - m))];
            }
            cnt.reset();
        }
        calc_pref(p, l, m);
        calc_pref(p, m + 1, r);
    });

    auto pr = p;
    reverse(pr.begin(), pr.end());

    for (int i = 0; i < withmid.size(); ++i) {
        if (i * B >= n) break;
        int r = min(n - 1, (i + 1) * B - 1);
        for (int j = i * B; j <= r; ++j) pref[j] = 0;
        calc_pref(p, i * B, r);
        for (int j = i * B + 1; j <= r; ++j)
            pref[j] += pref[j - 1];
        for (int ind : withmid[i])
            ans[ind] += pref[que[ind].second];

        for (int j = n - 1 - (i * B - 1); j <= n - 1; ++j) pref[j] = 0;
        calc_pref(pr, n - 1 - (i * B - 1), n - 1);
        for (int j = n - 1 - (i * B - 1) + 1; j <= n - 1; ++j) pref[j] += pref[j - 1];
        for (int ind : withmid[i])
            ans[ind] += pref[n - 1 - que[ind].first];
    }


    auto get_in_interval = [&](const mydeq &d, const pair<int, int> &p) {
        return d.calc_at_least(p.first);
    };

    vector<vector<int>> addto(n);

    for (int mid = B; mid < n; mid += B) {
        int m = mid - 1;
        int l = 0;
        int r = min(n - 1, m + B);

        {
            mn[m] = mx[m] = p[m];
            mn[m + 1] = mx[m + 1] = p[m + 1];
            for (int i = m - 1; i >= l; --i) {
                mn[i] = min(mn[i + 1], p[i]);
                mx[i] = max(mx[i + 1], p[i]);
            }
            for (int i = m + 2; i <= r; ++i) {
                mn[i] = min(mn[i - 1], p[i]);
                mx[i] = max(mx[i - 1], p[i]);
            }

            // max on the right, min on the left
            {
                int curmin, curmax;
                curmax = curmin = p[m + 1];
                int L = m + 1, R = m;
                for (int i = m + 1; i <= r; ++i) {
                    curmax = max(curmax, p[i]);
                    curmin = min(curmin, p[i]);

                    while (L - 1 >= l && mx[L - 1] < curmax) {
                        --L;
                        cntd[M - (m - L) - mn[L]].push_front(L);
                    }
                    while (R >= L && mn[R] > curmin) {
                        cntd[M - (m - R) - mn[R]].pop_back();
                        --R;
                    }

                    for (int ind : withmid[i / B])
                        if (i <= que[ind].second)
                            ans[ind] += get_in_interval(cntd[M - (mx[i] - (i - m))], que[ind]);
                }
                cntd.reset();
            }
            // max on the left, min on the right
            {
                int curmin, curmax;
                curmax = curmin = p[m + 1];
                int L = m + 1, R = m;
                for (int i = m + 1; i <= r; ++i) {
                    curmax = max(curmax, p[i]);
                    curmin = min(curmin, p[i]);

                    while (L - 1 >= l && mn[L - 1] > curmin) {
                        --L;
                        cntd[M - (m - L) + mx[L]].push_front(L);
                    }
                    while (R >= L && mx[R] < curmax) {
                        cntd[M - (m - R) + mx[R]].pop_back();
                        --R;
                    }

                    for (int ind : withmid[i / B])
                        if (i <= que[ind].second)
                            ans[ind] += get_in_interval(cntd[M - (-mn[i] - (i - m))], que[ind]);
                }
                cntd.reset();
            }
            // both on the right
            {
                int curmin, curmax;
                curmax = curmin = p[m + 1];
                int L = m + 1;
                for (int i = m + 1; i <= r; ++i) {
                    curmax = max(curmax, p[i]);
                    curmin = min(curmin, p[i]);

                    while (L - 1 >= l && mn[L - 1] > curmin && mx[L - 1] < curmax) {
                        --L;
                        cntd[M - (m - L)].push_front(L);
                    }

                    for (int ind : withmid[i / B])
                        if (i <= que[ind].second)
                            ans[ind] += get_in_interval(cntd[M - (-mn[i] + mx[i] - (i - m))], que[ind]);
                }
                cntd.reset();
            }
            // both on the left
            {
                int curmin, curmax;
                curmax = curmin = p[m + 1];
                int L = l, R = m;
                for (int i = m; i >= l; --i) {
                    cntd[M - (m - i) + mx[i] - mn[i]].push_back(i);
                }
                for (int i = m + 1; i <= r; ++i) {
                    curmax = max(curmax, p[i]);
                    curmin = min(curmin, p[i]);

                    while (R >= L && (mx[R] < curmax || mn[R] > curmin)) {
                        cntd[M - (m - R) + mx[R] - mn[R]].pop_back();
                        --R;
                    }

                    for (int ind : withmid[i / B])
                        if (i <= que[ind].second)
                            ans[ind] += get_in_interval(cntd[M - (- (i - m))], que[ind]);
                }
                cntd.reset();
            }
        }
    }


    for (ll k : ans)
        cout << k << '\n';

    return 0;
}