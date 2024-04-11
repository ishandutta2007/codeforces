#include<bits/stdc++.h>
using namespace std;

map<int,int> seen;

map<int, vector<int> > cnt;

bool cmp(int a,int b)
{
    return a>b;
}

set< pair<int,int> > blocked;

long long solve()
{
    int n,m;
    scanf("%i%i",&n,&m);

    seen={};

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);
        seen[cur]++;
    }

    cnt={};

    for(auto w:seen)
        cnt[w.second].push_back(w.first);

    for(auto &w:cnt)
        sort(w.second.begin(),w.second.end(),cmp);

    blocked={};

    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%i%i",&x,&y);

        blocked.insert({x,y});
    }

    long long outp=0;

    for(auto p:cnt)
        for(auto q:cnt)
            if(p.first<=q.first)
            {
                for(auto u:p.second)
                    for(auto v:q.second)
                    {
                        if(1LL*(p.first+q.first)*(u+v)<=outp)break;
                        else if(u!=v)
                        {
                            if(blocked.count({u,v})==0&&blocked.count({v,u})==0)
                            {
                                //cout<<u<<" "<<v<<" ok "<<endl;

                                outp=1LL*(p.first+q.first)*(u+v);
                                break;
                            }
                        }
                    }
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

        printf("%lld\n",solve());
    }

    return 0;
}