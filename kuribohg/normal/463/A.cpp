#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,s,a[110],b[110],ans=-1;
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    for(int i=1;i<=n;i++)
        if(a[i]<s||(b[i]==0&&a[i]==s))
        {
            int tmp=100-b[i];
            if(tmp==100) tmp=0;
            ans=max(ans,tmp);
        }
    printf("%d\n",ans);
    return 0;
}