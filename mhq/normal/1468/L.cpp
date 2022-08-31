#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = 1005;
ll x[maxN];
const int BUBEN2 = 15;
mt19937 rnd(228);
long long multModulo(long long a, long long b, long long m) {
    long long q = (long long) ((long double) a * (long double) b / (long double) m);
    long long r = a * b - q * m;
    while (r < 0) r += m;
    while (r >= m) r -= m;
    return r;
}
ll powModulo(ll a, ll b, ll mod) {
    if (b == 0) return 1;
    if (b & 1) return multModulo(a, powModulo(a, b - 1, mod), mod);
    ll res = powModulo(a, b / 2, mod);
    return multModulo(res, res, mod);
}
bool is_prime(ll n) {
    if (n == 1) return false;
    if (n == 2 || n == 3 || n == 5 || n == 7) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) {
        return false;
    }
    ll d = n - 1;
    int r = 0;
    // can add
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }
    for (int j = 0; j < BUBEN2; j++) {
        ll a = rnd() % (n - 3) + 2;
        ll x = powModulo(a, d, n);
        if (x == 1 || x == n - 1) {
            continue;
        }
        for (int it = 0; it < r - 1; it++) {
            x = multModulo(x, x, n);
            if (x == n - 1) {
                break;
            }
        }
        if (x != (n - 1)) {
            return false;
        }
    }
    return true;
}
bool check(ll a, int k, ll c) {
    //check a >= c^k
    while (k) {
        if (k & 1) {
            a /= c;
            k--;
            if (!a) return false;
        }
        else {
            if ((a / c) < c) return false;
            k /= 2;
            c *= c;
        }
    }
    return a != 0;
}
ll pw(ll a, int i) {
    if (i == 0) return 1;
    if (i & 1) return a * pw(a, i - 1);
    ll res = pw(a, i / 2);
    return res * res;
}
ll check(ll x) {
    for (int i = 64; i >= 1; i--) {
        ll f = pow((ld)x, 1.0 / i) + 2;
        while (!check(x, i, f)) f--;
        if (pw(f, i) == x) {
            if (is_prime(f)) return f;
            else return -1;
        }
    }
    return -1;
}
bool can[maxN];
vector<ll> he[maxN];
bool mark[maxN];
bool prPw[maxN];
ll par[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    map<ll,vector<int>> good;

    map<ll,int> sz;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        ll D = check(x[i]);
        if (D != -1) {
            par[i] = D;
            prPw[i] = true;
            good[D].emplace_back(i);
            sz[D]++;
        }
    }
    vector<ll> real_good;
    for (auto& it : good) {
        if (it.second.size() >= 2) {
            real_good.emplace_back(it.first);
            for (auto& pit : it.second) {
                can[pit] = true;
            }
        }
    }
    if (k == 1) {
        cout << 0;
        return 0;
    }
    int tot_sz = 0;
    for (int i = 1; i <= n; i++) {
        if (prPw[i]) {
            if (can[i]) {
                mark[i] = true;
                tot_sz++;
            }
            continue;
        }
        ll st = x[i];
        for (auto& it : real_good) {
            if (st % it == 0) {
                he[i].emplace_back(it);
                while (st % it == 0) {
                    st /= it;
                }
            }
        }
        if (st == 1) {
            mark[i] = true;
            tot_sz++;
//            lft.emplace_back(i);
        }
    }
    if (tot_sz < k) {
        cout << 0;
        return 0;
    }
    int mn = 1e8;
    int when = -1;
    for (int i = 1; i <= n; i++) {
        if (mark[i] && !can[i]) {
            mn = min(mn, (int)he[i].size());
            if (mn == (int)he[i].size()) when = i;
        }
    }
    int cnt_big = 0;
    for (auto& it : real_good) {
        cnt_big += sz[it] >= 3;
    }
    if (k % 2 == 0) {
        for (int i = 1; i <= n; i++) {
            if (mark[i] && !can[i] && tot_sz > k) {
                mark[i] = false;
                tot_sz--;
            }
        }
        if (k != tot_sz) {
            for (int i = 1; i <= n; i++) {
                if (mark[i] && can[i]) {
                    int del = min(sz[par[i]], tot_sz - k);
                    int lft = sz[par[i]] - del;
                    if (lft == 1) {
                        assert(del >= 1);
                        del--;
                    }
                    if (lft == 0) {
                        for (int x : good[par[i]]) {
                            mark[x] = false;
                        }
                        tot_sz -= del;
                        sz[par[i]] = 0;
                    }
                    else {
                        if (del >= 1) {
                            mark[i] = false;
                            sz[par[i]]--;
                            tot_sz--;
                        }
                    }
                }
            }
        }
        assert(k == tot_sz);
    }
    else {
        if (k < 2 * mn + 1 && cnt_big == 0) {
            cout << 0;
            return 0;
        }
        if (cnt_big != 0) {
            for (int i = 1; i <= n; i++) {
                if (mark[i] && !can[i] && tot_sz > k) {
                    mark[i] = false;
                    tot_sz--;
                }

            }
            if (tot_sz != k) {
                vector<int> xx;
                for (int i = 1; i <= n; i++) {
                    if (mark[i] && can[i]) xx.emplace_back(i);
                }
                sort(xx.begin(), xx.end(), [&](int a, int b) {
                    return sz[par[a]] < sz[par[b]];
                });

                for (int i : xx) {
                    if (mark[i] && can[i]) {
                        int del = min(sz[par[i]], tot_sz - k);
                        int lft = sz[par[i]] - del;
                        if (lft == 1) {
                            assert(del >= 1);
                            del--;
                        }
                        if (lft == 0) {
                            for (int x : good[par[i]]) {
                                mark[x] = false;
                            }
                            tot_sz -= del;
                            sz[par[i]] = 0;
                        }
                        else {
                            if (del >= 1) {
                                mark[i] = false;
                                sz[par[i]]--;
                                tot_sz--;
                            }
                        }
                    }
                }
                assert(tot_sz == k);
            }
        }
        else {
            map<ll,int> ff;
            for (ll D : he[when]) {
                ff[D] = 1;
            }
            for (int i = 1; i <= n; i++) {
                if (mark[i] && !can[i] && tot_sz > k && i != when) {
                    mark[i] = false;
                    tot_sz--;
                }
            }
            if (tot_sz > k) {
                assert(tot_sz % 2 == 1);
                for (int i = 1; i <= n; i++) {
                    if (mark[i] && can[i] && tot_sz > k && !ff.count(par[i])) {
                        for (int v : good[par[i]]) {
                            tot_sz--;
                            mark[v] = false;
                        }
                    }
                }
                assert(tot_sz == k);
            }
        }
    }
    for (int i = 1; i <= n; i++) if (mark[i]) cout << x[i] << " ";


    return 0;
}