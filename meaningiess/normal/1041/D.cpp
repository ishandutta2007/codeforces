#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,i,g[400100],s[400100],ans,t,res;
int main()
{
    cin>>n>>m;s[0]=s[1]=0;
    for (i=1;i<=2*n;i++) cin>>g[i];
    for (i=3;i<=2*n;i+=2) s[i]=s[i+1]=(g[i]-g[i-1])+s[i-1];
    for (i=1;i<=2*n;i+=2)
    {
    	t=upper_bound(s+1,s+2*n+1,s[i]+m)-s;
    	if (s[t-1]-s[i]==m) res=g[t-2]-g[i];
    	else res=m-s[t-1]+s[i]+g[t-1]-g[i];
    	ans=max(ans,res);
    }
    printf("%d",ans);
}