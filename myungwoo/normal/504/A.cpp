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

int N;
int deg[MAXN], V[MAXN];
vector <pii> edges;

int main()
{
    scanf("%d", &N);
    for (int i=0;i<N;i++) scanf("%d%d", deg+i, V+i);
    queue <int> que;
    for (int i=0;i<N;i++) if (deg[i] == 1){
        que.push(i);
    }
    while (!que.empty()){
        int q = que.front(); que.pop();
        if (deg[q] != 1) continue;
        edges.pb(mp(q, V[q]));
        V[V[q]] ^= q;
        if (--deg[V[q]] == 1) que.push(V[q]);
    }
    printf("%d\n", sz(edges));
    for (pii &p: edges) printf("%d %d\n", p.fr, p.sc);
}