#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int n,a[MAXN],c[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        c[a[i]]++;
    }
    int ans=1;
    for(int i=2;i<=100000;i++)
    {
        int res=0;
        for(int j=i;j<=100000;j+=i)
            res+=c[j];
        ans=max(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}