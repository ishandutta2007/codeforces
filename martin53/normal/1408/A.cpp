#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[3][nmax];

void solve()
{
    scanf("%i",&n);

    for(int id=0;id<3;id++)
        for(int i=1;i<=n;i++)scanf("%i",&inp[id][i]);


    int prv=0;

    int f=0;

    for(int i=1;i<=n;i++)
    {
        int go;

        if(inp[0][i]!=prv&&inp[0][i]!=f)go=inp[0][i];
        else if(inp[1][i]!=prv&&inp[1][i]!=f)go=inp[1][i];
        else go=inp[2][i];


        printf("%i ",go);
        prv=go;

        if(f==0)f=go;
    }
    printf("\n");
}

int main()
{
    int t;

    scanf("%i",&t);

    while(t)
    {
        solve();
        t--;
    }
    return 0;
}