#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int w,h,n;

    scanf("%i%i%i",&w,&h,&n);

    int s=w*h;

    int ret=1;

    while(s%2==0)
    {
        s=s/2;
        ret=ret*2;
    }

    return ret>=n;
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