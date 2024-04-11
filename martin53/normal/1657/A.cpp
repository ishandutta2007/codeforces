#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int x,y;

    scanf("%i%i",&x,&y);

    int d=x*x+y*y;

    if(d==0)return 0;

    int k=sqrt(d);

    if(k*k==d)return 1;

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