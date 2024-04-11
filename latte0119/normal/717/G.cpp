#include<bits/stdc++.h>
 
using namespace std;
 
struct CWW{
    CWW(){
        ios::sync_with_stdio(false);cin.tie(0);
    }
}cww;
typedef long long LL;
struct edge{
    int flow,to,rev;LL cost;
};
typedef vector<edge> E;
typedef vector<E> Graph;
 
void addedge(Graph &g,int from,int to,int f,LL cost){
    int n=g[from].size();
    int m=g[to].size();
    g[from].push_back(edge{f,to,m,cost});
    g[to].push_back(edge{0,from,n,-cost});
}


namespace _ssc{
#define SZ 600
    LL h[SZ];
    LL d[SZ];
    int pV[SZ];
    int pE[SZ];
};
struct ssc{
    LL *h,*d;int *pV,*pE;
    ssc(int V):h(_ssc::h),d(_ssc::d),pV(_ssc::pV),pE(_ssc::pE){
        fill(h,h+V,0);
    }     
};
const LL INF=1e12;
LL min_cost_flow(int s,int t,int f,Graph &g,ssc& info){
    using P=tuple<LL,int>;
 
    const int V=g.size();
    LL res=0;
    while(f>0){
        priority_queue<P> que;
        fill(info.d,info.d+V,INF);
        info.d[s]=0;
        que.push(P(0,s));
        while(que.size()){
            auto p=que.top();que.pop();
            LL cost;int v;tie(cost,v)=p;cost=-cost;
            if(info.d[v]<cost)continue;
            for(int i=0,sz=g[v].size();i<sz;i++){
                auto &e=g[v][i];
                if(e.flow>0&&info.d[e.to]>info.d[v]+e.cost+info.h[v]-info.h[e.to]){
                    info.d[e.to]=info.d[v]+e.cost+info.h[v]-info.h[e.to];
                    info.pV[e.to]=v;
                    info.pE[e.to]=i;
                    que.push(P(-info.d[e.to],e.to));
                }
            }
        }
        if(info.d[t]==INF)break;
     
        for(int v=0;v<V;v++)info.h[v]+=info.d[v];
        int d=f;
        for(int v=t;v!=s;v=info.pV[v])
            d=min(d,g[info.pV[v]][info.pE[v]].flow);
        f-=d;
        res+=d*info.h[t];
        for(int v=t;v!=s;v=info.pV[v]){
            auto &e=g[info.pV[v]][info.pE[v]];
            e.flow-=d;
            g[v][e.rev].flow+=d;
        }
    }
    return res;
}
bool check(string &s,string &w,int i){
    int n=s.size();
    int m=w.size();
    if(i+m>n)return false;
    for(int j=0;j<m;j++)
        if(s[i+j]!=w[j])return false;
    return true;
}
int main(){
    int n;string hole;
    cin>>n>>hole;
    int m;
    cin>>m;
    vector<string> word(m);
    vector<LL> p(m);
    for(int i=0;i<m;i++)cin>>word[i]>>p[i];
    int x;
    cin>>x;
    int V=n+3;
    int s=n+1;
    int t=n+2;
    Graph g(V);
    ssc info(V);
    addedge(g,s,0,x,0);
    for(int i=0;i<n;i++)addedge(g,i,i+1,x,0);
    addedge(g,n,t,x,0);
    LL res=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(check(hole,word[j],i)){
                int k=word[j].size();
                addedge(g,s,i+k,1,0);
                addedge(g,i+k,i,1,p[j]);
                addedge(g,i,t,1,0);
                res+=p[j];
            }
    //cout<<res<<endl;
    cout<<res-min_cost_flow(s,t,3*114514,g,info)<<endl;
}