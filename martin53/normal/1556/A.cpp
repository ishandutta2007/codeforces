#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int c,d;

    scanf("%i%i",&c,&d);

    if((c+d)%2)return -1;

    if(c==0&&d==0)return 0;

    if(c==d)return 1;

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