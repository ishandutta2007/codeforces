#include <bits/stdc++.h>
using namespace std;
int m, n;
const int maxN = (int)1e6 + 10;
vector < int > divisors[maxN];
vector < int > all[maxN];
int lp[maxN];
vector < int > pr;
int a[maxN];
void calc() {
    divisors[1].push_back(1);
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < maxN; j++) {
            lp[i * pr[j]] = pr[j];
        }
        int t = i;
        int p = lp[i];
        int exp = 1;
        while (t > 1) {
            if (lp[t] != p) break;
            exp = exp * p;
            t = t / lp[t];
        }
        int to = i / exp;
        for (int j = 1; j <= exp; j *= p) {
            for (int k = 0; k < divisors[to].size(); k++) {
                divisors[i].push_back(j * divisors[to][k]);
            }
            if (1LL * j * p > exp) break;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    calc();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > m) continue;
        all[a[i]].push_back(i);
    }
    int ans = 1;
    int opt = 0;
    for (int i = 1; i <= m; i++) {
        int cur = 0;
        for (int j = 0; j < divisors[i].size(); j++) {
            cur += all[divisors[i][j]].size();
        }
        if (cur > opt) {
            ans = i;
            opt = cur;
        }
    }
    cout << ans << " " << opt << '\n';
    vector < int > need;
    for (int i = 1; i <= m; i++) {
        if (ans % i == 0) {
            for (int j = 0; j < all[i].size(); j++) {
                need.push_back(all[i][j]);
            }
        }
    }
    sort(need.begin(), need.end());
    for (int i = 0; i < need.size(); i++) cout << need[i] << " ";
    return 0;
}