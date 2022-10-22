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

namespace sol{

    void init(){
        
    }

    vector<int> trail;

    bool dfs(int pos,int bef,int goal,vector<vector<int>>& path){
        if(pos==goal)return true;
        for(auto to:path[pos]){
            if(to==bef)continue;
            trail.push_back(to);
            if(dfs(to,pos,goal,path))return true;
            trail.pop_back();
        }
        return false;
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        vector<vector<int>> path(n);
        for(i=0;i<n-1;i++){
            cin>>a>>b;
            a--,b--;
            path[a].push_back(b);
            path[b].push_back(a);
        }
        vector<int> v1,v2;
        vector<int> used(n),used2(n);
        cin>>a;
        for(i=0;i<a;i++){
            cin>>b;
            b--;
            v1.push_back(b);
            used[b]=1;
        }
        cin>>a;
        for(i=0;i<a;i++){
            cin>>b;
            b--;
            v2.push_back(b);
            used2[b]=1;
        }
        a=v1[0],b=v2[0];
        cout<<"B "<<b+1<<endl;
        cin>>b;
        b--;
        trail.clear();
        trail.push_back(a);
        dfs(a,-1,b,path);
        for(auto pos:trail){
            if(!used[pos])break;
            a=pos;
        }
        cout<<"A "<<a+1<<endl;
        cin>>b;
        b--;
        if(used2[b])cout<<"C "<<a+1<<endl;
        else cout<<"C "<<-1<<endl;
    }
}

int main(){
    int n,i;
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}