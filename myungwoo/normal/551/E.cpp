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

#define MAXN 500005
typedef long long lld;

int N, Q, M, K = 707;
int G[MAXN], L[710], R[710];
lld A[MAXN], inc[710];
unordered_map <lld, int> lft[710], rgt[710];

void upd(int g)
{
    lft[g].clear(); rgt[g].clear();
    for (int i=L[g];i<=R[g];i++) if (A[i] <= 1e9) rgt[g][A[i]] = i;
    for (int i=R[g];i>=L[g];i--) if (A[i] <= 1e9) lft[g][A[i]] = i;
}

int proc(int v)
{
    int r = 0, l = N+1;
    for (int g=1;g<=M;g++){
        lld t = v - inc[g];
        if (!rgt[g].count(t)) continue;
        l = min(l, lft[g][t]);
        r = max(r, rgt[g][t]);
    }
    return !r ? -1 : r-l;
}

int main()
{
    scanf("%d%d", &N, &Q);
    for (int i=1;i<=N;i++) scanf("%lld", A+i);
    for (int i=1;i<=N;i++){
        if ((i-1)%K == 0) M++;
        G[i] = M;
    }
    for (int i=1;i<=N;i++) rgt[G[i]][A[i]] = i, R[G[i]] = i;
    for (int i=N;i;i--) lft[G[i]][A[i]] = i, L[G[i]] = i;
    while (Q--){
        int t;
        scanf("%d", &t);
        if (t == 1){
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            int gl = G[l], gr = G[r];
            for (int i=gl+1;i<gr;i++) inc[i] += x;
            for (int i=l;i<=r&&i<=R[gl];i++) A[i] += x;
            upd(gl);
            if (gl < gr){
                for (int i=L[gr];i<=r;i++) A[i] += x;
                upd(gr);
            }
        }else{
            int y;
            scanf("%d", &y);
            printf("%d\n", proc(y));
        }
    }
}