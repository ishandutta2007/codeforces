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

vector<vector<P>> path;
vector<P> vp;

class union_find_tree{
private:
    static constexpr int N=100005;
    int n,m;
    queue<int> q1;
    vector<int> parent;
    vector<LL> num,v1,id;
    LL cost;
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
    union_find_tree(int _n,int _m,vector<LL>& _v1,LL x){
        n=_n;
        m=_m;
        v1=_v1;
        cost=x;
        id.resize(n);
        iota(id.begin(),id.end(),0);
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
        v1[y]+=v1[x]-cost;
        v1[x]=0;
        int a=id[x],b=id[y];
        if(path[a].size()<path[b].size())swap(a,b);
        id[y]=a;
        path[a].insert(path[a].end(),path[b].begin(),path[b].end());
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

    LL asp(int pos){
        pos=check_parent(pos);
        return v1[pos];
    }

    vector<int> calc(){
        vector<int> vs;
        int i,j,k;
        for(i=0;i<n;i++){
            int pos=i;
            if(check_parent(pos)!=pos)continue;
            bool flag=true;
            while(flag){
                flag=false;
                k=id[pos];
                for(j=0;j<path[k].size();j++){
                    int to=path[k][j].first,e=path[k][j].second;
                    if(check(pos,to)){
                        swap(path[k][j],path[k].back());
                        path[k].pop_back();
                        j--;
                        continue;
                    }
                    if(asp(pos)+asp(to)<cost)break;
                    vs.push_back(e);
                    connect(pos,to);
                    pos=check_parent(pos);
                    flag=true;
                    break;
                }
            }
        }
        for(i=0;i<m;i++){
            int a=vp[i].first,b=vp[i].second;
            if(!connect(a,b))vs.push_back(i);
        }
        return vs;
    }
};

namespace sol{

    void solve(){
        LL n,m,x;
        int i,j,k;
        LL a,b,c;
        cin>>n>>m>>x;
        path.resize(n);
        vector<LL> v1(n);
        cin>>v1;
        for(i=0,a=0;i<n;i++){
            a+=v1[i];
        }
        if(a>=x*(n-1))cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
            return;
        }
        for(i=0;i<m;i++){
            cin>>a>>b;
            a--,b--;
            path[a].push_back({b,i});
            path[b].push_back({a,i});
            vp.push_back({a,b});
        }
        union_find_tree ua(n,m,v1,x);
        vector<int> vs=ua.calc();
        for(auto num:vs){
            cout<<num+1<<endl;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}