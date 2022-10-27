#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,u,v;
long long w;
pair<long long,int> a[maxn];
int pa[maxn];
struct edge{
int x;
int y;
long long b;
    bool operator <(const edge d)const{
    return b<d.b;
    }
};
vector<edge> e;
int findpa(int x){
    return x==pa[x]?x:pa[x]=findpa(pa[x]);

}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].first);
        a[i].second=i;
        pa[i]=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%lld",&u,&v,&w);
        if(u>v) swap(u,v);
        e.push_back({u,v,w});
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        e.push_back({a[1].second,a[i].second,a[1].first+a[i].first});
    }
    sort(e.begin(),e.end());
    int pt=0,g=n-1;
    long long sum=0;
    while(g){
        u=findpa(e[pt].x);
        v=findpa(e[pt].y);
        if(u==v){
            pt++;
            continue;
        }
        g--;
        sum+=(e[pt].b);
        pt++;
        pa[v]=u;
    }
    printf("%lld\n",sum);
}