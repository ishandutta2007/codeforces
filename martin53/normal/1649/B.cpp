#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    scanf("%i",&n);

    long long sum=0;
    int MX=0;

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);
        sum+=cur;

        MX=max(MX,cur);
    }

    if(MX==0)return 0;

    return max(1LL,1+2*MX-1-sum);
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