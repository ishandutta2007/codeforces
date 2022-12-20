#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,k,inp[nmax];

map< vector< pair<int,int> >,int> seen;
int main()
{
    long long output=0;
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        vector< pair<int,int> > now={};
        for(int j=2;j*j<=inp[i];j++)
            if(inp[i]%j==0)
            {
                int t=0;
                while(inp[i]%j==0)inp[i]=inp[i]/j,t++;
                t=t%k;

                if(t)now.push_back({j,t});
            }

        if(inp[i]!=1)
        {
            now.push_back({inp[i],1});
        }
        vector< pair<int,int> > rev={};
        for(auto p:now)
            rev.push_back({p.first,k-p.second});
        output=output+seen[rev];
        seen[now]++;
    }
    printf("%lld\n",output);
    return 0;
}