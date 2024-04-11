#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    scanf("%i",&n);

    if(n==1)
    {
        printf("a\n");
        return;
    }

    int av=n/2;

    if(n%2==0)
    {
        for(int i=1;i<=av;i++)printf("a");

        printf("b");

        for(int i=1;i<av;i++)printf("a");
    }

    if(n%2==1)
    {
        for(int i=1;i<=av;i++)printf("a");

        printf("b");

        printf("c");

        for(int i=1;i<av;i++)printf("a");
    }

    printf("\n");
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