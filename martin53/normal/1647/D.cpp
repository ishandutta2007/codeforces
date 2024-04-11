#include<bits/stdc++.h>
using namespace std;

bool comp(int num)
{
    for(int i=2;i*i<=num;i++)
        if(num%i==0)return 1;

    return 0;
}

bool solve()
{
    int x,d;

    scanf("%i%i",&x,&d);

    if(1LL*d*d>=x)return 0;

    int cnt=0;

    int b=x;

    while(b%d==0)b=b/d,cnt++;

    if(cnt==1)return 0;

    if(comp(b))return 1;

    if(b==1)
    {
        if(comp(d))return 1;
        return 0;
    }

    //b is prime
    if(comp(d))
    {
        /*
        if(1LL*b*b==d&&cnt<=3)return 0;
        return 1;
        */

        if(cnt>=4)return 1;
        if(cnt>=3&&1LL*b*b!=d)return 1;

        return 0;
    }

    return 0;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}