#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);
    inp[0]=0;
    inp[n+1]=0;

    int outp=0;
    for(int i=1;i<=n;i++)
        if(inp[i]!=inp[i-1])
        {
            int cnt=0;

            int j=i;

            while(j<=n&&inp[j]==inp[i])
            {
                j++;
                cnt++;
            }

            //cout<<"i= "<<i<<" j= "<<j<<" cnt= "<<cnt<<endl;

            while(j<=n)
            {
                cnt++;

                j=lower_bound(inp+1,inp+n+1,2*inp[j]-inp[i])-inp;
            }

            outp=max(outp,cnt);
        }
    return n-outp;
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