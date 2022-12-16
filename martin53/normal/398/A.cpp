#include<bits/stdc++.h>
using namespace std;
void print(int t,char c)
{
    for(int j=1;j<=t;j++)
        printf("%c",c);
}
int main()
{
int a,b;
scanf("%i%i",&a,&b);
if(a==0)
{
    printf("%lld\n",-1LL*b*b);
    for(int j=1;j<=b;j++)
        printf("x");
    return 0;
}

if(b==0||b==1)
{
    printf("%lld\n",1LL*a*a-1LL*b*b);
    if(b)printf("x");
    for(int j=1;j<=a;j++)
        printf("o");
    return 0;
}

long long ans=1LL*a*a-1LL*b*b;
for(int big=1;big<=a;big++)
{
    int groups=a-big+1+1;
    if(groups>b)continue;
    long long now=1LL*big*big+(a-big);
    now=now-1LL*(b/groups)*(b/groups)*(groups-b%groups);
    now=now-1LL*(b/groups+1)*(b/groups+1)*(b%groups);
    //cout<<big<<" -> "<<now<<endl;
    if(now>ans)
    {
        ans=now;
    }
}


for(int big=1;big<=a;big++)
{
    int groups=a-big+1+1;
    if(groups>b)continue;
    long long now=1LL*big*big+(a-big);
    now=now-1LL*(b/groups)*(b/groups)*(groups-b%groups);
    now=now-1LL*(b/groups+1)*(b/groups+1)*(b%groups);
    if(now==ans)
    {
        printf("%lld\n",ans);
        for(int j=0;j<groups;j++)
        {
            if(j<b%groups)print(b/groups+1,'x');
            else print(b/groups,'x');
            if(j==0)print(big,'o');
            else if(j!=groups-1)print(1,'o');
        }
        return 0;
    }
}

return 0;
}