#include<bits/stdc++.h>
using namespace std;

int inp[10];

void solve()
{
    for(int i=1;i<=7;i++)scanf("%i",&inp[i]);

    printf("%i %i %i\n",inp[1],inp[2],inp[7]-inp[1]-inp[2]);
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}