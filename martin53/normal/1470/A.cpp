#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,m,inp[nmax];

int cost[nmax];

int seen[nmax];

void solve()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=m;i++)seen[i]=0;

    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%i",&x);
        seen[x]++;
    }

    for(int i=1;i<=m;i++)scanf("%i",&cost[i]);

    long long outp=0;

    set< pair<int,int> > active={};

    int pointer=0;

    for(int i=m;i>=1;i--)
    {
        while(seen[i])
        {
            outp+=cost[i];
            seen[i]--;

            active.insert({cost[i],pointer++});
        }

        if(active.size())
        {
            set< pair<int,int> >::iterator it=active.end();
            it--;

            //cout<<"i= "<<(*it).first<<" "<<cost[i]<<endl;

            if((*it).first>cost[i])
            {
                outp=outp-(*it).first+cost[i];

                active.erase(it);

                active.insert({cost[i],pointer++});
            }
        }

        //cout<<"i= "<<i<<" outp= "<<outp<<" "<<active.size()<<endl;
    }


    printf("%lld\n",outp);
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