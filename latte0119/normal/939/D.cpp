#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

struct UnionFindTree{
    vector<int>par,sz;
    UnionFindTree(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool areSame(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};

signed main(){
    int N;
    cin>>N;
    string S,T;
    cin>>S>>T;
    UnionFindTree uf(26);
    rep(i,N){
        uf.unite(S[i]-'a',T[i]-'a');
    }
    vpint ans;
    rep(i,26){
        if(i!=uf.find(i))continue;

        vint lis;
        rep(j,26){
            if(uf.areSame(i,j))lis.pb(j);
        }
        for(int j=0;j+1<lis.size();j++)ans.pb({lis[j],lis[j+1]});
    }

    cout<<ans.size()<<endl;
    rep(i,ans.size())cout<<(char)(ans[i].fi+'a')<<" "<<(char)(ans[i].se+'a')<<endl;
    return 0;
}