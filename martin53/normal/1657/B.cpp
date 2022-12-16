#include<bits/stdc++.h>
using namespace std;

long long solve()
{
    int n,b,x,y;

    scanf("%i%i%i%i",&n,&b,&x,&y);

    long long sum=0,cur=0;

    for(int i=1;i<=n;i++)
    {
        if(cur+x<=b)cur=cur+x;
        else cur=cur-y;

        sum+=cur;
    }

    return sum;
}

int main()
{
    int t;

    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%lld\n",solve());
    }

    return 0;
}