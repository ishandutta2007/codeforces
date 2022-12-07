#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int n;
LL a[510][510],sum,k,kk;
bool check()
{
    LL sum=0;
    for(int i=1;i<=n;i++) sum+=a[1][i];
    for(int i=1;i<=n;i++)
    {
        LL s=0;
        for(int j=1;j<=n;j++)
            s+=a[i][j];
        if(s!=sum) return false;
    }
    for(int j=1;j<=n;j++)
    {
        LL s=0;
        for(int i=1;i<=n;i++)
            s+=a[i][j];
        if(s!=sum) return false;
    }
    LL s=0;
    for(int i=1;i<=n;i++) s+=a[i][i];
    if(s!=sum) return false;
    s=0;
    for(int i=1;i<=n;i++) s+=a[i][n+1-i];
    if(s!=sum) return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%I64d",&a[i][j]);
    if(n==1) {puts("1");return 0;}
    for(int i=1;i<=n;i++)
    {
        sum+=a[1][i];
        if(a[1][i]==0) sum=-100000000000000LL;
    }
    if(sum<0)
    {
        sum=0;
        for(int i=1;i<=n;i++)
            sum+=a[2][i];
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]==0) k=i,kk=j;
    for(int j=1;j<=n;j++) sum-=a[k][j];
    a[k][kk]=sum;
    if(check()&&sum>0) printf("%I64d\n",sum);
    else puts("-1");
    return 0;
}