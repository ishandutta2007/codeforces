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
    int nest=0;
    vector<vector<P>> path;
    typedef tuple<int,int,int> T;
    vector<T> vs;

    int dfs(int pos,int bef,int t){
        vector<int> v1;
        int a;
        int cnt=0;
        for(auto node:path[pos]){
            int to=node.first,cost=node.second;
            if(to==bef)continue;
            a=dfs(to,pos,cost);
            if(a==-1)return -1;
            t-=cost;
            v1.push_back(a);
            cnt++;
        }
        if(pos==nest)return 0;
        if(cnt==0)v1.push_back(pos);
        if(t==0)return v1[0];
        if(cnt==0){
            vs.push_back({nest,pos,t});
            return pos;
        }
        if(v1.size()<=1)return -1;
        int x=v1[0],y=v1[1];
        vs.push_back({nest,x,t/2});
        vs.push_back({nest,y,t/2});
        vs.push_back({x,y,-t/2});
        return v1[0];
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        path.resize(n);
        for(i=0;i<n-1;i++){
            cin>>a>>b>>c;
            a--,b--;
            path[a].push_back({b,c});
            path[b].push_back({a,c});
        }
        for(i=0;i<n;i++){
            if(path[i].size()==1)nest=i;
        }
        if(dfs(nest,-1,0)==-1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            cout<<vs.size()<<endl;
            for(i=0;i<vs.size();i++){
                tie(a,b,c)=vs[i];
                cout<<a+1<<" "<<b+1<<" "<<c<<endl;
            }
        }
    }
}

int main(){
    sol::solve();
}