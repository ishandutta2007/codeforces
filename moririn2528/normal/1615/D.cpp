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
template<typename T1,typename T2> istream& operator>>(istream& is,pair<T1,T2>& p){
    is>>p.first>>p.second;
    return is;
}

namespace sol{
    typedef tuple<int,int,int> T;

    void init(){
        
    }
    
    vector<vector<P>> path;
    vector<int> col;

    bool check(int pos,int c){
        if(col[pos]!=-1)return col[pos]==c;
        col[pos]=c;
        for(auto node:path[pos]){
            int to=node.first,ct=node.second;
            if(!check(to,c^ct))return false;
        }
        return true;
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        path.assign(n,vector<P>());
        col.assign(n,-1);
        vector<T> path2;
        for(i=0;i<n-1;i++){
            cin>>a>>b>>c;
            a--,b--;
            path2.push_back({a,b,c});
            if(c==-1)continue;
            c=__builtin_popcount(c)%2;
            path[a].push_back({b,c});
            path[b].push_back({a,c});
        }
        for(i=0;i<m;i++){
            cin>>a>>b>>c;
            a--,b--;
            path[a].push_back({b,c});
            path[b].push_back({a,c});
        }
        for(i=0;i<n;i++){
            if(col[i]!=-1)continue;
            if(!check(i,0)){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
        for(i=0;i<n-1;i++){
            tie(a,b,c)=path2[i];
            if(c==-1)c=col[a]^col[b];
            cout<<a+1<<" "<<b+1<<" "<<c<<endl;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,i;
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}