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
    const int N=5e5,M=1e5+7;


    void solve(){
        LL n,m;
        LL h,w;
        int i,j,k;
        LL a,b,c;
        LL x=0,y=0,mx=1,my=1,t=0;
        vector<P> pos;
        vector<vector<vector<LL>>> v(2,vector<vector<LL>>(3*M));
        cin>>h>>w;
        cin>>n;
        vector<LL> vs(n,-1);
        for(i=0;i<n;i++){
            cin>>a>>b;
            pos.push_back({a,b});
            v[0][b-a+M].push_back(i);
            v[1][b+a+M].push_back(i);
        }
        for(i=0;i<N;i++){
            a=1-(mx*my+1)/2;
            if(a==0)b=y-x+M;
            else b=x+y+M;
            for(auto id:v[a][b]){
                if(vs[id]!=-1)continue;
                vs[id]=t+abs(x-pos[id].first);
            }
            v[a][b].clear();

            if(mx==1)a=h-x;
            else a=x;
            if(my==1)b=w-y;
            else b=y;
            c=min(a,b);
            x+=mx*c,y+=my*c,t+=c;
            if(a<=b)mx=-mx;
            if(a>=b)my=-my;
        }
        for(auto num:vs){
            cout<<num<<endl;
        }
    }
}

int main(){
    sol::solve();
}