#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define svec(x) sort(all(x))
#define press(x) x.erase(unique(all(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
typedef pair<LL, LL> pll;
const int INF=1e9;
const LL LLINF=1e18;

int n, m, ans[200010];
pii edg[200010];
struct UNION_FIND{
    int par[200010];
    void init(int sz){for(int i=1; i<=sz; i++)par[i]=i;}
    int findpar(int num){return num==par[num]?num:par[num]=findpar(par[num]);}
    void mergepar(int a, int b){par[findpar(a)]=findpar(b);}
}uf;
bool ch[200010];
vector<pii> link[200010];
void dfs(int num){
    if(ch[num])return;
    ch[num]=true;
    for(auto i:link[num])dfs(i.F);
}

void solve(){
    scanf("%d %d", &n, &m);
    uf.init(n);
    set<int> s;
    for(int i=1; i<=m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        edg[i]=mp(a, b);
        if(uf.findpar(a)==uf.findpar(b)){
            ans[i]=1;
            s.insert(a);
            s.insert(b);
        }
        else{
            ans[i]=0;
            link[a].eb(b, i);
            link[b].eb(a, i);
        }
        uf.mergepar(a, b);
    }
    if(s.size()==3){
        int st, fin, chn;
        for(int i=1; i<=m; i++){
            if(ans[i]==1){
                st=edg[i].F;
                fin=edg[i].S;
                chn=i;
                break;
            }
        }
        for(int i=1; i<=n; i++)ch[i]=false;
        ch[st]=true;
        for(auto i:link[st]){
            dfs(i.F);
            if(ch[fin]){
                ans[chn]=0;
                ans[i.S]=1;
                break;
            }
        }
    }
    for(int i=1; i<=m; i++)printf("%d", ans[i]);
    puts("");
    for(int i=1; i<=n; i++)link[i].clear();
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
}