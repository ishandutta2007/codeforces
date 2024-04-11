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

int N, T, P, Q;
int A[MAXN];
int cnt[MAXN], tmp[MAXN];

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%d", A+i), cnt[A[i]]++;
    int odds = 0;
    for (int i=1;i<=N;i++) if (cnt[i]&1) odds++, T = i;
    if ((N&1) != odds){ puts("0"); return 0; }
    for (int i=1;i<=N;i++) tmp[i] = cnt[i];
    for (int i=1;i<=N;i++){
        tmp[A[i]] -= 2;
        P = i;
        if (odds && i == (N+1)/2 && A[i] != T) break;
        if (i <= N/2 && tmp[A[i]] < 0 || i > N/2 && A[i] != A[N-i+1]) break;
    }
    for (int i=1;i<=N;i++) tmp[i] = cnt[i];
    for (int i=N;i;i--){
        tmp[A[i]] -= 2;
        Q = i;
        if (odds && i == (N+1)/2 && A[i] != T) break;
        if (i > (N+1)/2 && tmp[A[i]] < 0 || i <= (N+1)/2 && A[i] != A[N-i+1]) break;
    }
    lld ans = 0;
    for (int i=0;i+1<=N-i;i++){
        if (A[i] != A[N-i+1]) break;
        ans += (min(N-i, P)-i) + (N-i+1-max(i+1, Q)) - 1;
    }
    printf("%lld\n", ans);
}