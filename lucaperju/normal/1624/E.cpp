
#include <bits/stdc++.h>

using namespace std;
pair<int,int>m2[10][10];
pair<int,int>m3[10][10][10];
char v[1003];
int dp[1003];
struct ura
{
    int a,b,c;
};
vector<ura>rz;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        for(int a=0;a<=9;++a)
            for(int b=0;b<=9;++b)
                for(int c=0;c<=9;++c)
                    m2[a][b]=m3[a][b][c]=make_pair(0,0);
        int n,i,j,m;
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            cin>>(v+1);
            for(j=1;j<=m;++j)
            {
                v[j]-='0';
            }
            for(j=1;j<m;++j)
            {
                m2[v[j]][v[j+1]]=make_pair(i,j);
                if(j<m-1)
                    m3[v[j]][v[j+1]][v[j+2]]=make_pair(i,j);
            }
        }
        cin>>(v+1);
        for(i=1;i<=m;++i)
            v[i]-='0';
        dp[0]=1;
        for(i=1;i<=m;++i)
            dp[i]=0;
        n=m;
        for(i=2;i<=m;++i)
        {
            if(m2[v[i-1]][v[i]].first!=0)
                dp[i]=max(dp[i],dp[i-2]);
            if(i>=3)
            if(m3[v[i-2]][v[i-1]][v[i]].first!=0)
                dp[i]=max(dp[i],dp[i-3]);
        }
        if(dp[m]==0)
        {
            cout<<-1<<'\n';
            continue;
        }
        rz.clear();
        int pz=m;
        while(pz)
        {
            i=pz;
            if(m2[v[i-1]][v[i]].first!=0)
            {
                if(dp[i-2])
                {
                    ura a;
                    a.c=m2[v[i-1]][v[i]].first;
                    a.a=m2[v[i-1]][v[i]].second;
                    a.b=a.a+1;
                    rz.push_back(a);
                    pz=i-2;
                    continue;
                }
            }
            if(i>=3)
            if(m3[v[i-2]][v[i-1]][v[i]].first!=0)
            {
                if(dp[i-3])
                {
                    ura a;
                    a.c=m3[v[i-2]][v[i-1]][v[i]].first;
                    a.a=m3[v[i-2]][v[i-1]][v[i]].second;
                    a.b=a.a+2;
                    rz.push_back(a);
                    pz=i-3;
                    continue;
                }
            }
        }
        cout<<rz.size()<<'\n';
        for(i=rz.size()-1;i>=0;--i)
        {
            cout<<rz[i].a<<' '<<rz[i].b<<' '<<rz[i].c<<'\n';
        }
        cout<<'\n';
    }

    return 0;
}