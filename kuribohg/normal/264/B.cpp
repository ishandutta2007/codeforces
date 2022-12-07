#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
const int N=100000;
int n,a[MAXN];
int f[MAXN],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int con=0;
        for(int j=1;j*j<=a[i];j++)
            if(a[i]%j==0)
            {
                if(j!=1) con=max(con,f[j]);
                if(j*j!=a[i]) con=max(con,f[a[i]/j]);
            }
        for(int j=1;j*j<=a[i];j++)
            if(a[i]%j==0)
            {
                f[j]=max(f[j],con+1);
                if(j*j!=a[i]) f[a[i]/j]=max(f[a[i]/j],con+1);
            }
    }
    for(int i=1;i<=N;i++) ans=max(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}