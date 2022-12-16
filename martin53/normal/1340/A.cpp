#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];

int where[nmax];

set< pair<int/*position*/,int/*size*/> > active;

set< pair<int/*size*/,int/*position*/> > sorted_active;

bool query()
{
    active={};
    sorted_active={};

    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        where[inp[i]]=i;

        active.insert({i,1});
        sorted_active.insert({1,i});
    }

    for(int i=1;i<=n;i++)
    {
        set< pair<int/*size*/,int/*position*/> >::iterator it=sorted_active.end();
        it--;

        int mx=(*it).first;

        //cout<<i<<" -> "<<mx<<endl;

        if(active.count({where[i],mx})==0)return 0;

        sorted_active.erase({mx,where[i]});
        active.erase({where[i],mx});

        set< pair<int/*position*/,int/*size*/> >::iterator it_other=active.lower_bound({where[i],mx});

        if(it_other==active.end())continue;

        pair<int/*position*/,int/*size*/> cur=*it_other;

        active.erase(cur);
        sorted_active.erase({cur.second,cur.first});

        active.insert({cur.first,cur.second+mx});
        sorted_active.insert({cur.second+mx,cur.first});
    }
    return 1;
}
int main()
{
    int t;
    scanf("%i",&t);

    for(int i=1;i<=t;i++)
        if(query())printf("Yes\n");
        else printf("No\n");

    return 0;
}