#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define MAXV 500005
#define pb push_back
#define sz(v) ((int)(v).size())
typedef long long lld;

int N, Q, C;
int A[MAXN], cnt[MAXV];
bool V[MAXN];
vector <int> primes[MAXN];

int main()
{
    scanf("%d%d", &N, &Q);
    for (int i=1;i<=N;i++){
        scanf("%d", A+i);
        int n = A[i];
        for (int j=2;j*j<=n;j++) if (n%j == 0){
            while (n%j == 0) n /= j;
            primes[i].pb(j);
        }
        if (n > 1) primes[i].pb(n);
    }
    lld ans = 0;
    while (Q--){
        int x;
        scanf("%d", &x);
        auto &p = primes[x];
        lld c = 0;
        vector <int> tmp;
        for (int msk=(1<<sz(p));--msk;){
            int v = 1, s = -1;
            for (int i=sz(p);i--;) if (msk & (1 << i)) v *= p[i], s *= -1;
            c += cnt[v] * s;
            tmp.pb(v);
        }
        c = C - c;
        if (V[x]) ans -= c - (A[x] == 1), C--;
        else ans += c, C++;
        V[x] ^= 1;
        printf("%lld\n", ans);
        for (int t: tmp) cnt[t] += V[x] ? 1 : -1;
    }
}