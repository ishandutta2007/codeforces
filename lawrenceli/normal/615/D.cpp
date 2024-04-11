#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <ios>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 200100;
const int mod = 1e9 + 7;
const int mod2 = 1e9 + 6;

map<int, int> mp;
int ar[maxn], num[maxn];
int suf[maxn];

int exp(int b, int e) {
    if (!e) return 1;
    if (e & 1) return ll(exp(b, e - 1)) * b % mod;
    int res = exp(b, e >> 1);
    return ll(res) * res % mod;
}

int main() {
    ios_base::sync_with_stdio(0);

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int p; cin >> p;
        mp[p]++;
    }

    int cnt = 0;
    for (pii p : mp) {
        ar[cnt] = p.first, num[cnt] = p.second;
        cnt++;
    }
    int n = mp.size();

    suf[n] = 1;
    for (int i = n - 1; i >= 0; i--)
        suf[i] = ll(suf[i + 1]) * (num[i] + 1) % mod2;

    int ans = 1, cur = 1;
    for (int i = 0; i < n; i++) {
        int x = (ll(num[i]) * (num[i] + 1) / 2) % mod2;
        ans = ll(ans) * exp(ar[i], ll(cur) * suf[i + 1] % mod2 * x % mod2) % mod;
        cur = ll(cur) * (num[i] + 1) % mod2;
    }

    cout << ans << '\n';
}