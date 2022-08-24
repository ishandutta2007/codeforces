#include<bits/stdc++.h>
using namespace std;
#define int unsigned int
typedef long long ll;
const int maxN = (int)sqrt(5 * (int)1e8);
bool prime[maxN];
bool ok[maxN];
int n, a, b, c, d;
vector < int > all;
int calc(int p) {
    int cur = p;
    int t = 0;
    while (1) {
        t += n / cur;
        if (1LL * cur * p > n) break;
        cur *= p;
    }
    return t * (a * p * p * p + b * p * p + c * p + d);
}
// 16 mb
main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
   cin >> n >> a >> b >> c >> d;
   int sqr = (int)sqrt(n);
  // cout << sqr << endl;
   while (sqr * sqr > n) sqr--;
   for (int i = 2; i <= sqr; i++) {
        if (prime[i] == false) {
            all.push_back(i);
            if (1LL * i * i <= sqr) {
                for (int j = i * i; j <= sqr; j += i) prime[j] = true;
            }
        }
   }
   int s = sqr + 1;
   int ans = 0;
   int lim = (n + s - 1) / s;
   for (int k = 0; k <= lim; k++) {
        memset(ok, 0, sizeof ok);
        int st = k * s;
        if (st > n) break;
        for (int i = 0; i < all.size(); i++) {
            int cur = (st + all[i] - 1) / all[i];
            int j = max(cur, (unsigned)2) * all[i] - st;
            for (; j < s; j += all[i]) ok[j] = true;
        }
        if (k == 0) ok[0] = true, ok[1] = true;
        for (int i = 0; i < s && st + i <= n; i++) {
            if (st + i <= sqr) continue;
            if (ok[i]) continue;
            int p = st + i;
            int x = n / p;
            ans += x * (a * p * p * p + b * p * p + c * p + d);
        }
   }
   for (int i = 0; i < all.size(); i++) ans += calc(all[i]);
   cout << ans;
}