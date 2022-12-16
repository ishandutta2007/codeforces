#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;

    int sum=0;

    int cnt[2]={0,0};

    scanf("%i",&n);

    while(n)
    {
        n--;

        int cur;

        scanf("%i",&cur);

        sum+=cur;

        cnt[cur-1]++;
    }

    if(sum%2)return 0;

    sum=sum/2;

    if(sum%2&&cnt[0]==0)return 0;

    return 1;
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