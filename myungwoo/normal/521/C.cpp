#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

#define MAXN 100005

const int MOD = 1e9 + 7;
int N, K;
int A[MAXN];
int F[MAXN], CK1[MAXN], T[MAXN], AC[MAXN];

int inv(int n)
{
    int ret = 1, p = MOD - 2, v = n;
    for (;p;p>>=1,v=(lld)v*v%MOD) if (p&1) ret = (lld)ret * v % MOD;
    return ret;
}

int combi(int n, int k)
{
    return (lld)F[n] * inv(F[k]) % MOD * inv(F[n-k]) % MOD;
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i=1;i<=N;i++) scanf("%1d", A+i);
    F[0] = T[0] = 1;
    for (int i=1;i<=N;i++) F[i] = (lld)F[i-1] * i % MOD, T[i] = (lld)T[i-1] * 10 % MOD;
    for (int i=K-1;i<=N;i++) CK1[i] = combi(i, K-1);
    AC[0] = CK1[0];
    for (int i=1;i<=N;i++) AC[i] = ((lld)AC[i-1] * 10 + CK1[i]) % MOD;
    int ans = 0;
    for (int i=1;i<=N;i++){
        int mxp = min(N - i - 1, N - K + 1);
        if (i-1 >= K){
            int p = N - i;
            ans = (ans + ((lld)combi(N-p-1, K) * A[i] * T[p])) % MOD;
        }
        if (mxp < 0) continue;
        int v = (AC[N-2] - (N-mxp-3 >= 0 ? (lld)AC[N-mxp-3] * T[mxp + 1] % MOD : 0) + MOD) % MOD;
        v = (lld)v * A[i] % MOD;
        ans = (ans + v) % MOD;
    }
    printf("%d\n", ans);
}