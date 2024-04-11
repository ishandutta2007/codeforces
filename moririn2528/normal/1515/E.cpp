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

long long int pow_mod(long long int a,long long int n,long long int p=1e9+7){
    //a^n mod p
    long long int b=1,t=1;
    for(;b<=n;b<<=1);
    for(b>>=1;b>0;b>>=1){
        t*=t;
        if(t>=p)t%=p;
        if(n&b)t*=a;
        if(t>=p)t%=p;
    }
    return t;
}

long long int gcd(long long int a,long long int b){
    if(a<b)gcd(b,a);
    if(b==0)return a;
    return gcd(b,a%b);
}

long long int divide(long long int a,long long int b,long long int p=1e9+7){
    // a/b mod p
    // prime:p is prime
    if(a>=p)a%=p;
    if(a<0)a+=p;
    if(b>=p)b%=p;
    if(b<0)b+=p;
    a*=pow_mod(b,p-2,p);
    return a%p;
}

namespace sol{

    LL mod;
    const int N=6;
    LL dp[N][444][444][2];

    void solve(){
        LL n,m;
        int i,j,k,l;
        int i1,i2,i3;
        LL a,b,c;
        cin>>n>>m;
        mod=m;
        dp[0][1][0][0]=1;
        for(i=0;i<n;i++){
            i1=i%N,i2=(i+1)%N,i3=(i+2)%N;
            memset(dp[i3],0,sizeof(dp[i3]));
            for(j=1;j<=i+1;j++){
                for(k=0;k<j;k++){
                    for(l=0;l<2;l++){
                        if(dp[i1][j][k][l]<0)dp[i1][j][k][l]+=((-dp[i1][j][k][l])/mod+1)*mod;
                        dp[i1][j][k][l]%=mod;
                    }
                    dp[i2][j+1][0][0]+=dp[i1][j][k][0];
                    dp[i2][j+1][k+1][0]-=dp[i1][j][k][0];
                    dp[i2][j+1][k+1][1]+=dp[i1][j][k][0]+dp[i1][j][k][1];
                    dp[i3][j+1][0][0]+=dp[i1][j][k][0]+dp[i1][j][k][1];
                }
            }
            for(j=1;j<=i+2;j++){
                for(k=0;k<=j;k++){
                    for(l=0;l<2;l++){
                        dp[i2][j][k+1][l]+=dp[i2][j][k][l]%mod;
                    }
                }
            }
        }
        a=0;
        for(i=0;i<=n;i++){
            for(j=0;j<i;j++){
                for(k=0;k<2;k++){
                    a+=dp[(n-1)%N][i][j][k]%mod;
                }
            }
        }
        cout<<a%mod<<endl;
    }
}

int main(){
    sol::solve();
}