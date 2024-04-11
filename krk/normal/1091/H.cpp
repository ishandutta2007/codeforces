#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxk = 3005;
const int Maxm = 3345;
const int Maxb = 60;

int n, f;
bool nprime[Maxn];
vector <int> prime;
int cnt[Maxn];
ll has[Maxk][Maxm];
ll cur[Maxm];
int nim[Maxn];

int main()
{
    scanf("%d %d", &n, &f);
    for (int i = 2; i < Maxn; i++) {
        if (!nprime[i]) { prime.push_back(i); cnt[i] = 1; }
        for (int j = 0; j < prime.size() && prime[j] * i < Maxn; j++) {
            cnt[prime[j] * i] = cnt[i] + 1;
            nprime[prime[j] * i] = true;
            if (i % prime[j] == 0) break;
        }
    }
    cnt[1] = cnt[f] = 3;
    has[0][0] |= 1ll;
    int mx = 0;
    for (int i = 1; i < Maxn; i++) {
        int nd = i / Maxb + 2;
        for (int j = nd; j >= 0; j--) {
            if (cur[j] & (1ll << ll(Maxb - 1)))
                cur[j] ^= 1ll << ll(Maxb - 1);
            cur[j] <<= 1ll;
            if (j && bool(cur[j - 1] & (1ll << ll(Maxb - 1))))
                cur[j] |= 1ll;
        }
        if (cnt[i] <= 2) cur[0] |= 1ll;
        for (int v = 0; v < Maxk; v++) {
            bool ok = false;
            for (int j = 0; j < nd && !ok; j++)
                ok = bool(cur[j] & has[v][j]);
            if (!ok) { nim[i] = v; break; }
        }
        has[nim[i]][i / Maxb] |= 1ll << ll(i % Maxb);
        mx = max(mx, nim[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        res ^= nim[b - a - 1] ^ nim[c - b - 1];
    }
    string A = "Alice", B = "Bob";
    if (!res) swap(A, B);
    printf("%s\n%s\n", A.c_str(), B.c_str());
    return 0;
}