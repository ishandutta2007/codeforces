#include<bits/stdc++.h>
using namespace std;

const int nmax=(1<<18)+42;

int n,inp[nmax];

int parent[nmax];

vector<int> seen[nmax];

int where[nmax],coeff[nmax];

long long outp;

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    /*
    n=2e5;
    for(int i=1;i<=n;i++)inp[i]=i;
    */

    n++;
    inp[n]=0;

    for(int i=1;i<=n;i++)parent[i]=i;

    sort(inp+1,inp+n+1);

    for(int i=1;i<=n;i++)
    {
        where[inp[i]]=i;
        coeff[inp[i]]++;
    }

    for(int i=0;i<=n;i++)
        seen[i].push_back(i);

    outp=0;
    for(int i=1;i<=n;i++)outp=outp-inp[i];

    for(int sum=(1<<18)-1;sum>=0;sum--)
    {
        for(int i=sum;i;i=(i-1)&sum)
        {
            int j=sum-i;

            if(where[i]==0||where[j]==0)continue;

            if(parent[where[i]]==parent[where[j]])continue;

            outp+=(1LL)*(i+j)*(coeff[i]+coeff[j]-1);

            //cout<<i<<" "<<j<<" -> "<<coeff[i]<<" "<<coeff[j]<<" "<<(i+j)*(coeff[i]+coeff[j]-1)<<endl;

            coeff[i]=1;
            coeff[j]=1;

            //parent[root(where[i])]=root(where[j]);
            int u=parent[where[i]],v=parent[where[j]];

            if(seen[u].size()<seen[v].size())swap(u,v);

            for(auto w:seen[v])
            {
                parent[w]=u;
                seen[u].push_back(w);
            }
        }

    }
    printf("%lld\n",outp);

    return 0;
}