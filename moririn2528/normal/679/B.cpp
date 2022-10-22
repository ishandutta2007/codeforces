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
template<typename T> ostream& operator<<(ostream& os,const pair<T,T>& p){
    os<<p.first<<" "<<p.second;
    return os;
}
template<typename T> istream& operator>>(istream& is,vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++)is>>v1[i];
    return is;
}



namespace sol{

    const int N=1e6+7;
    int cnt[N+10];
    int max_cnt_id[N+10];

    LP calc(LL x){
        if(x<N){
            x=max_cnt_id[x];
            return {cnt[x],x};
        }
        LL a=cbrt(x)-5;
        a=max(a,0LL);
        for(;a*a*a<=x;a++);
        a--;
        LL b=(a-1)*(a-1)*(a-1),c=a*a*a;
        LP p1=calc(x-c);
        LP p2=calc(c-b-1);
        if(p2.first<=p1.first)return {p1.first+1,p1.second+c};
        return {p2.first+1,p2.second+b};
    }

    void solve(){
        int n,m;
        int i,j,k;
        LL a,b,c;
        LL x,y;
        a=1,b=0;
        for(i=1;i<=N;i++){
            x=(a+1)*(a+1)*(a+1);
            if(x<=i)a++;
            x=a*a*a;
            cnt[i]=cnt[i-x]+1;
            if(cnt[b]<=cnt[i])b=i;
            max_cnt_id[i]=b;
        }
        cin>>x;
        LP p=calc(x);
        cout<<p<<endl;
    }
}

int main(){
    sol::solve();
}