#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
int n, m;

vector<ll> get_vec(vector<ll> a) {
    vector<ll> t(a.size() - 2);
    for (int i = 0; i + 2 < a.size(); i++) {
        t[i] = a[i] + 2 * a[i + 1] + a[i + 2];
    }
    return t;
}

const int mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1 << 20;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

void fft(vector<int> &a, bool invert) {
    int n = (int) a.size();

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = int(wlen * 1ll * wlen % mod);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j], v = int(a[i + j + len / 2] * 1ll * w % mod);
                a[i + j] = u + v < mod ? u + v : u + v - mod;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                w = int(w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = pw(n, mod - 2);
        for (int i = 0; i < n; ++i)
            a[i] = int(a[i] * 1ll * nrev % mod);
    }
}

void poly_mult(vector<int> &a, vector<int> b) {
    int s = a.size() + b.size();
    int r = 1;
    while (r < s) r *= 2;
    a.resize(r);
    b.resize(r);
    fft(a, false);
    fft(b, false);
    for (int j = 0; j < r; j++) {
        a[j] = mult(a[j], b[j]);
    }
    fft(a, true);
    while (!a.empty() && (a.back() == 0)) a.pop_back();
}


vector<bool> check(vector<ll> &fa, vector<ll> &fb) {
    vector<int> f_reda(fa.size());
    vector<int> f_redb(fb.size());
    for (int i = 0; i < fa.size(); i++) {
        f_reda[i] = ((fa[i] % mod) + mod) % mod;
    }

    for (int i = 0; i < fb.size(); i++) {
        f_redb[i] = ((fb[i] % mod) + mod) % mod;
    }



    //fa[i + j] * fb[fb.size() - 1 - j]

    vector<ll> prefa(fa.size() + 1);
    vector<ll> prefb(fb.size() + 1);


    vector<int> pref_sa(fa.size() + 1);
    vector<int> pref_sb(fb.size() + 1);
    for (int i = 0; i < fa.size(); i++) {
        prefa[i + 1] = prefa[i] + fa[i];
        pref_sa[i + 1] = sum(pref_sa[i], mult(f_reda[i], f_reda[i]));
    }

    for (int i = 0; i < fb.size(); i++) {
        prefb[i + 1] = prefb[i] + fb[i];
        pref_sb[i + 1] = sum(pref_sb[i], mult(f_redb[i], f_redb[i]));
    }


    reverse(f_redb.begin(), f_redb.end());

    poly_mult(f_reda, f_redb);


    ll S = prefb.back();
    int S_sq = pref_sb.back();
    //i + j, fb.size() - 1 - j

    if (m == 2) {
        return vector<bool>(n - m + 1, true);
    }

    assert(m > 2);

    f_reda.resize(n + m);
    //i + j, fb.size() - 1 - j

    vector<bool> is_ok(n - m + 1);
//    cout << " HI " << endl;
//    for (ll x : fa) cout << x << " ";
//    cout << endl;
//    for (ll x : fb) cout << x << " ";

    for (int i = 0; i <= n - m; i++) {
        ll we = prefa[i + m - 2] - prefa[i];
        ll D = S - we;
        if (D >= 0 && D <= (m - 2)) {
            //[a_{i + j} - b_{j}]^2
            int T = sum(sub(pref_sa[i + m - 2], pref_sa[i]), S_sq);
            T = sub(T, mult(2, f_reda[i + fb.size() - 1]));
            if (T == D % mod) {
//                cout << T << " " << D << endl;
                is_ok[i] = true;
            }
        }
    }
    return is_ok;
}


void solve() {
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vector<ll> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    auto fa = get_vec(a);
    auto fb = get_vec(b);
    auto res = check(fa, fb);
    assert(res.size() == n - m + 1);
    for (int i = 0; i <= n - m; i++) {
        if (res[i]) {
//            cout << i << " hi " << endl;
            ll a0 = a[i];
            ll a1 = a[i] + a[i + 1];
            ll b0 = b[0];
            ll b1 = b[0] + b[1];
            ll D = b1 - a1;

            ll LIM1 = (i / 2) + 1;
            ll LIM2 = (i + 1) / 2;
            ll F = b0 - a0;
            //0 .. LIM1 - 1
            //+2 * t + 1
            //0 .. LIM2 - 1
            //2 * t + 2

            //+1 -2
            //-X + Y = D
            //a[0] + 2 * a[1] + a[2]
            //v 1 -> +1 k a1
            for (int add = 0; add <= 1; add++) {
                //a[1]
                D -= add;
                //-X + Y = D
                if (-LIM1 <= D && D <= LIM2) {
//                    cout << " YA " << D << " " << F << " " << LIM1 << " " << LIM2 << endl;
                    //3, 2
                    //2, 1

                    //1, 3, 5
                    //2, 4



                    //0, 2, 3
                    //4
                    //1, 3
                    //+3, +5
                    //-2

                    //1+3+5+7+9
                    //-2 -4 -6 -8
                    //new x
                    //Y = D + X <= LIM2


                    vector<ll> coefs;
                    coefs.emplace_back(0);
                    coefs.emplace_back( D);
                    coefs.emplace_back(LIM1);
                    coefs.emplace_back(LIM2 - D);
                    auto to_check = [&](ld A, ld B, ld C) {
                        if (B * B < 4 * A * C) return;
                        ld D = sqrt(B * B - 4 * A * C);
                        coefs.emplace_back((-B - D) / (2 * A));
                        coefs.emplace_back((-B + D) / (2 * A));
                    };


                    //max(X^2, F + Y^2 + Y) <= X + X * (2 * LIM1 - 1 - X)
                    //Y = D + X
                    //X^2 + Y^2 >= 0
                    //F >= X^2 - Y * (LIM2 + 1 + LIM2 - Y) = X^2 + Y^2 - Y * (2 * LIM2 + 1)
                    //F >= X^2 + (X + D)^2 - (X + D) * (2 * LIM2 + 1)


                    //X * (2 * LIM1) - Y >= F + X^2 + Y^2
                    //F + X^2 + (X + D)^2 + (X + D) - X * 2 * LIM1

                    to_check(2, 2 * D - 2 * (LIM2 + 1) + 1, D * D - D * (2 * LIM2 + 1) - F);
                    to_check(2, 2 * D - 2 * LIM1, D * D + D + F);


                    for (auto &it: coefs) {
                        for (int p = -2; p <= 2; p++) {
                            ll X = it + p;
                            if ((X + F) % 2 != 0) continue;

                            ll Y = D + X;
                            if (Y < 0) continue;
                            if (Y > LIM2 || Y < 0 || X < 0 || X > LIM1) continue;
//                            cout << X << " " << Y << " ?? " << " ZZ " << endl;
                            ll mn_x = X + X * (X - 1);
                            ll mx_x = X + ((X * (LIM1 - 1 + LIM1 - X)));
                            ll mn_y = 2 * Y + Y * (Y - 1);
                            ll mx_y = 2 * Y + ((Y * (LIM2 - 1 + LIM2 - Y)));
                            if (mx_x - mn_y >= F && F >= mn_x - mx_y) {
                                ll val_x = max(mn_x, F + mn_y);
                                ll val_y = val_x - F;


                                auto produce = [&](ll S, ll LIM, ll cnt) {
                                    vector<int> ans;
                                    for (ll i = LIM; i >= 0; i--) {
                                        if (i >= cnt && S <= cnt * (i - cnt + i - 1) / 2 && S >= (cnt * (cnt - 1)) / 2) {

                                        } else {
                                            ans.emplace_back(i);
                                            S -= i;
                                            cnt -= 1;
                                        }
                                    }
                                    assert(S == 0 && cnt == 0);
                                    return ans;
                                };
                                val_x -= X;
                                val_y -= 2 * Y;
//                                if (val_x % 2 != 0 || val_y % 2 != 0) exit(0);
                                assert(val_x % 2 == 0 && val_y % 2 == 0);
                                auto res1 = produce(val_x / 2, LIM1 - 1, X);
                                auto res2 = produce(val_y / 2, LIM2 - 1, Y);
                                vector<int> fin_ans;
                                if (add) {
                                    fin_ans.emplace_back(i + 1);
                                }
                                for (int p = 0; p < m - 2; p++) {
                                    assert(fb[p] - fa[i + p] == 0 || fb[p] - fa[i + p] == 1);
                                    if (fb[p] - fa[i + p] == 1) {
                                        fin_ans.emplace_back(i + 2 + p);
                                    }
                                }
                                for (int t = 0; t < res1.size(); t++) {
                                    fin_ans.emplace_back(i - 2 * res1[t]);
                                }
                                for (int t = 0; t < res2.size(); t++) {
                                    fin_ans.emplace_back(i - 1 - 2 * res2[t]);
                                }
                                cout << fin_ans.size() << '\n';
                                for (int v: fin_ans) cout << v + 1 << " ";
                                cout << '\n';
                                return;

                            }
                        }
                    }
                    //X^2 + (X + D)^2 - (X + D)
                    //[l1 .. r1]
                    //[l2 .. r2]

                    //X^2 + (X + D)^2 <=
                    //~D + LIM2
                    //X * (2 * LIM1) - X^2 - Y^2 - Y >= F

                    //+1, -2, +3, -4, +5, -6, +7

                    //[l1 .. l2]
                    //[r1 .. r2]
                    //-X + Y =


                }

            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }

    return 0;
}