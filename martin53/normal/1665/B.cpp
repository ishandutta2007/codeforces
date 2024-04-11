#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    scanf("%i",&n);

    int MX=0;

    map<int,int> seen={};

    for(int j=1;j<=n;j++)
    {
        int cur;
        scanf("%i",&cur);
        seen[cur]++;
        MX=max(MX,seen[cur]);
    }

    int outp=0;
    while(MX<n)
    {
        if(MX+MX<n)
        {
            outp+=1+MX;
            MX=MX*2;
        }
        else
        {
            outp+=1+n-MX;
            MX=n;
        }
    }

    return outp;
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