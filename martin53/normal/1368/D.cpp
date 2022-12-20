#include<bits/stdc++.h>
using namespace std;

int n,seen[20];

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        int num;
        scanf("%i",&num);

        for(int j=0;j<20;j++)
            if(((1<<j)&num)!=0)seen[j]++;
    }

    long long outp=0;
    for(int i=1;i<=n;i++)
    {
        long long cur=0;

        for(int j=19;j>=0;j--)
            if(seen[j])seen[j]--,cur+=(1<<j);

        outp+=cur*cur;
    }

    printf("%lld\n",outp);
    return 0;
}