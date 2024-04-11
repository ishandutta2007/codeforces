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
const LL mod=1e9+7;

int n, m, tmp[500010];
vector<int> cp[500010], cp2[500010], vc;
bool isone[500010];
pii edg[500010];
LL ans=1, pw[500010];

struct UNION_FIND{
    int par[500010];
    void init(){for(int i=1; i<=500000; i++)par[i]=i;}
    int findpar(int num){return num==par[num]?num:par[num]=findpar(par[num]);}
    void mergepar(int a, int b){par[findpar(a)]=findpar(b);}
}uf;

int main(){
    scanf("%d %d", &n, &m);
    uf.init();
    pw[0]=1ll;
    for(int i=1; i<=500000; i++)pw[i]=pw[i-1]*2ll%mod;
    for(int i=1; i<=n; i++){
        int k;
        scanf("%d", &k);
        if(k==1){
            int a;
            scanf("%d", &a);
            edg[i].F=a;
            isone[a]=true;
            if(!tmp[a])tmp[a]=i;
        }
        else{
            int a, b;
            scanf("%d %d", &a, &b);
            uf.mergepar(a, b);
            edg[i]=mp(a, b);
        }
    }
    for(int i=1; i<=m; i++)cp[uf.findpar(i)].eb(i);
    for(int i=1; i<=n; i++)cp2[uf.findpar(edg[i].F)].eb(i);
    uf.init();
    for(int i=1; i<=m; i++){
        if(cp[i].size()==0)continue;
        if(cp[i].size()==1){
            if(isone[cp[i][0]]){
                vc.eb(tmp[cp[i][0]]);
                ans*=2ll;
                ans%=mod;
            }
        }
        else{
            bool flg=false;
            for(auto j:cp[i]){
                if(isone[j]){
                    flg=true;
                    break;
                }
            }
            svec(cp2[i]);
            if(flg){
                ans*=pw[cp[i].size()];
                ans%=mod;
            }
            else{
                ans*=pw[cp[i].size()-1];
                ans%=mod;
            }
            for(auto j:cp2[i]){
                if(uf.findpar(edg[j].F)==uf.findpar(edg[j].S))continue;
                uf.mergepar(edg[j].F, edg[j].S);
                vc.eb(j);
            }
        }
    }
    printf("%lld %d\n", ans, vc.size());
    svec(vc);
    for(auto i:vc)printf("%d ", i);
}