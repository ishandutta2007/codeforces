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

ll n,m;
int a[110],b[110];
int l1,l2;

int main()
{
    read(n),read(m);
    l1=l2=0;
    while (n)
    {
        a[++l1]=n&1;
        n>>=1;
    }
    while (m)
    {
        b[++l2]=m&1;
        m>>=1;
    }
    int ans=0;
    for (int i=l1+1;i<=l2;i++)
        ans+=i-1;
    int pos=0,ha=0;
    for (int i=1;i<=l1;i++)
    if (a[i]==0)
    {
        ha++,pos=i;
    }
    if (ha==0)  ans+=0;else
    {
        ans+=pos;
    }
    pos=0,ha=0;
    for (int i=1;i<=l2;i++)
    if (b[i]==0)
    {
        ha++,pos=i;
    }
    if (ha==0)  ans-=0;else
    {
        ans-=pos;
        if (ha==1)  ans++;
    }
    printf("%d\n",ans);
    return 0;
}