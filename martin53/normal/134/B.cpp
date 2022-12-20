#include<bits/stdc++.h>
using namespace std;
int f(int a,int b)
{
    if(a<b)return f(b,a);
    if(b==1)return a-1;
    return f(a%b,b)+(a/b);
}
int main()
{
int n;
scanf("%i",&n);
int ans=n-1;
for(int i=1;i<=n;i++)
    if(__gcd(i,n)==1)ans=min(ans,f(n,i));
printf("%i\n",ans);
return 0;
}