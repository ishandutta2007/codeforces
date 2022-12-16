#include<bits/stdc++.h>
using namespace std;

int ask(int pw,int n)
{
    return pow(n+0.5,1.0/pw);
}

int solve()
{
    int n;
    scanf("%i",&n);

    return ask(2,n)+ask(3,n)-ask(6,n);
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