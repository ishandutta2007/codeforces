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
typedef pair<LL,int> LP;
const int INF=1<<30;
const int MAX=1e6;

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
    vector<vector<int>> path;
    vector<tuple<int,int,int>> vs;
    vector<int> sz,dis;

    int calc_nest(int pos,int bef,int n){
        int s;
        bool flag=true;
        for(auto to:path[pos]){
            if(to==bef)continue;
            s=calc_nest(to,pos,n);
            if(s!=-1)return s;
            sz[pos]+=sz[to];
            if(sz[to]*2>n)flag=false;
        }
        sz[pos]++;
        if((n-sz[pos])*2>n)flag=false;
        if(flag)return pos;
        return -1;
    }

    void calc_size(int pos,int bef){
        sz[pos]=1;
        for(auto to:path[pos]){
            if(to==bef)continue;
            calc_size(to,pos);
            sz[pos]+=sz[to];
        }
    }

    int calc(int pos,int bef,int& d,int inc){
        dis[pos]=d;
        d+=inc;
        d=min(d,MAX);
        vs.push_back({pos,bef,dis[pos]-dis[bef]});
        int s=dis[pos];
        for(auto to:path[pos]){
            if(to==bef)continue;
            s=max(s,calc(to,pos,d,inc));
        }
        return s;
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        path.assign(n,vector<int>());
        for(i=0;i<n-1;i++){
            cin>>a>>b;
            a--,b--;
            path[a].push_back(b);
            path[b].push_back(a);
        }
        sz.assign(n,0);
        int nes=calc_nest(0,-1,n);
        //cout<<nes<<endl;
        calc_size(nes,-1);
        dis.assign(n,0);
        vector<int> v1(n);
        bool flag=false;
        for(auto to:path[nes]){
            if(sz[to]*3>=n){
                v1[to]=1;
                flag=true;
                break;
            }
        }
        if(!flag){
            a=0;
            for(auto to:path[nes]){
                a+=sz[to];
                v1[to]=1;
                if(a*3>=n)break;
            }
        }
        //array_show(v1);
        a=1;
        for(auto to:path[nes]){
            if(v1[to])continue;
            calc(to,nes,a,1);
        }
        b=a;
        for(auto to:path[nes]){
            if(!v1[to])continue;
            calc(to,nes,a,b);
        }
        for(auto node:vs){
            tie(a,b,c)=node;
            cout<<a+1<<" "<<b+1<<" "<<c<<endl;
        }
    }
}

int main(){
    sol::solve();
}