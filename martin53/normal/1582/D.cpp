#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];
int outp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int m=n;

    while(m>3||(m%2==0&&m>=2))
    {
        outp[m]=inp[m-1];
        outp[m-1]=-inp[m];

        m=m-2;
    }

    if(m==3)
    {
        if(inp[2]+inp[3]!=0)
        {
            outp[1]=-inp[2]-inp[3];
            outp[2]=inp[1];
            outp[3]=inp[1];
        }
        else if(inp[3]+inp[1]!=0)
        {
            outp[2]=-inp[3]-inp[1];
            outp[3]=inp[2];
            outp[1]=inp[2];
        }
        else
        {
            outp[3]=-inp[1]-inp[2];
            outp[1]=inp[3];
            outp[2]=inp[3];
        }
    }

    for(int i=1;i<=n;i++)printf("%i ",outp[i]);
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