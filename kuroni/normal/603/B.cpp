#include <bits/stdc++.h>
using namespace std;
    
const int P = 1E6 + 5, MOD = 1E9 + 7;
    
int p, k, ans[P], cyc[P], add[P];
long long ret = 1;
bool chk[P];
vector<int> ve;

long long pw(long long u, int v) {
    long long ret = 1;
    for (int i = __lg(v); i >= 0; i--) {
        (ret *= ret) %= MOD;
        if (v >> i & 1) {
            (ret *= u) %= MOD;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> p >> k;
    if (k == 0) {
        return cout << pw(p, p - 1), 0;
    }
    for (int i = 0; i < p; i++) {
        if (chk[i]) {
            continue;
        }
        int cur = i, cnt = 0;
        do {
            chk[cur] = true;
            cnt++;
            cur = 1LL * cur * k % p;
        } while (cur != i);
        ans[cnt]++;
        cyc[cnt]++;
    }
    for (int i = 1; i < p; i++) {
        for (int j = i; j < p; j += i) {
            (add[j] += 1LL * cyc[i] * i) %= MOD;
        }
    }
    for (int i = 1; i < p; i++) {
        if (ans[i] != 0) {
            (ret *= pw(add[i], ans[i])) %= MOD;
        }
    }
    cout << ret;
}