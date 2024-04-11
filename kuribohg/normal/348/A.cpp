#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n;
LL L,R,mid;
LL a[MAXN],sum;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    L=0,R=2000000000;
    while(L<R)
    {
        mid=(L+R)>>1;
        for(int i=1;i<=n;i++)
            if(a[i]>mid) L=mid+1;
        if(L==mid+1) continue;
        sum=0;
        for(int i=1;i<=n;i++) sum+=a[i];
        if(mid*n-mid>=sum) R=mid;
        else L=mid+1;
    }
    printf("%I64d\n",L);
    return 0;
}