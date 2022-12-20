#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int l1,r1,l2,r2;
    scanf("%i%i%i%i",&l1,&r1,&l2,&r2);

    if(max(l1,l2)<=min(r1,r2))return max(l1,l2);

    return l1+l2;
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