#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,q;

int inp[nmax];
int mini[nmax];

set<int> active;

void solve()
{
    active={};

    scanf("%i%i",&n,&q);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    mini[1]=inp[1];
    active.insert(1);

    for(int i=2;i<=n;i++)
    {
        mini[i]=min(mini[i-1],inp[i]);

        if(mini[i-1]>mini[i])active.insert(i);
    }

    for(int i=1;i<=q;i++)
    {
        int pos,val;

        scanf("%i%i",&pos,&val);

        inp[pos]=inp[pos]-val;

        set<int>::iterator it=active.lower_bound(pos);

        bool go=0;

        if(it==active.begin())go=1;
        else
        {
            it--;

            if(inp[(*it)]>inp[pos])go=1;
        }

        if(go)
        {
            active.insert(pos);

            while(1)
            {
                set<int>::iterator it=active.upper_bound(pos);

                if(it==active.end())break;
                else if(inp[pos]<=inp[(*it)])active.erase(it);
                else break;
            }
        }

        printf("%i ",active.size());
    }

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