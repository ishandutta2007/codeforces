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
typedef pair<LL,LL> P;
typedef pair<LL,int> LP;
const LL INF=1LL<<60;
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

namespace sol{

    vector<vector<P>> path;
    vector<vector<LL>> dis;
    typedef tuple<LL,int,int> T;

    void solve(){
        int n,m;
        int i,j,k;
        LL a,b,c;
        cin>>n>>m;
        path.assign(n,vector<P>());
        for(i=0;i<m;i++){
            cin>>a>>b>>c;
            a--,b--;
            path[a].push_back(make_pair(b,c));
            path[b].push_back(make_pair(a,c));
        }
        dis.assign(n,vector<LL>(4,INF));
        priority_queue<T,vector<T>,greater<T>> q1;
        q1.push(make_tuple(0,0,0));
        while(!q1.empty()){
            tie(a,b,c)=q1.top();q1.pop();
            if(dis[b][c]!=INF)continue;
            dis[b][c]=a;
            for(auto node:path[b]){
                int to=node.first,cost=node.second;
                q1.push(make_tuple(a+cost,to,c));
                if(~c&1)q1.push(make_tuple(a,to,c+1));
                if(~c&2)q1.push(make_tuple(a+cost*2,to,c+2));
                if(c==0)q1.push(make_tuple(a+cost,to,3));
            }
        }
        for(i=1;i<n;i++){
            if(i>1)cout<<" ";
            cout<<dis[i][3];
        }
        cout<<endl;
    }
}

int main(){
    sol::solve();
}