#include<bits/stdc++.h>
using namespace std;

int inp[4];

bool solve()
{
    for(int i=1;i<=3;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=3;i++)
        for(int j=i+1;j<=3;j++)
        {
            int k=1+2+3-i-j;

            if(inp[i]+inp[j]==inp[k])return 1;
            if(inp[i]==inp[j]&&inp[k]%2==0)return 1;
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