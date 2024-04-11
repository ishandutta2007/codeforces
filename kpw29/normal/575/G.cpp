#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=s;i<=e;i++)
#define FORD(i,s,e) for(int i=s;i>=e;i--)
#define ALL(k) (k).begin(),(k).end()
#define e1 first
#define e2 second
#define MP make_pair
#define EB emplace_back
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<PII,int> PPI;

const int MAXN=100111;
vector<PII> kraw[MAXN];

int nilrt[MAXN];
int odl2[MAXN],ojc2[MAXN];
void bfs2(int st,int n){
    queue<int> Q;
    Q.push(st);nilrt[st]=1;odl2[st]=0;
    while(!Q.empty()){
        int v=Q.front();Q.pop();
        for(auto it:kraw[v]){
            int c=it.e1,b=it.e2;
            if(c>0) continue;
            if(nilrt[b]) continue;
            nilrt[b]=1;
            odl2[b]=odl2[v]+1;
            ojc2[b]=v;
            Q.push(b);
        }
    }
}
vector<PII> V[MAXN],V2[MAXN];
vector<PPI> V3[69];
int odw[MAXN],ojc[MAXN];
int kro[MAXN];
main(){
    int n,m;scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        a++,b++;
        kraw[a].EB(c,b);
        kraw[b].EB(c,a);
    }
    FOR(i,1,n) sort(ALL(kraw[i]));
    bfs2(n,n);
    int ilo=1;
    FOR(i,1,n) if(nilrt[i]) V[1].EB(odl2[i],i),odw[i]=1;
    while(odw[1]==0){
        int ob=0;
        FOR(nr0,1,ilo){
            sort(ALL(V[nr0]));
            
            for(auto it0:V[nr0]){
                int v=it0.e2,dis=it0.e1;
                for(auto it:kraw[v]){
                    int b=it.e2,val=it.e1;
                    if(odw[b]) continue;
                    V3[val].PB({{dis+1,b},v});
                }
            }
            FOR(val,0,9){
                int ok=0;
                if(V3[val].empty()) continue;
                sort(ALL(V3[val]));
                for(auto it:V3[val]){
                    int b=it.e1.e2,dis=it.e1.e1,v=it.e2;
                    if(odw[b]) continue;
                    if(ok==0) ok=1,ob++;
                    ojc[b]=v;odw[b]=1;
                    kro[b]=val;
                    V2[ob].EB(dis,b);
                }
                V3[val].clear();
            }
        }
        FOR(i,1,ilo) V[i].clear();
        FOR(i,1,ob) V[i]=V2[i];
        FOR(i,1,ob) V2[i].clear();
        ilo=ob;
    }
    vector<int> ans,path;
    int v=1;
    while(nilrt[v]==0){
        path.PB(v);
        ans.PB(kro[v]);
        v=ojc[v];
    }
    while(v!=n){
        path.PB(v);
        v=ojc2[v];
    }
    path.PB(n);
    reverse(ALL(ans));
    if(ans.empty()) printf("0");
    for(auto it:ans) printf("%d",it);
    printf("\n%d\n",(int)path.size());
    for(auto it:path) printf("%d ",it-1);
    puts("");
}