#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,mod=1e9+7;

map<int,int> seen[nmax];

int n,q,inp[nmax];

int dvd[nmax];

long long outp=1;

void upd(int pos,int val)
{
    seen[val][pos]++;

    if(seen[val].size()==n)
    {
        outp=outp*val%mod;

        map<int,int> help={};

        for(auto w:seen[val])
            if(w.second>1)help[w.first]=w.second-1;

        seen[val]=help;
    }
}

void update(int pos,int val)
{
    while(val>1)
    {
        upd(pos,dvd[val]);
        val=val/dvd[val];
    }
}

int main()
{
    scanf("%i%i",&n,&q);

    for(int i=2;i<nmax;i++)
        if(dvd[i]==0)
        {
            dvd[i]=i;
            for(int j=i;j<nmax;j=j+i)
                if(dvd[j]==0)dvd[j]=i;
        }

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        update(i,inp[i]);
    }

    for(int i=1;i<=q;i++)
    {
        int pos,val;
        scanf("%i%i",&pos,&val);

        update(pos,val);

        printf("%lld\n",outp);
    }

    return 0;
}