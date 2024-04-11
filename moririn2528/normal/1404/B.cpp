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

void init(){
    
}

vector<vector<int>> path;

void dfs(int pos,int d,vector<int>& dis){
    if(dis[pos]!=-1)return;
    dis[pos]=d;
    for(auto to:path[pos])dfs(to,d+1,dis);
}

void solve(){
    int n,m;
    int i,j,k;
    int a,b,c;
    int da,db;
    int x,y;
    cin>>n>>x>>y>>da>>db;
    x--,y--;
    path.assign(n,vector<int>());
    for(i=0;i<n-1;i++){
        cin>>a>>b;
        a--,b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    if(da*2>=db){
        cout<<"Alice"<<endl;
        return;
    }
    vector<int> dis(n,-1);
    dfs(x,0,dis);
    if(dis[y]<=da){
        cout<<"Alice"<<endl;
        return;
    }
    for(i=0,j=0;i<n;i++){
        if(dis[j]<dis[i])j=i;
    }
    dis.assign(n,-1);
    dfs(j,0,dis);
    a=0;
    for(i=0;i<n;i++){
        a=max(a,dis[i]);
    }
    if(a<=2*da)cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}