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

    void init(){
        
    }

    typedef tuple<LL,LL,LL,LL> T;

    void solve(){
        LL n,m,t;
        int i,j,k;
        LL a,b,c,d,e;
        cin>>n>>m>>t;
        vector<LL> v1(n);
        vector<vector<T>> vt(n+1);
        vector<vector<LP>> v2(n+1);
        cin>>v1;
        for(i=0;i<t;i++){
            cin>>a>>b>>c>>d>>e;
            a--,b--,c--,d--;
            vt[a].push_back({b,c,d,e});
        }
        vt[n-1].push_back({m-1,n,0,0});
        v2[0].push_back(P(0,0));
        for(i=0;i<n;i++){
            sort(vt[i].begin(),vt[i].end());
            sort(v2[i].begin(),v2[i].end());
            for(j=1;j<v2[i].size();j++){
                v2[i][j].second=min(v2[i][j].second,v2[i][j-1].second+v1[i]*(v2[i][j].first-v2[i][j-1].first));
            }
            for(j=(int)v2[i].size()-1;j>0;j--){
                v2[i][j-1].second=min(v2[i][j-1].second,v2[i][j].second+v1[i]*(v2[i][j].first-v2[i][j-1].first));
            }
            for(j=0,k=0;j<vt[i].size();j++){
                tie(a,b,c,d)=vt[i][j];
                for(;k<v2[i].size() && v2[i][k].first<a;k++);
                e=2*INF;
                if(k<v2[i].size())e=min(e,v1[i]*(v2[i][k].first-a)+v2[i][k].second);
                if(k)e=min(e,v1[i]*(a-v2[i][k-1].first)+v2[i][k-1].second);
                v2[b].push_back({c,e-d});
            }
        }
        a=v2[n][0].second;
        if(a>=INF)cout<<"NO ESCAPE"<<endl;
        else cout<<v2[n][0].second<<endl;
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