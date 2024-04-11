#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,d[1<<20];
double p[20],s[1<<20],ans[20];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<(1<<n);i++) d[i]=d[i>>1]+(i&1);
    for(int i=0;i<n;i++) scanf("%lf",&p[i]);
    for(int i=0;i<(1<<n)-1;i++)
        for(int j=0;j<n;j++)
            if(i&(1<<j)) s[i]+=p[j];
    for(int i=0;i<(1<<n)-1;i++)
        s[i]=s[i]/(1-s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)
            if(j&(1<<i)) s[j]-=s[j^(1<<i)];
    for(int i=0;i<n;i++)
    {
        if(p[i]==0) continue;
        for(int j=0;j<(1<<n);j++)
            if((!(j&(1<<i)))&&d[j]<k) ans[i]+=s[j]*p[i];
    }
    for(int i=0;i<n;i++)
        if(p[i]==0) printf("0 ");
        else printf("%.010lf ",ans[i]+p[i]);
    puts("");
    return 0;
}