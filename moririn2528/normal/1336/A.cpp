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

vector<vector<int>> path;
int t[220000][2];
vector<int> vs;

void dfs(int pos,int bef){
    for(auto to:path[pos]){
        if(to==bef)continue;
        t[to][0]=t[pos][0]+1;
        dfs(to,pos);
        t[pos][1]+=t[to][1];
    }
    vs.push_back(t[pos][1]-t[pos][0]);
    t[pos][1]++;
}

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n>>m;
    path.assign(n,vector<int>());
    for(i=0;i<n-1;i++){
        cin>>a>>b;
        a--,b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    dfs(0,-1);
    sort(vs.rbegin(),vs.rend());
    LL s=0;
    for(i=0;i<n-m;i++){
        s+=vs[i];
    }
    cout<<s<<endl;
}