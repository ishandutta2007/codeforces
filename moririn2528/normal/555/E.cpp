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

class union_find_tree{
private:
    static constexpr int N=100005;
    int n;
    queue<int> q1;
    vector<int> parent;
    vector<int> num;
public:
    void init(int _n){
        n=_n;
        parent.assign(n,-1);
        num.assign(n,1);
    }
    union_find_tree(int n_init){
        assert(n_init>=0);
        init(n_init);
    }
    union_find_tree(){
        init(N);
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

class Lowlink{
    //compress biconnected components in undirect connected graph
    //want: unionfindtree
    //allow: multiple edges
private:
    typedef vector<pair<int,int>> VEC_PAIR;
    typedef vector<int> VEC;
    typedef vector<VEC> VEC2;
    typedef long long int ll;
    vector<VEC_PAIR> path;
    VEC2 tree;
    VEC ord,lowlink,trans_pos;
    int n=0,nest=0;
    int edge_count=0;
    bool initialized=false,reloaded=false;

    int dfs(int pos,int bef_id,int& cnt,union_find_tree& ua){
        if(ord[pos]!=-1)return -1;
        lowlink[pos]=ord[pos]=cnt++;
        for(auto node:path[pos]){
            int to=node.first,id=node.second;
            if(id==bef_id)continue;
            if(dfs(to,id,cnt,ua)==-1){
                lowlink[pos]=min(lowlink[pos],ord[to]);
            }else{
                lowlink[pos]=min(lowlink[pos],lowlink[to]);
                if(lowlink[to]<=ord[pos])ua.connect(pos,to);
            }
        }
        return 0;
    }

public:
    void init(int _n){
        n=_n;
        path.resize(n);
        ord.assign(n,-1);
        lowlink.assign(n,-1);
        trans_pos.assign(n,-1);
        initialized=true;
    }

    Lowlink(){}
    Lowlink(int _n){
        init(_n);
    }
    Lowlink(int _n,int _nest){
        init(_n);
        nest=_nest;
    }

    void add_edge(int a,int b){
        //undirected edge
        assert(0<=a && a<n);
        assert(0<=b && b<n);
        path[a].push_back({b,edge_count});
        path[b].push_back({a,edge_count});
        edge_count++;
    }

    void reload(){
        assert(initialized);//want: init(n)
        union_find_tree ua(n);
        int i,j;
        int cnt=0;
        dfs(nest,-1,cnt,ua);
        cnt=0;
        for(i=0;i<n;i++){
            j=ua.check_parent(i);
            if(trans_pos[j]==-1)trans_pos[j]=cnt++;
            if(i!=j)trans_pos[i]=trans_pos[j];
        }
        unordered_set<ll> exist_edge;
        tree.resize(cnt);
        for(i=0;i<n;i++){
            int pos=trans_pos[i];
            for(auto node:path[i]){
                int to=trans_pos[node.first];
                if(pos==to)continue;
                if(exist_edge.find((ll)pos*n+to)!=exist_edge.end())continue;
                exist_edge.insert((ll)pos*n+to);
                tree[pos].push_back(to);
            }
        }
        reloaded=true;
    }

    vector<vector<int>>& get_tree(){
        assert(reloaded);//want: reload()
        return tree;
    }
    vector<int>& get_trans_pos(){
        assert(reloaded);//want: reload()
        return trans_pos;
    }

    int get_trans_pos(int pos)const{
        assert(reloaded);//want: reload()
        assert(0<=pos && pos<n);
        return trans_pos[pos];
    }
};




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
    int t[222222][3];

    bool dfs(int pos,int bef,vector<vector<int>>& tree){
        for(auto to:tree[pos]){
            if(to==bef)continue;
            if(!dfs(to,pos,tree))return false;
            for(int i=0;i<3;i++){
                t[pos][i]+=t[to][i];
            }
        }
        if(t[pos][0]>t[pos][2] && t[pos][1]>t[pos][2])return false;
        return true;
    }

    void solve(){
        int n,m,q;
        int i;
        int a,b,c;
        cin>>n>>m>>q;
        Lowlink loli(n+1);
        union_find_tree ua(n);
        for(i=0;i<m;i++){
            cin>>a>>b;
            a--,b--;
            loli.add_edge(a+1,b+1);
            ua.connect(a,b);
        }
        for(i=0;i<n;i++){
            if(ua.check_parent(i)==i)loli.add_edge(i+1,0);
        }
        loli.reload();
        vector<vector<int>> tree=loli.get_tree();
        n=tree.size();
        Lca lca(n);
        for(i=0;i<n;i++){
            for(auto to:tree[i]){
                if(i<to)lca.connect(i,to);
            }
        }
        lca.reload();
        for(i=0;i<q;i++){
            cin>>a>>b;
            a=loli.get_trans_pos(a),b=loli.get_trans_pos(b);
            t[a][0]++,t[b][1]++;
            c=lca.lca(a,b);
            if(c==0){
                cout<<"No"<<endl;
                return;
            }
            t[c][2]++;
        }
        if(dfs(0,-1,tree))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

int main(){
    sol::solve();
}