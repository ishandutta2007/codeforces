#include<bits/stdc++.h>
using namespace std;

map<int,int> seen;

void solve()
{
    seen={};

    int n,k;

    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        seen[cur]++;
    }

    int l=1,r=0;

    int started=-1,prv=-1;

    for(auto w:seen)
        if(w.second>=k)
        {
            if(w.first==prv+1)
            {
                prv=w.first;
            }
            else
            {
                prv=w.first;
                started=w.first;
            }

            if(r-l<prv-started)
            {
                r=prv;
                l=started;
            }
        }
        else prv=-1,started=-1;

    if(r-l<0)printf("-1\n");
    else printf("%i %i\n",l,r);
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