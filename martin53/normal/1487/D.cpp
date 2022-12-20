#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    scanf("%i",&n);

    int k=sqrt(2*n-1);

    while((k+1)*(k+1)<=2*n-1)k++;

    return (k-1)/2;
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