#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,m,a[110],s,ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(s+a[i]>m) ans++,s=0;
        s+=a[i];
    }
    if(s) ans++;
    printf("%d\n",ans);
    return 0;
}