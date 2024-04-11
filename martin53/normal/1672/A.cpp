#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int n;
    scanf("%i",&n);

    int sum=0;

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);
        sum+=cur-1;
    }

    return sum%2;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("errorgorn\n");
        else printf("maomao90\n");
    }

    return 0;
}