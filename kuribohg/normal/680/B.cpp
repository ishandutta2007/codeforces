#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a,ans;
int t[101];
int main()
{
    scanf("%d%d",&n,&a);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    if(t[a]) ans++;
    for(int d=1;d<=n;d++)
    {
        int l=a-d,r=a+d,k=0,kk=0;
        if(l>0&&t[l]) k++;
        if(r<=n&&t[r]) k++;
        if(l>0) kk++;
        if(r<=n) kk++;
        if(k==kk) ans+=kk;
    }
    printf("%d\n",ans);
    return 0;
}