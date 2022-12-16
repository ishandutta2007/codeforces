#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int cnt[2]={0,0};

    int n;
    scanf("%i",&n);

    for(int i=1;i<=2*n;i++)
    {
        int val;

        scanf("%i",&val);

        cnt[val%2]++;
    }

    return cnt[0]==cnt[1];
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