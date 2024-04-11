#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,a[MAXN],k,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    k=1,ans=1;;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1]) k++;
        else k=1;
        ans=max(ans,k);
    }
    printf("%d\n",ans);
    return 0;
}