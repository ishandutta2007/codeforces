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

const int MOD = 1e9+9;
int N, X[MAXN], Y[MAXN], C[MAXN];
bool V[MAXN];
map <pii, int> A;
vector <int> con[MAXN], rcon[MAXN];
set <int> S;

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%d%d", X+i, Y+i), A[mp(X[i], Y[i])] = i;
    for (int i=1;i<=N;i++) if (Y[i]){
        for (int dx=-1;dx<2;dx++){
            auto it = A.find(mp(X[i]+dx, Y[i]-1));
            if (it == A.end()) continue;
            con[i].pb(it->second);
            rcon[it->second].pb(i);
        }
    }
    for (int i=1;i<=N;i++) S.insert(i);
    for (int i=1;i<=N;i++){
        if (sz(con[i]) == 1) S.erase(con[i][0]), C[con[i][0]]++;
    }
    int ans = 0;
    for (int t=1;t<=N;t++){
        int player = t&1;
        int v = player ? *S.rbegin() : *S.begin();
        V[v] = 1;
        ans = ((lld)ans * N + (v-1)) % MOD;
        S.erase(v);
        for (int t: rcon[v]) if (!V[t]){
            con[t].erase(find(all(con[t]), v));
            if (sz(con[t]) == 1) S.erase(con[t][0]), C[con[t][0]]++;
        }
        if (sz(con[v]) == 1){
            if (!--C[con[v][0]])
                S.insert(con[v][0]);
        }
    }
    printf("%d\n", ans);
}