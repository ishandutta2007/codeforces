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

    bool is_connect(int x,int y){
        assert(x>=0 && x<n);
        assert(y>=0 && y<n);
        return check_parent(x)==check_parent(y);
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
    const int N=1000;
    typedef tuple<int,int,int> T;

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        LL s=0;
        cin>>n>>m;
        priority_queue<T,vector<T>,greater<T>> q1;
        vector<vector<P>> path(n);
        for(i=0;i<m;i++){
            cin>>a>>b>>c;
            a--,b--;
            path[a].push_back({b,c});
            path[b].push_back({a,c});
            q1.push({c,a,b});
        }
        union_find_tree ua(n);
        if(n>=N){
            for(i=0,a=0;i<n;i++){
                if(path[i].size()<path[a].size())a=i;
            }
            vector<char> used(n);
            used[a]=1;
            for(auto node:path[a]){
                used[node.first]=1;
            }
            vector<int> v1;
            for(i=0;i<n;i++){
                if(!used[i]){
                    ua.connect(i,a);
                }else v1.push_back(i);
            }
            for(auto num:v1){
                used.assign(n,0);
                used[num]=1;
                for(auto node:path[num]){
                    used[node.first]=1;
                }
                for(i=0;i<n;i++){
                    if(!used[i])ua.connect(num,i);
                }
            }
            while(!q1.empty()){
                tie(a,b,c)=q1.top(),q1.pop();
                if(ua.is_connect(b,c))continue;
                ua.connect(b,c);
                s+=a;
            }
            cout<<s<<endl;
            return;
        }
        vector<vector<int>> pm(n,vector<int>(n,-1));//path matrix
        int xo=0;
        for(i=0;i<n;i++){
            for(auto node:path[i]){
                a=node.first,b=node.second;
                if(a<i)continue;
                pm[i][a]=pm[a][i]=b;
                xo^=b;
            }
        }
        
        bool flag=false;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(pm[i][j]!=-1)continue;
                if(ua.is_connect(i,j)){
                    flag=true;
                }
                ua.connect(i,j);
            }
        }
        union_find_tree ub(n);
        while(!q1.empty()){
            tie(a,b,c)=q1.top();q1.pop();
            if(!ua.is_connect(b,c)){
                ua.connect(b,c);
                ub.connect(b,c);
                s+=a;
                continue;
            }
            if(ub.is_connect(b,c))continue;
            if(!flag && a<xo){
                flag=true;
                s+=a;
            }
        }
        if(!flag)s+=xo;
        cout<<s<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}