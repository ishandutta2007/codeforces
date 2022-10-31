#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100000
int a[MAXN+10],n,mx,b[MAXN+10];
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=n;i;i--){
        b[i]=max(mx+1-a[i],0);
        mx=max(a[i],mx);
    }
    for(i=1;i<n;i++)
        printf("%d ",b[i]);
    printf("%d\n",b[n]);
}