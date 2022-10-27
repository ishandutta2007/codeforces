#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long double ldbl;
typedef long long ll;
typedef double dbl;
const int N = 300300;
ll mem[N][2];
ll sum[N];
int a[N];
 
int n,m,k;
 
 
ll dp(int i,bool f){
    if(i > n)
        return 0;
 
    ll &ret = mem[i][f];
    if(ret != -1)
        return ret;
 
    if(!f){
        ret=0;
        for(int j=0 ; j<m ; j++)
            ret = max(ret,sum[min(i+j,n)]-sum[i-1]-k);
 
        ret = max(ret , sum[min(i+m-1,n)]-sum[i-1]-k + dp(i+m,1));
        ret = max(ret , dp(i+1,0));
 
        return ret;
    }
 
    ret=0;
    for(int j=0 ; j<m ; j++)
        ret = max(ret,sum[min(i+j,n)]-sum[i-1]-k);
 
    ret = max(ret , sum[min(i+m-1,n)]-sum[i-1]-k + dp(i+m,1));
 
    return ret;
 
}
 
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1 ; i<=n ; i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
 
    memset(mem,-1,sizeof mem);
    printf("%lld\n",dp(1,0));
 
    return 0;
}