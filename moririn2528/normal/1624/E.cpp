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

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        string sa;
        const int N=1e3;
        P pn={-1,-1};
        vector<P> v1(N,pn),v2(N,pn);
        vector<int> va;
        for(i=0;i<n;i++){
            cin>>sa;
            va.clear();
            for(j=0;j<m;j++){
                va.push_back(sa[j]-'0');
            }
            for(j=0;j+1<m;j++){
                a=va[j]*10+va[j+1];
                v1[a]={i,j};
            }
            for(j=0;j+2<m;j++){
                a=va[j]*100+va[j+1]*10+va[j+2];
                v2[a]={i,j};
            }
        }
        cin>>sa;
        va.clear();
        for(i=0;i<m;i++){
            va.push_back(sa[i]-'0');
        }
        vector<int> bef(m+2,-1),pos(m+2),id(m+2);
        bef[0]=0;
        for(i=0;i<m;i++){
            if(bef[i]==-1)continue;
            if(i+1<m){
                a=va[i]*10+va[i+1];
                if(v1[a]!=pn){
                    bef[i+2]=i;
                    pos[i+2]=v1[a].second;
                    id[i+2]=v1[a].first;
                }
            }
            if(i+2<m){
                a=va[i]*100+va[i+1]*10+va[i+2];
                if(v2[a]!=pn){
                    bef[i+3]=i;
                    pos[i+3]=v2[a].second;
                    id[i+3]=v2[a].first;
                }
            }
        }
        vector<T> vs;
        for(i=m;i>0;i=bef[i]){
            vs.push_back({pos[i]+1,pos[i]+i-bef[i],id[i]+1});
        }
        if(i==-1){
            cout<<-1<<endl;
            return;
        }
        reverse(vs.begin(),vs.end());
        cout<<vs.size()<<endl;
        for(auto node:vs){
            tie(a,b,c)=node;
            cout<<a<<" "<<b<<" "<<c<<endl;
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