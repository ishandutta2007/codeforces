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

int N, M, P, Q;
int A[101], B[101];
int w[202][202];
bool V[202];
vector <int> path;

bool dfs(int n)
{
    path.pb(n); V[n] = 1;
    if (n == N+N+1) return 1;
    for (int i=0;i<=N+N+1;i++) if (!V[i] && w[n][i]){
        if (dfs(i)) return 1;
    }
    path.pop_back();
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i=1;i<=N;i++) cin >> A[i], w[0][i] = A[i], P += A[i];
    for (int i=1;i<=N;i++) cin >> B[i], w[N+i][N+N+1] = B[i], Q += B[i];
    for (int i=1;i<=N;i++) w[i][N+i] = 1e9;
    for (int i=1;i<=M;i++){
        int a, b; cin >> a >> b;
        w[a][N+b] = 1e9;
        w[b][N+a] = 1e9;
    }
    int ans = 0;
    while (dfs(0)){
        int flow = 2e9;
        for (int i=1;i<sz(path);i++) flow = min(flow, w[path[i-1]][path[i]]);
        for (int i=1;i<sz(path);i++){
            w[path[i-1]][path[i]] -= flow;
            w[path[i]][path[i-1]] += flow;
        }
        ans += flow;
        path.clear();
        for (int i=0;i<=N+N+1;i++) V[i] = 0;
    }
    if (P != Q || ans != P){ puts("NO"); return 0; }
    puts("YES");
    for (int i=1;i<=N;i++, puts("")) for (int j=1;j<=N;j++){
        printf("%d ", w[N+j][i]);
    }
}