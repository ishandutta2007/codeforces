// chtholly <3

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int seed;
struct node{
    int l,r;
    mutable int x;
    node(int a,int b=-1,int c=0){l=a;r=b;x=c;}
    bool operator<(const node &wao)const{return l<wao.l;}
};
set<node> ODT;
vector<pair<int,int> > pp;
int rnd(){
    int ans=seed;
    ((seed*=7)+=13)%=mod;
    return ans;
}
int bm(int b,int p,int m){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
auto split(int x){
    auto it=ODT.lower_bound(node(x));
    if(it!=ODT.end()&&it->l==x)return it;
    it--;
    int u=it->l,v=it->r,w=it->x;
    ODT.erase(it);
    ODT.insert(node(u,x-1,w));
    return ODT.insert(node(x,v,w)).first;
}
int qry(auto u,auto v,int r){
    pp.clear();
    for(auto it=u;it!=v;++it)pp.push_back({it->x,it->r-it->l+1});
    sort(pp.begin(),pp.end());
    for(auto it=pp.begin();it!=pp.end();++it){
        r-=it->second;
        if(r<=0)return it->first;
    }
    return 0;
}
signed main(){
    int n,m,v;
    cin>>n>>m>>seed>>v;
    for(int i=1;i<=n;i++){
        int wa=rnd()%v+1;
        ODT.insert(node(i,i,wa));
    }
    ODT.insert(node(n+1,n+1,0));
    while(m--){
        int op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x;
        if(l>r)swap(l,r);
        if(op==3)x=rnd()%(r-l+1)+1;
        else x=rnd()%v+1;
        auto a=split(l),b=split(r+1);
        if(op==1){
            for(auto it=a;it!=b;++it)it->x+=x;
        }
        else if(op==2){
            ODT.erase(a,b);
            ODT.insert(node(l,r,x));
        }
        else if(op==3)cout<<qry(a,b,x)<<"\n";
        else{
            int m=rnd()%v+1,ans=0;
            for(auto it=a;it!=b;++it)ans=(ans+(it->r-it->l+1)*bm(it->x,x,m))%m;
            cout<<ans<<"\n";
        }
    }
}