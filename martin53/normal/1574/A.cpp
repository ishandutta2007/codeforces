#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)printf("(");
        for(int j=1;j<=i;j++)printf(")");

        for(int j=2*i+1;j<=2*n;j++)
            if(j%2==1)printf("(");
            else printf(")");

        printf("\n");
    }
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