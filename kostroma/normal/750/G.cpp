#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }

    /*while (true) {
        solve(false);
    }*/

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

void precalc() {

}

#define int li

//const int mod = 1000000007;

vector<int> get_bin(int s) {
    vector<int> res;
    while (s) {
        res.push_back(s & 1);
        s /= 2;
    }
    return res;
}

int dp[100][100][2];

void solve(bool read) {
    int s;
    cin >> s;
    //vector<vector<vector<int>>> dp;
    int ans = 0;
    for (int d1 = 0; ; ++d1) {
        int have1 = (1LL << (d1 + 1)) - 3;
        if (have1 > s) {
            break;
        }
        for (int d2 = 0; ; ++d2) {
            //cout << d1 << ' ' << d2 << endl;
            int del = (1LL << (d1 + 1)) + (1LL << (d2 + 1)) - 3;
            if (del > s) {
                break;
            }
            int rest = s % del;
            for (int k = 0; k <= d1 + d2; ++k) {
                if ((rest + k) % 2) {
                    continue;
                }
                if (rest + k == 0) {
                    if (d2 == 0) {
                        ++ans;
                    }
                    continue;
                }
                auto now = get_bin(rest + k);
                now.erase(now.begin());
                if (d2 > now.size()) {
                    continue;
                }
                for (int i = 0; i <= now.size(); ++i) {
                    for (int j = 0; j <= k; ++j) {
                        for (int r = 0; r < 2; ++r) {
                            dp[i][j][r] = 0;
                        }
                    }
                }
                //dp.assign(now.size() + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
                dp[0][0][0] = 1;
                for (int pref = 0; pref < now.size(); ++pref) {
                    for (int used = 0; used <= k; ++used) {
                        for (int nex = 0; nex < 2; ++nex) {
                            for (int use1 = 0; use1 < 2; ++use1) {
                                if (pref >= d1 && use1) {
                                    continue;
                                }
                                if (pref == d1 - 1 && use1) {
                                    continue;
                                }
                                for (int use2 = 0; use2 < 2; ++use2) {
                                    if (pref >= d2 && use2) {
                                        continue;
                                    }
                                    if (pref == d2 - 1 && !use2) {
                                        continue;
                                    }
                                    int next_val = (nex + use1 + use2);
                                    int next_nex = next_val / 2;
                                    next_val %= 2;
                                    if (next_val != now[pref]) {
                                        continue;
                                    }
                                    if (used + use1 + use2 > k) {
                                        continue;
                                    }
                                    dp[pref + 1][used + use1 + use2][next_nex] += dp[pref][used][nex];
                                }
                            }
                        }
                    }
                }
                ans += dp[now.size()][k][0];
            }
        }
    }

    cout << ans << endl;

}