#include <bits/stdc++.h>

using namespace std;
//#pragma GCC optimize("O3")

typedef long long ll;
typedef long double ld;
int n;
const int maxN = 2e5 + 10;
int a[maxN];
int pref_gcd[maxN];
int suf_gcd[maxN];
int lp[maxN];
int cnt[maxN];
int id[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref_gcd[i] = __gcd(pref_gcd[i - 1], a[i]);
        cnt[a[i]]++;
        id[a[i]] = i;
    }
    for (int i = n; i >= 1; i--) {
        suf_gcd[i] = __gcd(suf_gcd[i + 1], a[i]);
    }
    int gc = pref_gcd[n];
    ll coef = 1;
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            for (int j = 2 * i; j < maxN; j += i) {
                lp[j] = i;
            }
            int val = 0;
            int ngc = gc;
            while (ngc % i == 0) {
                val++;
                ngc /= i;
            }
            bool fnd = false;
            int mn = 1e9;
            int tot_cnt = 0;
            for (int j = i; j < maxN; j += i) {
                if (cnt[j]) {
                    tot_cnt += cnt[j];
                    int t2 = 0;
                    int nj = j;
                    while (nj % i == 0) {
                        nj /= i;
                        t2++;
                    }
                    mn = min(mn, t2);
                    if (t2 == val) {
                        fnd = true;
                        int pos = id[j];
                        int tot_val = __gcd(pref_gcd[pos - 1], suf_gcd[pos + 1]);
                        while (tot_val % i == 0) {
                            tot_val /= i;
                            coef *= i;
                        }
                        break;
                    }
                }
            }
            if (fnd) continue;
            if (tot_cnt < (n - 1)) continue;
            for (int j = 0; j < mn; j++) coef *= i;
        }
    }
    cout << coef;

    return 0;
}