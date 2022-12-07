#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int n,p[MAXN],b[MAXN],sumb,ans,res;
bool used[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]),sumb+=b[i];
    if(sumb%2==0) ans++;
    for(int i=1;i<=n;i++)
        if(!used[i])
        {
            int x=i;
            used[x]=true;
            while(!used[p[x]]) used[p[x]]=true,x=p[x];
            res++;
        }
    if(res==1) printf("%d\n",ans);
    else printf("%d\n",ans+res);
    return 0;
}