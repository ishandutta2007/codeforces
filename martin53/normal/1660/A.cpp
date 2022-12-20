#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int a,b;
    scanf("%i%i",&a,&b);

    if(a==0)return 1;
    return a+2*b+1;
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