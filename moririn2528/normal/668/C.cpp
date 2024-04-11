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

typedef long double D;

void array_show(vector<D>& v){
    int n=v.size();
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        if(v[i]<0)v[i]=0;
        cout<<v[i];
    }
    cout<<endl;
}

namespace sol{

    void solve(){
        int n,m;
        int i,j,k;
        D a,b,c;
        D x,y;
        cin>>n;
        vector<D> v1(n),v2(n);
        for(int iI=0;iI<n;iI++)cin>>v1[iI];
        for(int iI=0;iI<n;iI++)cin>>v2[iI];
        for(i=1;i<n;i++)v1[i]+=v1[i-1];
        for(i=n-1;i>0;i--)v2[i-1]+=v2[i];
        vector<D> vx(n),vy(n);
        for(i=0;i<n-1;i++){
            a=v1[i]-v2[i+1];
            b=(v1[i]+v2[i+1]-0.5)/2;
            c=a*a-4*b;
            if(c<0)c=0;
            x=(a+sqrtl(c))/2;
            y=(a-sqrtl(c))/2;
            x+=0.5,y+=0.5;
            vx[i]=x,vy[i]=y;
        }
        vx.back()=1,vy.back()=1;
        for(i=n-1;i>0;i--){
            vx[i]-=vx[i-1];
            vy[i]-=vy[i-1];
        }
        array_show(vx);
        array_show(vy);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(15);
    sol::solve();
}