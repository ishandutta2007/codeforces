#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    scanf("%i",&n);

    if(n<=3)return n-1;
    return n%2+2;
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