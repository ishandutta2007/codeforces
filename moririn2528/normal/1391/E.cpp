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

void init(){
    
}

int n,m;
vector<vector<int>> path;
vector<char> used;
vector<int> nodes;
vector<vector<int>> vec_dep;

int create_tree(int pos, int dep){
    if(used[pos])return -1;
    vec_dep[dep].push_back(pos);
    nodes.push_back(pos+1);
    used[pos]=1;
    if(dep+1>=(n+1)/2){
        return 1;
    }
    for(auto to:path[pos]){
        if(create_tree(to,dep+1)==1)return 1;
    }
    nodes.pop_back();
    return 0;
}

void solve(){
    int i,j,k;
    int a,b,c;
    scanf("%d%d",&n,&m);
    path.assign(n,vector<int>());
    used.assign(n,0);
    vec_dep.assign(n,vector<int>());
    nodes.clear();
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        a--,b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    if(create_tree(0,0)==1){
        printf("PATH\n");
        printf("%d\n",nodes.size());
        array_show(nodes);
        return;
    }
    printf("PAIRING\n");
    vector<P> vs;
    for(i=0;i<n;i++){
        for(j=0;j<vec_dep[i].size()/2;j++){
            vs.push_back(make_pair(vec_dep[i][2*j],vec_dep[i][2*j+1]));
        }
    }
    printf("%d\n",vs.size());
    for(i=0;i<vs.size();i++){
        printf("%d %d\n",vs[i].first+1,vs[i].second+1);
    }
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}