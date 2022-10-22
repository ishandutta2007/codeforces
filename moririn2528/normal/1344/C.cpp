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

bool used[220000][2];

void dfs(int pos,int mode,vector<vector<int>>& path){
    if(used[pos][mode])return;
    used[pos][mode]=true;
    for(auto to:path[pos]){
        dfs(to,mode,path);
    }
}

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n>>m;
    vector<vector<int>> path(n),rpath(n);
    vector<int> deg(n);
    for(i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        path[a].push_back(b);
        rpath[b].push_back(a);
        deg[b]++;
    }
    queue<int> q1;
    for(i=0;i<n;i++){
        if(deg[i]==0)q1.push(i);
    }
    for(i=0;!q1.empty();i++){
        a=q1.front();q1.pop();
        for(auto to:path[a]){
            deg[to]--;
            if(deg[to]==0)q1.push(to);
        }
    }
    if(i!=n){
        cout<<-1<<endl;
        return 0;
    }
    string ss(n,'E');
    int s=0;
    for(i=0;i<n;i++){
        if(!used[i][0] && !used[i][1])ss[i]='A',s++;
        dfs(i,0,path);
        dfs(i,1,rpath);
    }
    cout<<s<<endl;
    cout<<ss<<endl;
}