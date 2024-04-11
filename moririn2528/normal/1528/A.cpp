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

    void init(){
        
    }

    vector<vector<LL>> vt,path,vs;

    LL calc(int pos,int bef){
        int i,j;
        LL a,b;
        for(auto to:path[pos]){
            if(to==bef)continue;
            calc(to,pos);
            for(i=0;i<2;i++){
                a=0;
                for(j=0;j<2;j++){
                    b=abs(vt[pos][i]-vt[to][j])+vs[to][j];
                    a=max(a,b);
                }
                vs[pos][i]+=a;
            }
        }
    }

    void solve(){
        int n,m;
        int i,j,k;
        LL a,b,c;
        cin>>n;
        vt.assign(n,vector<LL>(2,0));
        vs.assign(n,vector<LL>(2,0));
        path.assign(n,vector<LL>());
        cin>>vt;
        for(i=0;i<n-1;i++){
            cin>>a>>b;
            a--,b--;
            path[a].push_back(b);
            path[b].push_back(a);
        }
        calc(0,-1);
        cout<<max(vs[0][0],vs[0][1])<<endl;
    }
}

int main(){
    int n,i;
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}