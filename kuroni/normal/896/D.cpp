#include <bits/stdc++.h>
#define lg(x) (x == 0 ? -1 : __lg(x))
using namespace std;

int n, p, l, r, eu;
long long ans = 0;
vector<int> pr;
vector<long long> mul;
vector<vector<int>> pre;

long long pw(int u, int x) {
    long long ans = 1;
    for (int i = lg(x); i >= 0; i--) {
        (ans *= ans) %= p;
        if (x >> i & 1) {
            (ans *= u) %= p;
        }
    }
    return ans;
}

void init() {
    eu = p;
    int tmp = p;
    for (int i = 2; i * i <= tmp; i++) {
        if (tmp % i == 0) {
            (eu /= i) *= (i - 1);
            pr.push_back(i);
            pre.push_back(vector<int>(n + 1));
            while (tmp % i == 0) {
                tmp /= i;
            }
        }
    }
    if (tmp > 1) {
        (eu /= tmp) *= (tmp - 1);
        pr.push_back(tmp);
        pre.push_back(vector<int>(n + 1));
    }
    mul = vector<long long>(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        for (int j = 0; j < pr.size(); j++) {
            pre[j][i] = pre[j][i - 1];
            while (tmp % pr[j] == 0) {
                pre[j][i]++;
                tmp /= pr[j];
            }
        }
        mul[i] = mul[i - 1] * tmp % p;
    }
}

long long C(int n, int k) {
    if (k > n) {
        return 0;
    }
    long long ans = 1;
    for (int i = 0; i < pr.size(); i++) {
        int cur = pre[i][n] - pre[i][n - k] - pre[i][k];
        (ans *= pw(pr[i], cur)) %= p;
    }
    (ans *= mul[n] * pw(mul[n - k], eu - 1) % p * pw(mul[k], eu - 1) % p) %= p;
    return ans;
}

long long path(int n, int x) {
    return C(n, (n + x) / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> p >> l >> r;
    init();
    for (int i = 0; i <= n - l; i++) {
        int nl = l, nr = min(n - i, r);
        if (nl % 2 != (n - i) % 2) {
            nl++;
        }
        if (nr % 2 != (n - i) % 2) {
            nr--;
        }
        if (nl > nr) {
            continue;
        }
        (ans += C(n, i) * (path(n - i, nl) - path(n - i, nr + 2))) %= p;
    }
    cout << ans;
}