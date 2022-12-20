#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42;

int n;

pair<int,int/*original id*/> inp[nmax];
int aim[nmax];

void no()
{
    printf("NO\n");
    exit(0);
}

stack<int> active;

vector< pair<int, pair<int,int> > > outp;

int main()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i].first);
        inp[i].second=i;
    }
    for(int i=1;i<=n;i++)scanf("%i",&aim[i]);

    sort(inp+1,inp+n+1);
    sort(aim+1,aim+n+1);

    long long sum=0;

    for(int i=1;i<=n;i++)
    {
        sum+=aim[i]-inp[i].first;
        if(sum<0)no();
    }

    if(sum!=0)no();

    for(int i=1;i<=n;i++)
        if(inp[i].first!=aim[i])
        {
            if(inp[i].first<aim[i])active.push(i);
            else
            {
                while(inp[i].first!=aim[i])
                {
                    int tp=active.top();

                    int d=min(inp[i].first-aim[i],aim[tp]-inp[tp].first);

                    outp.push_back({inp[tp].second,{inp[i].second,d}});

                    inp[tp].first+=d;
                    inp[i].first-=d;

                    if(inp[tp].first==aim[tp])active.pop();
                }
            }
        }

    printf("YES\n");
    printf("%i\n",outp.size());

    for(auto w:outp)
    {
        printf("%i %i %i\n",w.first,w.second.first,w.second.second);
    }

    return 0;
}