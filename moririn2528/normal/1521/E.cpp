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
template<typename T> ostream& operator<<(ostream& os,const vector<vector<T>>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++){
        if(i)os<<endl;
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

    bool check(LL w,int n,int ma){
        LL a=w*w/2,b=(w+1)/2;
        b*=b;
        if(a+b<n)return false;
        a/=2;
        return ma<=a+b;
    }

    void put(int x,int y,vector<vector<int>>& va,vector<P>& vp){
        if(vp.empty())return;
        vp.back().first--;
        va[x][y]=vp.back().second;
        if(vp.back().first==0)vp.pop_back();
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        vector<int> v1(m);
        cin>>v1;
        a=0;
        for(i=0;i<m;i++){
            a=max(a,v1[i]);
        }
        LL z[3]={0,(LL)1e5};
        while(z[1]-z[0]>1){
            z[2]=(z[0]+z[1])/2;
            if(check(z[2],n,a))z[1]=z[2];
            else z[0]=z[2];
        }
        int p=z[1];
        cout<<p<<endl;
        vector<vector<int>> vs(p,vector<int>(p));
        vector<P> vp;
        for(i=0;i<m;i++){
            if(v1[i])vp.push_back({v1[i],i+1});
        }
        sort(vp.begin(),vp.end());
        for(i=1;i<p;i+=2){
            for(j=0;j<p;j+=2){
                put(i,j,vs,vp);
            }
        }
        for(i=0;i<p;i+=2){
            for(j=0;j<p;j+=2){
                put(i,j,vs,vp);
            }
        }
        for(i=0;i<p;i+=2){
            for(j=1;j<p;j+=2){
                put(i,j,vs,vp);
            }
        }
        cout<<vs<<endl;

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