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
typedef pair<LL,int> LP;
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

class Lca{
    // use method
    // 1. (constructer) Lca lca(n)
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

    int get_par(int pos,int i){return par.at(pos).at(i);}
    int get_depth(int pos){return depth.at(pos);}
    
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
        if(__builtin_popcount(dis)==1){
            return par.at(pos).at(__builtin_ffs(dis)-1);
        }
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

template<typename T> class Lca2: private Lca{
    //funciton using LCA
    //it can calculate path score in O(log n)
    // use method
    // 1. set merge, e function
    // 2. (constructer) Lca2 lca(n)
    // 3. lca.connect(a,b) ((a,b) \in path)
    //  & lca.set_node_cal(vector<T>& val)
    // 4. lca.reload()
    const int N=10;
private:
    const int M=20;
    int n;
    vector<vector<T>> val;

    T merge(const T& t1,const T& t2){
        T ts=T();
        int i,j;
        for(i=0,j=0;i<t1.size() || j<t2.size();){
            if(ts.size()>=N)break;
            if(j==t2.size() || (i<t1.size() && t1[i]<=t2[j])){
                ts.push_back(t1[i]),i++;
            }else ts.push_back(t2[j]),j++;
        }
        return ts;
    }

    T e(){
        return T();
    }

    T calc_path_to_root_val(int a,int dis){
        T s=e();
        for(int i=M-1;i>=0;i--){
            if(dis&(1<<i)){
                s=merge(s,val.at(i).at(a));
                a=get_par(a,i);
            }
        }
        return s;
    }
public:
    Lca2(int _n):n(_n),Lca(_n){}
    Lca2(int _n,int nest):n(_n),Lca(_n,nest){}

    void connect(int a,int b){Lca::connect(a,b);}
    void lca(int a,int b){Lca::lca(a,b);}
    void distance(int a,int b){Lca::distance(a,b);}

    void set_node_value(vector<T>& _val){
        assert(_val.size()==n);
        val.assign(M,vector<T>(n,e()));
        val.at(0)=_val;
    }

    void reload(){
        Lca::reload();
        int i,j;
        for(i=1;i<M;i++){
            for(j=0;j<n;j++){
                if(get_depth(j)<(1<<i))continue;
                int mid=get_par(j,i-1);
                val.at(i).at(j)=merge(val.at(i-1).at(j),val.at(i-1).at(mid));
            }
        }
    }

    T calc_path_val(int a,int b){
        int lca_node=Lca::lca(a,b);
        T ts=merge(val.at(0).at(lca_node),calc_path_to_root_val(a,get_depth(a)-get_depth(lca_node)));
        return merge(ts,calc_path_to_root_val(b,get_depth(b)-get_depth(lca_node)));
    }

};

namespace sol{

    void solve(){
        int n,m,q;
        int i,j,k;
        int a,b,c;
        cin>>n>>m>>q;
        Lca2<vector<int>> lca(n);
        for(i=0;i<n-1;i++){
            cin>>a>>b;
            a--,b--;
            lca.connect(a,b);
        }
        vector<vector<int>> val(n);
        for(i=0;i<m;i++){
            cin>>a;
            a--;
            val[a].push_back(i+1);
        }
        lca.set_node_value(val);
        lca.reload();
        vector<int> vs;
        for(i=0;i<q;i++){
            cin>>a>>b>>c;
            a--,b--;
            vs=lca.calc_path_val(a,b);
            if(c<vs.size())vs.resize(c);
            cout<<vs.size();
            for(auto num:vs){
                cout<<" "<<num;
            }
            cout<<endl;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}