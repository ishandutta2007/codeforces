#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;

    int sum=0;

    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        sum+=cur-1;
    }

    if(sum<0)return 1;
    return sum;
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