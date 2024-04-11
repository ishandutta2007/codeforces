#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,q,inp[nmax];

int prv[nmax];

int up[20][nmax];

int seen[nmax];

vector<int> gen(int val)
{
    vector<int> ret={};
    for(int p=2;p*p<=val;p++)
        if(val%p==0)
        {
            ret.push_back(p);
            while(val%p==0)val=val/p;
        }
    if(val!=1)ret.push_back(val);
    return ret;
}

int query()
{
    int l,r;

    scanf("%i%i",&l,&r);

    int ret=0;

    for(int step=19;step>=0;step--)
        if(up[step][r]>=l)r=up[step][r],ret+=(1<<step);

    return ret+1;
}

int main()
{
    scanf("%i%i",&n,&q);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
    {
        vector<int> pr=gen(inp[i]);

        for(auto w:pr)
        {
            prv[i]=max(prv[i],seen[w]);
            seen[w]=i;
        }
    }

    for(int i=1;i<=n;i++)
    {
        up[0][i]=max(up[0][i-1],prv[i]);
    }

    for(int step=1;step<20;step++)
        for(int i=1;i<=n;i++)
            up[step][i]=up[step-1][up[step-1][i]];

    for(int i=1;i<=q;i++)
    {
        printf("%i\n",query());
    }
    return 0;
}