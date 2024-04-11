#include<bits/stdc++.h>
using namespace std;
int arr[3];
int now[3];
int main()
{
int k;
scanf("%i%i%i%i",&arr[0],&arr[1],&arr[2],&k);
now[0]=1;
now[1]=1;
now[2]=1;
for(int i=1;i<=1e6;i++)
{
    if(k&&now[0]<arr[0])k--,now[0]++;
    if(k&&now[1]<arr[1])k--,now[1]++;
    if(k&&now[2]<arr[2])k--,now[2]++;
}
long long ans=1LL*now[0]*now[1]*now[2];
printf("%lld\n",ans);
return 0;
}