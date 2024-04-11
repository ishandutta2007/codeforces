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
template<typename T> ostream& operator<<(ostream& os,const vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++){
        if(i)os<<" ";
        os<<v1[i];
    }
    return os;
}
template<typename T1,typename T2> ostream& operator<<(ostream& os,const pair<T1,T2>& p){
    os<<p.first<<" "<<p.second;
    return os;
}
template<typename T> istream& operator>>(istream& is,vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++)is>>v1[i];
    return is;
}

namespace sol{
    vector<vector<int>> path;
    vector<int> vs;
    vector<char> used;

    void dfs2(int pos,int bef){
        if(used[pos])return;
        vs.push_back(pos);
        used[pos]=1;
        for(auto to:path[pos]){
            if(to==bef)continue;
            dfs2(to,pos);
        }
    }

    void dfs1(int pos,int bef){
        int deg=0;
        if(bef!=-1)deg++;
        for(auto to:path[pos]){
            if(to==bef)continue;
            dfs1(to,pos);
            if(!used[to])deg++;
        }
        if(deg%2==0)dfs2(pos,bef);
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        path.resize(n);
        for(i=0;i<n;i++){
            cin>>a;
            if(a==0)continue;
            a--;
            path[i].push_back(a);
            path[a].push_back(i);
        }
        used.resize(n);
        for(i=0,j=0;i<n;i++){
            if(path[i].size()%2==0)j++;
        }
        if(j%2)cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
            return;
        }
        dfs1(0,-1);
        for(auto num:vs){
            cout<<num+1<<endl;
        }
    }
}

int main(){
    sol::solve();
}