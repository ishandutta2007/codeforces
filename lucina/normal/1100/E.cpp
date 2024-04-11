#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct edge{
    int u,v,w,id;
    bool operator <(const edge x)const{
        return w<x.w;
    }
};
vector<edge> e;
vector<int> val, a[maxn],topo,b;
int n,m,s[maxn],ans;
bool vis[maxn],d[maxn],ok;
void topsort(int nod){
    vis[nod]=true;
    d[nod]=true;
    for(int i:a[nod]){
        if(!vis[i]){
            topsort(i);
        }
        else if(d[i]){
            ok=false;
        }
    }
    d[nod]=false;
    topo.push_back(nod);
}
bool ch(int x){
    ok=true;memset(vis,false,sizeof(vis));
    memset(d,false,sizeof(d));topo.clear();
    for(int i=1;i<=n;i++)a[i].clear();
    for(auto i:e){
        if(i.w>x){
            a[i.u].push_back(i.v);
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])
            topsort(i);
    }
    reverse(topo.begin(),topo.end());
    for(int i=0;i<n;i++){
        s[topo[i]]=i+1;
    }
    if(!ok)return false;
    vector<int> nb;
    for(auto i:e){
        if(i.w<=x){
            if(s[i.u]>s[i.v]){
                nb.push_back(i.id);
            }
        }
    }
    b=nb;
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    e.resize(m);
    int id=0;
    for(auto &i:e){
        scanf("%d%d%d",&i.u,&i.v,&i.w);
        i.id=++id;
        val.push_back(i.w);
    }
    val.push_back(0);
    sort(val.begin(),val.end());
    val.erase(unique(val.begin(),val.end()),val.end());
    int l=0,r=(int)val.size()-1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(ch(val[mid])){
            r=mid-1;
            ans=val[mid];
        }
        else{
            l=mid+1;
        }
    }
    printf("%d %d\n",ans,(int)b.size());
    for(auto i:b){
        printf("%d ",i);
    }
}