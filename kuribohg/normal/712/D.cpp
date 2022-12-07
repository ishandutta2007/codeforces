#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
const int DELTA=100001;
const int N=200001;
int a,b,k,t,ans;
int f[300010],d[300010],s[300010];
int main()
{
    cin>>a>>b>>k>>t;
    f[0+DELTA]=1;
    while(t--)
    {
        for(int i=1;i<=N;i++) d[i]=0;
        for(int i=1;i<=N;i++)
            if(f[i]) d[i-k]=(d[i-k]+f[i])%MOD,d[i+k+1]=(d[i+k+1]-f[i]+MOD)%MOD;
        for(int i=1;i<=N;i++)
            f[i]=(f[i-1]+d[i])%MOD;
    }
    for(int i=1;i<=N;i++)
        s[i]=(s[i-1]+f[i])%MOD;
    for(int i=-100000;i<=100000;i++)
        if(a+i-b-1+DELTA<=N&&a+i-b-1+DELTA>=0) ans=(ans+((LL)f[i+DELTA]*s[a+i-b-1+DELTA])%MOD)%MOD;
        else if(a+i-b-1+DELTA>N) ans=(ans+((LL)f[i+DELTA]*s[N])%MOD)%MOD;
    cout<<ans<<endl;
    return 0;
}