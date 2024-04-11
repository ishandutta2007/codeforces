#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;

    scanf("%i",&n);

    if(n%7==0)return n;

    for(int d=0;d<10;d++)
    {
        int cur=n/10*10+d;

        if(cur%7==0)return cur;
    }
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