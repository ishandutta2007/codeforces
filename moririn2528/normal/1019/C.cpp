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

vector<vector<int>> path,rpath;
vector<char> used;
vector<int> vs,vs2;

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    bool flag;
    scanf("%d%d",&n,&m);
    path.assign(n,vector<int>());
    rpath.assign(n,vector<int>());
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        a--,b--;
        path[a].push_back(b);
        rpath[b].push_back(a);
    }
    used.assign(n,0);
    for(i=0;i<n;i++){
        if(used[i])continue;
        vs.push_back(i);
        used[i]=1;
        for(auto to:path[i])used[to]=1;
    }
    reverse(vs.begin(),vs.end());
    used.assign(n,0);
    for(i=0;i<vs.size();i++){
        flag=false;
        for(auto par:rpath[vs[i]]){
            if(used[par])flag=true;
        }
        if(!flag){
            vs2.push_back(vs[i]+1);
            used[vs[i]]=1;
        }
    }
    cout<<vs2.size()<<endl;
    array_show(vs2);
}