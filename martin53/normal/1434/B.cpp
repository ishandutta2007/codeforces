#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

char type[nmax];

int where[nmax];

void wrong()
{
    cout<<"NO"<<endl;
    exit(0);
}

int sell[nmax];

set<int> active;

void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin>>n;
    for(int i=1;i<=2*n;i++)
    {
        cin>>type[i];

        if(type[i]=='-')
        {
            cin>>inp[i];

            where[inp[i]]=i;
        }
        else active.insert(i);
    }

    for(int i=1;i<=n;i++)
    {
        set<int>::iterator it=active.lower_bound(where[i]);

        if(it==active.begin())wrong();

        it--;

        sell[*it]=i;

        //cout<<*it<<" -> "<<i<<endl;

        active.erase(it);
    }

    for(int i=1;i<=2*n;i++)
        if(type[i]=='+')
        {
            active.insert(sell[i]);
        }
        else
        {
            if(active.size()==0)wrong();

            if((*active.begin())!=inp[i])wrong();
            active.erase(inp[i]);
        }

    cout<<"YES\n";
    for(int i=1;i<=2*n;i++)
        if(sell[i])cout<<sell[i]<<"\n";
}

int main()
{
    int t;
    t=1;

    while(t)
    {
        t--;
        solve();
    }
    return 0;
}