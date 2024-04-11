#include<bits/stdc++.h>
using namespace std;
int test,a,n,p,h;
bool ans;
bool solve(int a,int p,int n)
{
if (1ll*a*n<p)
{
if (max(a,p-a*n)>h) return 0;
return 1;
}
int cr=1ll*a*n/p,ps=1ll*a*n%p;
if (ps<((p/a)-1)*a) cr--;
return solve(p%a,a,cr);
}
int main()
{
scanf("%d",&test);
while(test--)
{
scanf("%d%d%d%d",&a,&n,&p,&h);a%=p;
if (1ll*a*n<p)
{
if (a<=h) printf("YES\n");
else printf("NO\n");
continue;
}
ans=solve(a,p,n);
if (!ans) printf("NO\n");
else printf("YES\n");
}
return 0;
}
//aa