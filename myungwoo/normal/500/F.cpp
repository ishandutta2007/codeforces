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

#define MAXN 4004
#define MAXQ 20004

int N, P, Q;
int T[MAXN];
int D[MAXN], D1[MAXN][MAXN], D2[MAXN][MAXN];
int ans[MAXQ];

struct ITEM{
    int c, h, t;
} A[MAXN];

struct QUERY{
    int a, b, idx;
} B[MAXQ];

int main()
{
    scanf("%d%d", &N, &P);
    for (int i=1;i<=N;i++) scanf("%d%d%d", &A[i].c, &A[i].h, &A[i].t);
    sort(A+1, A+N+1, [](const ITEM &a, const ITEM &b){
        return a.t < b.t;
    });
    for (int i=1;i<=N;i++) T[i] = A[i].t;
    scanf("%d", &Q);
    for (int i=1;i<=Q;i++) scanf("%d%d", &B[i].a, &B[i].b), B[i].idx = i;
    sort(B+1, B+Q+1, [](const QUERY &a, const QUERY &b){
        return a.a < b.a;
    });
    for (int t=0,i=1,k=1;t<=20000;t+=P){
        while (i <= N && A[i].t < t) i++;
        for (int j=0;j<4001;j++) D[j] = D1[i-1][j] = 0;
        for (int j=i;j<=N&&A[j].t<t+P;j++){
            for (int k=4000-A[j].c;k>=0;k--) put_max(D[k+A[j].c], D[k] + A[j].h);
            for (int k=0;k<4001;k++) D1[j][k] = D[k];
        }
        for (int j=0;j<4001;j++) D[j] = D2[i][j] = 0;
        for (int j=i-1;j>0&&A[j].t>t-P;j--){
            for (int k=4000-A[j].c;k>=0;k--) put_max(D[k+A[j].c], D[k] + A[j].h);
            for (int k=0;k<4001;k++) D2[j][k] = D[k];
        }
        while (k <= Q && B[k].a-P+1 <= t){
            int s = lower_bound(T+1, T+N+1, B[k].a-P+1) - T, e = upper_bound(T+1, T+N+1, B[k].a) - T - 1;
            for (int j=0;j<=B[k].b;j++) put_max(ans[B[k].idx], D1[e][j] + D2[s][B[k].b-j]);
            k++;
        }
    }
    for (int i=1;i<=Q;i++) printf("%d\n", ans[i]);
}