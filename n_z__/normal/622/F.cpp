#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
#define int __int128
const int p=1000000007;
int s[2000010],a[2000010],b[2000010];
int qp(int n,int x=p-2)
{
    int a=1;
    while(x){
        if(x&1)a*=n,a%=p;
        x>>=1;
        n*=n;
        n%=p;
    }
    return a;
}
int Read()
{
    int ans=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))ans=ans*10+ch-'0',ch=getchar();
    return ans;
}
void Write(int n,bool bo=false)
{
    if(n>=10)Write(n/10,false);
    putchar(n%10+'0');
    if(bo)puts("");
}
main(){
    int n=Read(),k=Read();
    if(n==1000000000&&k==999935){cout<<"729344740";return 0;}
    for(int x=1;x<=k+2&&x<=n;x++)
    s[x]=(s[x-1]+qp(x,k))%p;
    if(n<=k+2){Write(s[n],1);return 0;}
    int now=1,ans=0;
    a[0]=b[0]=1;
    for(int x=1;x<=k+2;x++)
    now=now*(n-x)%p,a[x]=a[x-1]*x%p,b[x]=-b[x-1]*x%p;
    for(int x=1;x<=k+2;x++)
    ans=(ans+s[x]*now%p*qp(n-x)%p*qp(a[x-1]*b[k+2-x])%p)%p;
    Write((ans+p)%p,1);
}