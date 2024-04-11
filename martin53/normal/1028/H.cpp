#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,MX=6e6+42;

int n,q,inp[nmax];

vector<int> primes[nmax];

vector< pair<int/*left*/,int/*id*/> > queries[nmax];

int dp[MX][15];

int last[15];

int outp[MX];

int main()
{
    scanf("%i%i",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        for(int j=2;j*j<=inp[i];j++)
            if(inp[i]%j==0)
            {
                int t=0;

                while(inp[i]%j==0)t++,inp[i]=inp[i]/j;

                if(t%2)primes[i].push_back(j);
            }

        if(inp[i]!=1)primes[i].push_back(inp[i]);

        //cout<<i<<" -> ";for(auto k:primes[i])cout<<k<<" ";cout<<endl;
    }

    for(int i=1;i<=q;i++)
    {
        int l,r;
        scanf("%i%i",&l,&r);
        queries[r].push_back({l,i});
    }

    for(int i=1;i<=n;i++)
    {
        int SZ=primes[i].size();

        for(int mask=0;mask<(1<<SZ);mask++)
        {
            int mult=1,other=0;

            for(int j=0;j<SZ;j++)
                if((mask&(1<<j)))
                    mult=mult*primes[i][j];
                else other++;

            for(int wrong=0;wrong<8;wrong++)
            {
                int cur_wrong=other+wrong;

                last[cur_wrong]=max(last[cur_wrong],dp[mult][wrong]);
            }

            dp[mult][other]=i;
        }

        //cout<<i<<" -> ";for(int j=0;j<8;j++)cout<<last[j]<<" ";cout<<endl;

        for(auto w:queries[i])
            for(int j=0;j<15;j++)
                if(last[j]>=w.first)
                {
                    outp[w.second]=j;

                    break;
                }
    }

    for(int i=1;i<=q;i++)
        printf("%i\n",outp[i]);
    return 0;
}