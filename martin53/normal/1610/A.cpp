#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n,m;
    scanf("%i%i",&n,&m);

    if(n==1&&m==1)return 0;

    if(n==1||m==1)return 1;

    return 2;
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