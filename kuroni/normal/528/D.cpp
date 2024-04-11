#include <bits/stdc++.h>
using namespace std;

const int LG = 19, MX = 1 << LG, N = 2E5 + 5;
const double PI = acos(-1);

int n, m, k, pre[N];
string s, t;

int reverse_bit(int u) {
    int ans = 0;
    for (int i = 0; i < LG; i++) {
        (ans <<= 1) ^= (u >> i & 1);
    }
    return ans;
}

struct polynomial {
    vector<complex<double>> f;

    polynomial(int _sz = 0) {
        f = vector<complex<double>>(_sz, 0);
    }

    polynomial fft(bool inv = false) {
        if (inv) {
            reverse(f.begin() + 1, f.end());
        }
        polynomial ans(MX);
        for (int i = 0; i < f.size(); i++) {
            ans.f[reverse_bit(i)] = f[i];
        }
        for (int len = 1; len < MX; len += len) {
            complex<double> rt(cos(PI / len), sin(PI / len));
            for (int i = 0; i < MX; i += 2 * len) {
                complex<double> w(1, 0);
                for (int j = 0; j < len; j++) {
                    complex<double> u = ans.f[i + j], v = ans.f[i + j + len];
                    ans.f[i + j] = u + w * v;
                    ans.f[i + j + len] = u - w * v;
                    w *= rt;
                }
            }
        }
        if (inv) {
            reverse(f.begin() + 1, f.end());
            for (auto &v : ans.f) {
                v /= MX;
            }
        }
        return ans;
    }

    polynomial operator*(const polynomial &oth) {
        polynomial ans(MX);
        for (int i = 0; i < MX; i++) {
            ans.f[i] = f[i] * oth.f[i];
        }
        return ans;
    }

    polynomial operator+(const polynomial &oth) {
        polynomial ans(MX);
        for (int i = 0; i < MX; i++) {
            ans.f[i] = f[i] + oth.f[i];
        }
        return ans;
    }

    long long coeffient(int u) {
        return round(abs(f[u]));
    }
} ans(MX);

void solve(char c) {
    polynomial a(MX), b(MX);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (s[i - 1] == c);
    }
    for (int i = 1; i <= n; i++) {
        int l = max(0, i - k - 1), r = min(n, i + k);
        if (pre[r] - pre[l] == 0) {
            a.f[i - 1] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        b.f[m - i] = (t[i - 1] == c);
    }
    ans = ans + (a.fft() * b.fft()).fft(true);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k >> s >> t;
    solve('A'); solve('T'); solve('G'); solve('C');
    int ret = 0;
    for (int i = 0; i <= n - m; i++) {
        ret += (ans.coeffient(i + m - 1) == 0);
    }
    cout << ret;
}