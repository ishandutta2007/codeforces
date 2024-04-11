#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int cur;
    scanf("%i",&cur);

    if(1900<=cur)return 1;
    if(1600<=cur)return 2;
    if(1400<=cur)return 3;
    return 4;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("Division %i\n",solve());
    }

    return 0;
}