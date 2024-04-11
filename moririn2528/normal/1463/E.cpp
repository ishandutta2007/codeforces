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

class union_find_tree{
private:
    static constexpr int uft_N=100005;
    int uft_n;
    queue<int> uft_q1;
    vector<int> uft_parent;
    vector<int> uft_num;
public:
    void init(){
        uft_parent.assign(uft_n,-1);
        uft_num.assign(uft_n,1);
    }
    union_find_tree(int uft_n_init){
        assert(uft_n_init>=0);
        uft_n=uft_n_init;
        init();
    }
    union_find_tree(){
        uft_n=uft_N;
        init();
    }

    int check_parent(int uft_x){
        assert(uft_x>=0 && uft_x<uft_n);
        if(uft_parent[uft_x]!=-1){
            uft_q1.push(uft_x);
            return check_parent(uft_parent[uft_x]);
        }
        int uft_a;
        while(!uft_q1.empty()){
            uft_a=uft_q1.front(),uft_q1.pop();
            uft_parent[uft_a]=uft_x;
        }
        return uft_x;
    }

    bool connect(int uft_x,int uft_y){
        assert(uft_x>=0 && uft_x<uft_n);
        assert(uft_y>=0 && uft_y<uft_n);
        uft_x=check_parent(uft_x),uft_y=check_parent(uft_y);
        if(uft_x==uft_y)return true;
        if(uft_num[uft_x]>uft_num[uft_y])swap(uft_x,uft_y);
        uft_parent[uft_x]=uft_y;
        uft_num[uft_y]+=uft_num[uft_x];
        return false;
    }

    int size(int pos){
        pos=check_parent(pos);
        return uft_num[pos];
    }
};

int t[330000];
int deg[330000][3];
vector<int> vs;

bool solve(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>t[i];
    }
    union_find_tree ua(n+10);
    for(i=0;i<m;i++){
        cin>>a>>b;
        ua.connect(a,b);
        deg[a][0]++,deg[b][1]++,deg[a][2]=b+1;
        if(deg[a][0]>1 || deg[b][1]>1)return false;
    }
    vector<vector<int>> va(n+10);
    for(i=0;i<=n;i++){
        if(deg[i][1]>0)continue;
        a=i;
        b=ua.check_parent(i);
        va[b].push_back(a);
        while(deg[a][2]>0){
            a=deg[a][2]-1;
            va[b].push_back(a);
        }
    }
    vector<vector<int>> path(n+10);
    vector<int> pdeg(n+10);
    for(i=0;i<n;i++){
        a=ua.check_parent(i+1);
        b=ua.check_parent(t[i]);
        if(a==b)continue;
        path[b].push_back(a);
        pdeg[a]++;
    }
    queue<int> q1;
    q1.push(0);
    for(i=0;!q1.empty();i++){
        a=q1.front();q1.pop();
        if(pdeg[a])continue;
        if(a!=0)vs.insert(vs.end(),va[a].begin(),va[a].end());
        for(auto to:path[a]){
            pdeg[to]--;
            if(pdeg[to])continue;
            q1.push(to);
        }
    }
    if(vs.size()!=n)return false;
    pdeg.assign(n+10,0);
    path.assign(n+10,vector<int>());
    for(i=0;i<n;i++){
        if(t[i])pdeg[i+1]++;
        path[t[i]].push_back(i+1);
    }
    for(i=0;i<n;i++){
        a=vs[i];
        if(pdeg[a])return false;
        for(auto to:path[a]){
            pdeg[to]--;
        }
    }
    array_show(vs);
    return true;
}


int main(){
    if(!solve()){
        cout<<0<<endl;
    }
}