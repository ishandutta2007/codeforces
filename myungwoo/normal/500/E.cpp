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

#define MAXN 200005
#define TS 524288

int N, Q;
int X[MAXN], Y[MAXN], R[MAXN][18], idx[MAXN][18], C[MAXN][18];;
int tree[TS], ST = TS/2-1;

int get_max(int l, int r)
{
    int ret = 0;
    for (l+=ST,r+=ST;l<=r;l>>=1,r>>=1){
        if (l&1) ret = max(ret, tree[l++]);
        if (!(r&1)) ret = max(ret, tree[r--]);
    }
    return ret;
}

void upd(int p, int v)
{
    p += ST;
    tree[p] = v;
    for (p>>=1;p;p>>=1) tree[p] = max(tree[p+p], tree[p+p+1]);
}

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%d%d", X+i, Y+i);
    for (int i=N;i;i--){
        int r = X[i] + Y[i];
        int j = upper_bound(X+1, X+N+1, r) - X - 1;
        R[i][0] = max(get_max(i+1, j), r);
        upd(i, R[i][0]);
        idx[i][0] = upper_bound(X+1, X+N+1, R[i][0]) - X - 1;
    }
    for (int i=1;i<18;i++){
        for (int j=1;j<=N;j++){
            if (idx[j][i-1] == N)
                idx[j][i] = N, C[j][i] = C[j][i-1], R[j][i] = R[j][i-1];
            else
                idx[j][i] = idx[idx[j][i-1]+1][i-1], C[j][i] = C[j][i-1] + C[idx[j][i-1]+1][i-1] + X[idx[j][i-1]+1] - R[j][i-1], R[j][i] = R[idx[j][i-1]+1][i-1];
        }
    }
    for (scanf("%d", &Q);Q--;){
        int a, b;
        scanf("%d%d", &a, &b);
        if (idx[a][0] >= b){ puts("0"); continue; }
        int ans = 0;
        for (int i=18;i--;){
            if (idx[a][i] < b){
                ans += C[a][i] + X[idx[a][i]+1] - R[a][i], a = idx[a][i]+1;
            }
        }
        printf("%d\n", ans);
    }
}