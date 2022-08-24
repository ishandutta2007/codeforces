#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int p, a;
const int base = 1000'000'000;
int sz = 0;
const int maxN = 3500;
int dig[maxN];
void transform(vector < int >& a) {
    if (a.size() == 1 && a[0] == 0) return;
    int carry = 0;
    for (int i=(int)a.size()-1; i>=0; --i) {
        long long cur = a[i] + carry * 1ll * base;
        a[i] = int (cur / p);
        carry = int (cur % p);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    dig[sz] = carry;
    sz++;
    transform(a);
}
int dp[maxN][2][2];
int ndp[maxN][2][2];
int ways(int x) {
    if (x < 0) return 0;
    return (int)(((1LL * (x + 2) * (x + 1)) / 2) % mod);
}

int get(int x) {
    if (x < 0) return 0;
    if (x >= p - 1 + p - 1) {
        return mult(p, p);
    }
    return sub(sum(ways(x), ways(x - 2 * p)), mult(2, ways(x - p)));
}

int get_sum(int a, int b) {
    if (a > b) return 0;
    return sub(get(b), get(a - 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> p >> a;
    string s;
    cin >> s;
    vector < int > q;
    reverse(s.begin(), s.end());
    for (auto it : s) {
        q.push_back(it - '0');
    }
    while (q.size() % 9 != 0) q.push_back(0);
    vector < int > nq;
    for (int i = 0; i < q.size() / 9; i++) {
        int res = 0;
        for (int j = 9 * i + 8; j >= 9 * i; j--) res = 10 * res + q[j];
        nq.push_back(res);
    }
    transform(nq);
    sz--;
    if (a >= sz + 2) {
        cout << 0;
        return 0;
    }
    dp[0][0][true] = 1;
    for (int i = 0; i <= sz; i++) {
        for (int carry = 0; carry < 2; carry++) {
            for (int flag = 0; flag < 2; flag++) {
                // a + b + carry < dig[i]
                int c1 = get_sum(0, dig[i] - carry - 1);
                if (c1 > 0) {
                    for (int cnt = 0; cnt <= a; cnt++) {
                        ndp[cnt][0][true] = sum(ndp[cnt][0][true], mult(c1, dp[cnt][carry][flag]));
                    }
                }
                // a + b + carry = dig
                int c2 = get_sum(dig[i] - carry, dig[i] - carry);
                if (c2 > 0) {
                    for (int cnt = 0; cnt <= a; cnt++) {
                        ndp[cnt][0][flag] = sum(ndp[cnt][0][flag], mult(c2, dp[cnt][carry][flag]));
                    }
                }
                // a + b + carry = dig + 1, p - 1
                int c3 = get_sum(dig[i] + 1 - carry, p - 1 - carry);
                if (c3 > 0) {
                    for (int cnt = 0; cnt <= a; cnt++) {
                        ndp[cnt][0][false] = sum(ndp[cnt][0][false], mult(c3, dp[cnt][carry][flag]));
                    }
                }
                // a + b + carry = p .. p + dig[i] - 1
                int c4 = get_sum(p - carry, p + dig[i] - 1 - carry);
                if (c4 > 0) {
                    for (int cnt = 0; cnt <= a; cnt++) {
                        ndp[min(cnt + 1, a)][1][true] = sum(ndp[min(cnt + 1, a)][1][true], mult(c4, dp[cnt][carry][flag]));
                    }
                }
                // a + b + carry = p + dig[i]
                int c5 = get_sum(p + dig[i] - carry, p + dig[i] - carry);
                if (c5 > 0) {
                    for (int cnt = 0; cnt <= a; cnt++) {
                        ndp[min(cnt + 1, a)][1][flag] = sum(ndp[min(cnt + 1, a)][1][flag], mult(c5, dp[cnt][carry][flag]));
                    }
                }
                // a + b + carry = p + dig[i] + 1 .. 2 * p - 1
                int c6 = get_sum(p + dig[i] + 1 - carry, 2 * p - 1 - carry);
                if (c6 > 0) {
                    for (int cnt = 0; cnt <= a; cnt++) {
                        ndp[min(cnt + 1, a)][1][false] = sum(ndp[min(cnt + 1, a)][1][false], mult(c6, dp[cnt][carry][flag]));
                    }
                }
            }
        }
        for (int carry = 0; carry < 2; carry++) {
            for (int flag = 0; flag < 2; flag++) {
                for (int cnt = 0; cnt <= a; cnt++) {
                    dp[cnt][carry][flag] = ndp[cnt][carry][flag];
                    ndp[cnt][carry][flag] = 0;
                }
            }
        }
    }
    cout << dp[a][0][true];
    return 0;
}