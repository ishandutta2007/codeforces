#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
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

#define maxn 5010
const ll mo=1e9+7;
int a[maxn];
int f[maxn][maxn];
ll g[maxn][maxn];
int n;

void build()
{
    for (int i=n;i;i--)
        for (int j=n;j;j--)
        if (a[i]==a[j]) f[i][j]=f[i+1][j+1]+1;
}

int compa(int l,int r,int ql,int qr) // 1= [ql,qr]>[l,r]
{
    if ((qr-ql+1)>(r-l+1))  return 1;
    if ((qr-ql+1)<(r-l+1))  return 0;
    int len=r-l+1;
    if (f[l][ql]>=len)  return 0;
    return a[ql+f[l][ql]]>a[l+f[l][ql]];
}
int main()
{
    read(n);
    for (int i=1;i<=n;i++)
    {
        char ch=getchar();
        while (!(ch<='9' && ch>='0'))   ch=getchar();
        a[i]=ch-'0';
    }
    build();
    for (int i=1;i<=n;i++)  g[1][i]=1;
    for (int i=1;i<n;i++)
    if (a[i+1]!=0)
    {
        ll sum=0;
        int k=i;
        for (int j=i+1;j<=n;j++)
        {
            while (k>=1 && compa(k,i,i+1,j))    {sum=(sum+g[k][i])%mo;k--;}
            g[i+1][j]=(g[i+1][j]+sum)%mo;
        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++)  ans=(ans+g[i][n])%mo;
    cout<<ans<<endl;
    return 0;
}