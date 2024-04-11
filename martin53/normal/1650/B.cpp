#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int l,r,a;

    scanf("%i%i%i",&l,&r,&a);

    int x=r;

    int x_new=(r+1)/a*a-1;

    if(l<=x_new)x=x_new;

    return x/a+x%a;
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