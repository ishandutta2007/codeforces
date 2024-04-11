#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define x first
#define y second
#define pi pair<ll, int>
#define vi vector<int>
using namespace std;
const int N = 600 + 10, P = 1e9 + 7;
int n, k, a[N], opt[N], tot = 0, p2[N], cnt[2][N];
vi operator + (const vi a, const vi b) {
    vi c = a;
    if(sz(c) < sz(b)) c.resize(sz(b));
    FOR(i, 0, sz(b) - 1) (c[i] += b[i]) %= P;
    return c;
}
vi operator * (const vi a, const vi b) {
    vi c(sz(a) + sz(b) - 1);
    FOR(i, 0, sz(a) - 1) FOR(j, 0, sz(b) - 1) {
        (c[i + j] += (ll)a[i] * b[j] % P) %= P;
    }
    return c;
}
int main() {
    cin >> n >> k;
    p2[0] = 1;
    FOR(i, 1, n) cin >> a[i], p2[i] = (ll)p2[i - 1] * 2 % P;
    int zero = 0;
    FOR(i, 1, n) {
        if(a[i] == 0) zero++;
        else a[++tot] = a[i];
    }
    sort(a + 1, a + tot + 1, [&](int x, int y) {
        return abs(x) > abs(y);
    });
    FOR(i, 1, tot) {
        if(a[i] > 0) cnt[0][i] = 1;
        else cnt[1][i] = 1;
        opt[i] = a[i];
        a[i] = (a[i] + P) % P;
    }
    ROF(i, tot, 1) FOR(j, 0, 1) cnt[j][i] += cnt[j][i + 1];
    vector<int> pos, neg;
    FOR(i, 1, tot) {
        if(opt[i] > 0) pos.emplace_back(i);
        else neg.emplace_back(i);
    }
    int sump = 0, sumn = 0;
    vi arr = {1};
    for(auto i : pos) {
        if(sz(arr) >= k) (sump += (ll)arr[k - 1] * a[i] % P * p2[tot - i] % P) %= P;
        arr = arr * vi{1, a[i]};
    }
    arr = {1};
    if(k & 1) {
        ROF(i, sz(neg) - 1, 0) {
            int x = neg[i];
            if(sz(arr) >= k) {
                (sumn += (ll)arr[k - 1] * a[x] % P * p2[i] % P) %= P;
            }
            arr = arr * vi{1, a[x]};
        }
        arr = {1};
        for(auto i : neg) {
            if(sz(arr) >= k) {
                int cnt = 0;
                FOR(j, i + 1, tot) {
                    if(opt[j] > 0) (sump += (ll)arr[k - 1] * a[j] % P * p2[tot - j + cnt] % P) %= P;
                    else cnt++;
                }
            }
            arr = arr * vi{1, a[i]};
        }
    } else {
        for(auto i : neg) {
            if(sz(arr) >= k) (sump += (ll)arr[k - 1] * a[i] % P * p2[tot - i] % P) %= P;
            arr = arr * vi{1, a[i]};
        }
    }
    if(k >= 2) {
        arr = {1};
        for(auto i : neg) {
            vi par[2] = {arr, arr};
            FOR(j, 0, sz(arr) - 1) par[!(j & 1)][j] = 0;
            for(auto j : pos) {
                // cout << i <<" " << j << endl;
                int t = max(i, j);
                if(sz(par[0]) >= k - 1) {
                    (sump += (ll)par[1][k - 2] * a[i] % P * a[j] % P * p2[tot - t] % P) %= P;
                    int prod = par[0][k - 2];
                    (sumn += (ll)prod * a[i] % P * a[j] % P) %= P;
                    FOR(k, t + 1, tot) {
                        if(opt[k] < 0) {
                            (sump += (ll)prod * a[i] % P * a[k] % P * p2[cnt[1][k + 1]] % P) %= P;
                        }
                    }
                    FOR(k, t + 1, tot) {
                        if(opt[k] > 0) {
                            (sump += (ll)prod * a[j] % P * a[k] % P * p2[cnt[0][k + 1]] % P) %= P;
                        }
                    }
                    vector<int> pa, na;
                    FOR(k, t + 1, tot) (opt[k] > 0 ? pa : na).emplace_back(k);
                    // for(auto k : pa) {
                    //     for(auto l : na) {
                    //         if((ll)opt[j] * opt[k] > (ll)opt[i] * opt[l]) {
                    //             (sump += (ll)prod * a[j] % P * a[k] % P * p2[cnt[0][k + 1] + cnt[1][l + 1]] % P) %= P;
                    //         } else {
                    //             (sump += (ll)prod * a[i] % P * a[l] % P * p2[cnt[0][k + 1] + cnt[1][l + 1]] % P) %= P;
                    //         }
                    //     }
                    // }
                    int sum1 = 0, sum2 = 0;
                    for(auto k : na) (sum2 += p2[cnt[1][k + 1]]) %= P;
                    int lst = -1;
                    for(auto k : pa) {
                        while(lst + 1 < sz(na) && (ll)opt[i] * opt[na[lst + 1]] >= (ll)opt[j] * opt[k]) {
                            int x = na[lst + 1];
                            (sum1 += (ll)p2[cnt[1][x + 1]] % P * a[x] % P) %= P;
                            (sum2 += P - (ll)p2[cnt[1][x + 1]] % P) %= P;
                            lst++;
                        }
                        (sump += (ll)prod * a[j] % P * a[k] % P * p2[cnt[0][k + 1]] % P * sum2 % P) %= P;
                        (sump += (ll)prod * a[i] % P * sum1 % P * p2[cnt[0][k + 1]] % P) %= P;
                    }
                }
                FOR(k, 0, 1) par[k] = par[k] * vi{1, a[j]};
            }
            arr = arr * vi{1, a[i]};
        }
    }
    sump = (ll)sump * p2[zero] % P;
    cout << (sumn + sump) % P << "\n";
    return 0;
}