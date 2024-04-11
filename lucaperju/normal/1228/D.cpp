#include <bits/stdc++.h>

using namespace std;
vector <int> v[100005];
int viz[100005];
int ok[100005];
int main()
{
    long long i,j,x,y,n,m,cnt=0;
    cin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1; i<=n; ++i)
    {
        if(!viz[i])
        {
            ++cnt;
            if(cnt==4)
            {
                cout<<-1;
                return 0;
            }
            for(j=1; j<=n; ++j)
                ok[j]=0;
            for(j=0; j<v[i].size(); ++j)
            {
                ok[v[i][j]]=1;
            }
            for(j=1; j<=n; ++j)
            {
                if(!ok[j])
                {
                    if(viz[j]!=0)
                    {
                        cout<<-1;
                        return 0;
                    }
                    viz[j]=cnt;
                }
            }
        }
    }
    if(cnt!=3)
    {
        cout<<-1;
        return 0;
    }
    for(i=1;i<=n;++i)
    {
        for(j=0;j<v[i].size();++j)
        {
            if(viz[v[i][j]]==viz[i])
            {
                cout<<-1;
                return 0;
            }
        }
    }
    long long cnt1=0,cnt2=0,cnt3=0;
    for(i=1; i<=n; ++i)
    {
        int tc=i;
        if(viz[tc]==1)
            ++cnt1;
        else if(viz[tc]==2)
            ++cnt2;
        else
            ++cnt3;
    }
    long long cat=(n*1LL*(n-1LL)/2LL)-m;
    if(cat!=cnt1*(cnt1-1LL)/2LL+cnt2*(cnt2-1LL)/2LL+cnt3*(cnt3-1LL)/2LL)
    {
        cout<<-1;
        return 0;
    }
    for(i=1; i<=n; ++i)
    {
        cout<<viz[i]<<' ';
    }
    return 0;
}