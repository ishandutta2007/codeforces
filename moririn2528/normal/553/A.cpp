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
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
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

LL dp[1111][1111];
LL kai[110000];

long long int pow_mod(long long int p_a,long long int p_n,long long int p_p=1e9+7){
    //p_a^p_n mod p_p
    long long int p_b=1,p_t=1;
    for(;p_b<=p_n;p_b<<=1);
    for(p_b>>=1;p_b>0;p_b>>=1){
        p_t*=p_t;
        if(p_t>=p_p)p_t%=p_p;
        if(p_n&p_b)p_t*=p_a;
        if(p_t>=p_p)p_t%=p_p;
    }
    return p_t;
}

long long int gcd(long long int g_a,long long int g_b){
    if(g_a<g_b)gcd(g_b,g_a);
    if(g_b==0)return g_a;
    return gcd(g_b,g_a%g_b);
}

long long int divide(long long int d_a,long long int d_b,long long int d_p=1e9+7){
    // d_a/d_b mod d_p
    // prime:d_p is prime
    if(d_a>=d_p)d_a%=d_p;
    if(d_a<0)d_a+=d_p;
    if(d_b>=d_p)d_b%=d_p;
    if(d_b<0)d_b+=d_p;
    d_a*=pow_mod(d_b,d_p-2,d_p);
    return d_a%d_p;
}

int main(){
    int n,m;
    int i,j,k;
    LL a,b,c;
    vector<int> v1;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(a);
    }
    reverse(v1.begin(),v1.end());
    dp[0][0]=1;
    kai[0]=1;
    for(i=1;i<1e5;i++){
        kai[i]=kai[i-1]*i%MAX;
    }
    b=0;
    for(i=0;i<n;i++){
        b+=v1[i];
        a=0;
        for(j=0;j<=b-v1[i];j++){
            a+=dp[i][j];
            a%=MAX;
            dp[i+1][j+1]=a*divide(kai[b-j-1],kai[v1[i]-1]*kai[b-j-v1[i]])%MAX;
        }
    }
    a=0;
    for(i=0;i<1e3+7;i++){
        a+=dp[n][i];
    }
    cout<<a%MAX<<endl;
}