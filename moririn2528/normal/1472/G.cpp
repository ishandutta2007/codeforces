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

void solve(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n>>m;
    vector<vector<int>> path(n);
    for(i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        path[a].push_back(b);
    }
    vector<int> v1,dis(n,-1);
    queue<int> q1;
    vector<char> used(n,0);
    q1.push(0);
    for(i=0;!q1.empty();i++){
        c=q1.size();
        for(j=0;j<c;j++){
            a=q1.front();q1.pop();
            if(dis[a]!=-1)continue;
            dis[a]=i;
            v1.push_back(a);
            for(auto to:path[a]){
                q1.push(to);
            }
        }
    }
    reverse(v1.begin(),v1.end());
    vector<int> vs(n,INF);
    for(auto num:v1){
        vs[num]=dis[num];
        for(auto to:path[num]){
            if(dis[num]<dis[to])vs[num]=min(vs[num],vs[to]);
            else vs[num]=min(vs[num],dis[to]);
        }
    }
    array_show(vs);
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}