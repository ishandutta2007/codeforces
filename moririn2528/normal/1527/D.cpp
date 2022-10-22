#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
#include<set>
#include<complex>
#include<numeric>
#include<functional>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,LL> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
template<typename T> ostream& operator<<(ostream& os,const vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++){
        if(i)os<<" ";
        os<<v1[i];
    }
    return os;
}
template<typename T1,typename T2> ostream& operator<<(ostream& os,const pair<T1,T2>& p){
    os<<p.first<<" "<<p.second;
    return os;
}
template<typename T> istream& operator>>(istream& is,vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++)is>>v1[i];
    return is;
}

class Lca{
    // use method
    // 1. (constructer) Lca lca(n) or lca.init(n)
    // 2. lca.connect(a,b) ((a,b) \in path)
    // 3. lca.reload()
    // lca.lca(a,b): lower common ancestor
private:
    const int M=20;
    int nest=0;
    vector<vector<int>> path;
    vector<vector<int>> par;
    vector<int> depth;
    
    void init(int n){
        path.assign(n,vector<int>());
        par.assign(n,vector<int>(M,-1));
        depth.assign(n,-1);
    }

    void create_depth(int pos,int bef,int d){
        if(depth.at(pos)!=-1)return;
        depth.at(pos)=d;
        int p=bef;
        for(int i=0;i<M;i++){
            if(p==-1)break;
            par.at(pos).at(i)=p;
            p=par.at(p).at(i);
        }
        for(auto to:path.at(pos)){
            create_depth(to,pos,d+1);
        }
    }

public:
    
    Lca(int n){
        init(n);
    }
    Lca(int n,int nes){
        nest=nes;
        init(n);
    }

    int get_depth(int pos){
        return depth.at(pos);
    }
    
    void connect(int a,int b){
        path.at(a).push_back(b);
        path.at(b).push_back(a);
    }

    void reload(){
        int n=path.size();
        par.assign(n,vector<int>(M,-1));
        depth.assign(n,-1);
        create_depth(nest,-1,0);
    }

    int check_parent(int pos,int dis){
        assert(0<=dis && dis<=depth[pos]);
        if(dis==0)return pos;
        for(int i=M-1;i>=0;i--){
            if(dis<(1<<i))continue;
            dis-=1<<i;
            pos=par.at(pos).at(i);
        }
        return pos;
    }

    int lca(int a,int b){
        if(depth.at(a)<depth.at(b))swap(a,b);
        a=check_parent(a,depth.at(a)-depth.at(b));
        if(a==b)return a;
        for(int i=M-1;i>=0;i--){
            if(par.at(a).at(i)!=par.at(b).at(i)){
                a=par.at(a).at(i);
                b=par.at(b).at(i);
            }
        }
        return par.at(a).at(0);
    }

    int distance(int a,int b){
        return depth.at(a)+depth.at(b)-2*depth.at(lca(a,b));
    }
};

namespace sol{

    void init(){
        
    }

    vector<LL> sz,par;
    vector<vector<int>> path;

    void dfs_sz(int pos,int bef){
        par[pos]=bef;
        for(auto to:path[pos]){
            if(to==bef)continue;
            dfs_sz(to,pos);
            sz[pos]+=sz[to];
        }
        sz[pos]++;
    }

    void solve(){
        LL n,m;
        int i,j,k;
        LL a,b,c;
        LL x,y,p,q;
        cin>>n;
        Lca lca(n);
        path.assign(n,vector<int>());
        for(i=0;i<n-1;i++){
            cin>>a>>b;
            lca.connect(a,b);
            path[a].push_back(b);
            path[b].push_back(a);
        }
        lca.reload();
        vector<LL> vs(n+10,0);
        vs[0]=n*(n-1)/2;
        sz.assign(n,0);
        par.assign(n,0);
        dfs_sz(0,-1);
        vs[1]=vs[0];
        for(auto to:path[0]){
            vs[1]-=sz[to]*(sz[to]-1)/2;
        }
        for(a=1;par[a]!=0;a=par[a]);
        x=sz[0]-sz[a];
        p=0,q=0;
        for(i=1;i<n;i++){
            a=lca.lca(p,i);
            if(a==i){
                vs[i+1]=vs[i];
                continue;
            }
            if(a==p){
                p=i;
            }else if(a!=0)break;
            else{
                a=lca.lca(q,i);
                if(a==i){
                    vs[i+1]=vs[i];
                    continue;
                }
                if(a==q)q=i;
                else break;
            }
            if(q==0)vs[i+1]=sz[p]*x;
            else vs[i+1]=sz[p]*sz[q];
        }
        for(i=0;i<n;i++){
            vs[i]-=vs[i+1];
        }
        vs.resize(n+1);
        cout<<vs<<endl;
    }
}

int main(){
    int n,i;
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}