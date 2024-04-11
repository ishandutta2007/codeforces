#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int sum=0;

    for(int i=1;i<=4;i++)
    {
        int cur;
        scanf("%i",&cur);

        sum+=cur;
    }

    if(sum==0)return 0;

    if(sum==4)return 2;

    return 1;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}