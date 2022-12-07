#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long LL;
const int MAXN=1000010;
int n;
LL a[MAXN],b[MAXN];
bool p[MAXN];
LL f[MAXN][2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    for(int i=2;i<n;i++)
        if((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))
            p[i]=true;
    for(int i=1;i<n;i++) b[i]=max(a[i+1]-a[i],a[i]-a[i+1]);
    f[1][0]=0,f[1][1]=b[1];
    for(int i=2;i<n;i++)
    {
        if(!p[i]) f[i][1]=max(f[i-1][0],f[i-1][1])+b[i],f[i][0]=max(f[i-1][0],f[i-1][1]);
        else f[i][1]=f[i-1][0]+b[i],f[i][0]=max(f[i-1][0],f[i-1][1]);
    }
    printf("%I64d\n",max(f[n-1][0],f[n-1][1]));
    return 0;
}