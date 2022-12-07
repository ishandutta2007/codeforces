#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
const int MAXN=1000010;
int n,ans,M;
LL fac[MAXN],inv[MAXN];
char str[MAXN];
int used[MAXN];
LL qpow(LL x,LL n)
{
    LL p=x,con=1;
    while(n)
    {
        if(n&1) con=(con*p)%MOD;
        p=(p*p)%MOD;
        n>>=1;
    }
    return con;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",str);
    for(int i=0;i<n;i++)
        used[str[i]]++;
    M=used['A'];
    M=max(M,used['G']);
    M=max(M,used['C']);
    M=max(M,used['T']);
    if(used['A']==M) ans++;
    if(used['G']==M) ans++;
    if(used['C']==M) ans++;
    if(used['T']==M) ans++;
    cout<<qpow(ans,n)<<endl;
    return 0;
}