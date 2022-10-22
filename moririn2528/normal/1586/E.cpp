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
template<typename T1,typename T2> istream& operator>>(istream& is,pair<T1,T2>& p){
    is>>p.first>>p.second;
    return is;
}

class Lca{
    // use method
    // 1. (constructer) Lca lca(n) or lca.init(n)
    // 2. lca.connect(a,b) ((a,b) \in path)
    // 3. lca.reload()
    // lca.lca(a,b): lower common ancestor
public:
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

class union_find_tree{
private:
    static constexpr int N=100005;
    int n;
    queue<int> q1;
    vector<int> parent;
    vector<int> num;
public:
    void init(){
        parent.assign(n,-1);
        num.assign(n,1);
    }
    union_find_tree(int n_init){
        assert(n_init>=0);
        n=n_init;
        init();
    }
    union_find_tree(){
        n=N;
        init();
    }

    int check_parent(int x){
        assert(x>=0 && x<n);
        if(parent[x]!=-1){
            q1.push(x);
            return check_parent(parent[x]);
        }
        int a;
        while(!q1.empty()){
            a=q1.front(),q1.pop();
            parent[a]=x;
        }
        return x;
    }

    bool connect(int x,int y){
        assert(x>=0 && x<n);
        assert(y>=0 && y<n);
        x=check_parent(x),y=check_parent(y);
        if(x==y)return true;
        if(num[x]>num[y])swap(x,y);
        parent[x]=y;
        num[y]+=num[x];
        return false;
    }

    int size(int pos){
        pos=check_parent(pos);
        return num[pos];
    }

    bool check(int x,int y){//connect:true
        assert(x>=0 && x<n);
        assert(y>=0 && y<n);
        return check_parent(x)==check_parent(y);
    }
};

namespace sol{
    vector<vector<int>> path;

    void solve(){
        int n,m,q;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        Lca lca(n);
        union_find_tree ua(n);
        path.resize(n);
        for(i=0;i<m;i++){
            cin>>a>>b;
            a--,b--;
            if(ua.connect(a,b))continue;
            lca.connect(a,b);
            path[a].push_back(b);
            path[b].push_back(a);
        }
        lca.reload();
        cin>>q;
        vector<int> v1(n);
        vector<P> vq;
        for(i=0;i<q;i++){
            cin>>a>>b;
            a--,b--;
            v1[a]++,v1[b]++;
            vq.push_back({a,b});
        }
        a=0;
        for(i=0;i<n;i++){
            if(v1[i]%2)a++;
        }
        if(a==0)cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
            cout<<a/2<<endl;
            return;
        }
        for(i=0;i<q;i++){
            a=vq[i].first,b=vq[i].second;
            c=lca.lca(a,b);
            vector<int> v1,v2,vs;
            while(a!=c){
                v1.push_back(a);
                a=lca.par[a][0];
            }
            while(b!=c){
                v2.push_back(b);
                b=lca.par[b][0];
            }
            reverse(v2.begin(),v2.end());
            for(auto num:v1)vs.push_back(num+1);
            vs.push_back(c+1);
            for(auto num:v2)vs.push_back(num+1);
            cout<<vs.size()<<endl;
            cout<<vs<<endl;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}