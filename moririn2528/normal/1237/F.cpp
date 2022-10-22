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
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=998244353;

void array_show(int *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%d%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%lld%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}

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

long long int divide(long long int d_a,long long int d_b,long long int d_p=1e9+7,bool prime=true){
    // d_a/d_b mod d_p
    // prime:d_p is prime or not
    if(d_a>=d_p)d_a%=d_p;
    if(d_a<0)d_a+=d_p;
    if(d_b>=d_p)d_b%=d_p;
    if(d_b<0)d_b+=d_p;
    if(!prime){
        long long int d_d=gcd(d_a,d_b);
        if(d_d>1)d_a/=d_d,d_b/=d_d;
    }
    d_a*=pow_mod(d_b,d_p-2,d_p);
    return d_a%d_p;
}

LL dp[2000][5000];
bool used[2][5005];
LL num[2][5005];
LL lim[2];
LL kai[5005];
LL memo[5000][5000];

LL calcP(LL a,LL b){
    if(memo[a][b]!=-1)return memo[a][b];
    memo[a][b]=divide(kai[a],kai[a-b],MAX);
    return memo[a][b];
}

int main(){
    LL n,h,w;
    int i,j,k;
    LL a,b,c;
    cin>>h>>w>>n;
    a=max(h,w);
    for(i=0;i<=a;i++){
        b=1;
        for(j=0;j<=i;j++){
            memo[i][j]=b;
            b*=i-j;
            if(b>=MAX)b%=MAX;
        }
    }
    for(i=0;i<2*n;i++){
        cin>>a>>b;
        a--,b--;
        used[0][a]=true,used[1][b]=true;
    }
    used[0][h]=true,used[1][w]=true;
    LL m[2]={h,w};
    for(i=0;i<2;i++){
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(j=0;j<=m[i]/2;j++){
            for(k=0;k<m[i];k++){
                if(dp[j][k]>=MAX)dp[j][k]%=MAX;
                dp[j][k+1]+=dp[j][k];
                if(!dp[j][k])continue;
                if(used[i][k] || used[i][k+1])continue;
                dp[j+1][k+2]+=dp[j][k];
            }
        }
        for(j=0;j<=m[i]/2;j++){
            num[i][j]=dp[j][m[i]]%MAX;
        }
        for(j=0;j<m[i];j++){
            if(!used[i][j])lim[i]++;
        }
    }
    LL s=0;
    for(i=0;i<=h/2;i++){
        if(i*2>lim[0] || i>lim[1])break;
        for(j=0;j<=w/2;j++){
            if(i*2+j>lim[0] || i+j*2>lim[1])break;
            a=memo[lim[0]-i*2][j]*memo[lim[1]-j*2][i]%MAX;
            a=a*num[0][i];
            if(a>=MAX)a%=MAX;
            s+=a*num[1][j];
            if(s>=MAX)s%=MAX;
        }
    }
    cout<<s<<endl;
}