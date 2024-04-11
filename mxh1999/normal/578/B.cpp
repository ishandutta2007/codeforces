#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(ll &digit)
{
    digit=0;
    char c;
    for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
    bool type=false;
    if (c=='-')
        type=true,c=getchar();
    for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
    if (type==true)
        digit=-digit;
}

#define maxn 200010
ll n,m,x;
ll a[maxn],pre[maxn],suf[maxn];
int main()
{
    read(n),read(m),read(x);
    for (int i=1;i<=n;i++)  read(a[i]);
    for (int i=1;i<=n;i++)  pre[i]=pre[i-1]|a[i];
    for (int i=n;i>=1;i--)  suf[i]=suf[i+1]|a[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)  a[i]*=x;
    ll ans=0;
    for (int i=1;i<=n;i++)
    if ((pre[i-1]|a[i]|suf[i+1])>ans)   ans=pre[i-1]|a[i]|suf[i+1];
    printf("%I64d\n",ans);
    return 0;
}