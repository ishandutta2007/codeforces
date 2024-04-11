#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
char s[100010];
int len,l[100010],r[100010],tot;
LL sz[100010],sum,ans,ans2;
int main()
{
    scanf("%s",s);
    len=strlen(s);
    l[++tot]=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i]==s[i-1]) continue;
        else r[tot]=i-1,l[++tot]=i;
    }
    tot--;
    for(int i=1;i<=tot;i++) sz[i]=(LL)r[i]-(LL)l[i]+1LL;
    for(int i=1;i<=tot;i+=2) ans+=sum*sz[i],sum+=sz[i];
    sum=0;
    for(int i=2;i<=tot;i+=2) ans+=sum*sz[i],sum+=sz[i];
    for(int i=1;i<=tot;i++) ans+=(sz[i]+1)*sz[i]/2;
    for(int i=1;i<=tot;i++)
        if(l[i]%2==0||r[i]%2==0) sz[i]=(r[i]-l[i])/2+1;
        else sz[i]=(r[i]-l[i])/2;
    sum=0;
    for(int i=1;i<=tot;i+=2) ans2+=sum*sz[i],sum+=sz[i];
    sum=0;
    for(int i=2;i<=tot;i+=2) ans2+=sum*sz[i],sum+=sz[i];
    for(int i=1;i<=tot;i++) ans2+=(sz[i]+1)*sz[i]/2;
    for(int i=1;i<=tot;i++) sz[i]=(r[i]-l[i]+1)-sz[i];
    sum=0;
    for(int i=1;i<=tot;i+=2) ans2+=sum*sz[i],sum+=sz[i];
    sum=0;
    for(int i=2;i<=tot;i+=2) ans2+=sum*sz[i],sum+=sz[i];
    for(int i=1;i<=tot;i++) ans2+=(sz[i]+1)*sz[i]/2;
    cout<<ans-ans2<<" "<<ans2<<endl;
    return 0;
}