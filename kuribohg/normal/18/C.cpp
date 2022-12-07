#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n,a[100010],sum,p,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]);sum+=a[i];}
    for(int i=1;i<n;i++)
    {
        p+=a[i];
        if((p<<1)==sum) ans++;
    }
    printf("%d\n",ans);
    return 0;
}