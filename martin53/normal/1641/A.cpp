#include<bits/stdc++.h>
using namespace std;

int solve()
{
    map<int, vector<int> > seen={};

    int n,x;

    scanf("%i%i",&n,&x);

    for(int i=1;i<=n;i++)
    {
        int cur;

        scanf("%i",&cur);

        int deg=0;

        while(cur%x==0)
        {
            cur=cur/x;
            deg++;
        }

        seen[cur].push_back(deg);
    }

    int outp=0;

    for(auto w:seen)
    {
        vector<int> cur=w.second;

        sort(cur.begin(),cur.end());

        vector<int> active={};

        for(auto w:cur)
        {
            if(active.size()&&active.back()+1==w)active.pop_back();
            else active.push_back(w);
        }

        outp+=active.size();
    }

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}