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

int N, M, K;
int par[MAXN];
vector <int> roots, members[MAXN];

struct Z{
    int a, b, c, in, idx;
} E[MAXN];
vector <pii> edges;

int cp(int n){ return par[n] == n ? n : (par[n] = cp(par[n])); }

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1;i<=M;i++){
        scanf("%d%d", &E[i].c, &E[i].in);
        E[i].idx = i;
    }
    sort(E+1, E+M+1, [](const Z &a, const Z &b){
        return a.c != b.c ? a.c < b.c : a.in > b.in;
    });
    for (int i=1;i<=N;i++) par[i] = i, roots.pb(i), members[i].pb(i);
    for (int i=1;i<=M;i++){
        if (E[i].in){
            if (sz(roots) < 2){ puts("-1"); return 0; }
            int a = roots.back(); roots.pop_back();
            int b = roots.back(); roots.pop_back();
            if (sz(members[a]) < sz(members[b]))
                swap(a, b);
            for (int x: members[a]){
                if (K >= M) break;
                for (int y: members[b]){
                    if (K >= M) break;
                    if (x == a && y == b) continue;
                    edges.pb(mp(x, y));
                    K++;
                }
            }
            E[i].a = a, E[i].b = b;
            for (int t: members[b]) members[a].pb(t);
            members[b].clear();
            par[b] = a;
            roots.pb(a);
        }else{
            if (!sz(edges)){ puts("-1"); return 0; }
            E[i].a = edges.back().fr, E[i].b = edges.back().sc;
            edges.pop_back();
        }
    }
    sort(E+1, E+M+1, [](const Z &a, const Z &b){
        return a.idx < b.idx;
    });
    for (int i=1;i<=M;i++) printf("%d %d\n", E[i].a, E[i].b);
}