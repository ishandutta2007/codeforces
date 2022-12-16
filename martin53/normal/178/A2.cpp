#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,inp[nmax];
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
    scanf("%i",&inp[i]);
long long ans=0;
for(int i=1;i<n;i++)
{
    ans=ans+inp[i];
    int t=20;
    while(i+(1<<t)>n)t--;
    inp[i+(1<<t)]+=inp[i];
    inp[i]=0;
    printf("%lld ",ans);
}
printf("\n");
return 0;
}