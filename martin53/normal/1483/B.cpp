#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,inp[nmax];

set<int> active={};

set<int> to_pop={};

void check(int pos)
{
    //cout<<"checking "<<pos<<endl;

    to_pop.erase(pos);

    set<int>::iterator it=active.lower_bound(pos);

    if(it==active.begin())
    {
        it=active.end();
        it--;
    }
    else it--;

    if(__gcd(inp[*it],inp[pos])==1)to_pop.insert(pos);
}
void solve()
{
    active={};
    to_pop={};

    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        active.insert(i);
    }

    for(int i=1;i<=n;i++)
        check(i);

    vector<int> outp={};

    int last=0;

    while(to_pop.size())
    {
        set<int>::iterator help=active.lower_bound(last);
        if(help==active.end())help=active.begin();

        help++;
        if(help==active.end())help=active.begin();

        //cout<<"help= "<<*help<<endl;

        set<int>::iterator cur=to_pop.lower_bound(*help);

        if(cur==to_pop.end())cur=to_pop.begin();

        int pos=*cur;

        //cout<<"pos= "<<pos<<endl;

        outp.push_back(pos);

        to_pop.erase(pos);

        active.erase(pos);

        last=pos;

        if(active.size())
        {
            set<int>::iterator it=active.lower_bound(pos);

            if(it==active.end())it=active.begin();

            check(*it);
        }
    }

    //cout<<"---"<<endl;
    printf("%i ",outp.size());for(auto w:outp)printf("%i ",w);
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