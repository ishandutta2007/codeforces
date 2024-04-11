#include <bits/stdc++.h>

using namespace std;
vector<int>v[5003];
int col[5003],viz[5003],rz[5003];
short dp[5003][5003];
vector<int>v1,v2,v3;
int cnt1,cnt2;
void dfs (int pz)
{
    viz[pz]=1;
    if(col[pz]==1)
        ++cnt1;
    else
        ++cnt2;
    for(int i=0;i<v[pz].size();++i)
    {
        if(!viz[v[pz][i]])
        {
            col[v[pz][i]]=3-col[pz];
            dfs(v[pz][i]);
        }
        else if(viz[v[pz][i]])
        {
            if(col[v[pz][i]]==col[pz])
            {
                cout<<"NO\n";
                exit(0);
            }
        }
    }
}
void solve(int pz)
{
    col[pz]=1;
    cnt1=cnt2=0;
    dfs(pz);
    v1.push_back(cnt1);
    v2.push_back(cnt2);
    v3.push_back(pz);
}
void dfs1(int pz)
{
    viz[pz]=2;
    col[pz]=3-col[pz];
    for(int i=0;i<v[pz].size();++i)
        if(viz[v[pz][i]]!=2)
            dfs1(v[pz][i]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n,i,m,t,j,k,mx,p,mxx=0,s,q;
    cin>>n>>m;
    int nr1,nr2,nr3;
    cin>>nr1>>nr2>>nr3;
    k=0;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1;i<=n;++i)
        if(!viz[i])
        {
            solve(i);
            ++k;
        }
    dp[0][0]=1;
    for(i=0;i<k;++i)
    {
        int a=v1[i];
        int b=v2[i];
        for(j=nr2;j>=0;--j)
        {
            if(dp[i][j])
            {
                if(j+a<=nr2)
                    dp[i+1][j+a]=1;
                if(j+b<=nr2)
                    dp[i+1][j+b]=1;
            }
        }
    }
    if(dp[k][nr2]==0)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    int sc=nr2;
    for(i=k;i>0;--i)
    {
        int a=v1[i-1];
        int b=v2[i-1];
        if(sc>=a && dp[i-1][sc-a])
        {
            dfs1(v3[i-1]);
            sc-=a;
        }
        else
            sc-=b;
    }
    for(i=1;i<=n;++i)
    {
        if(col[i]==1)
        {
            if(nr1)
            {
                cout<<1;
                --nr1;
            }
            else
                cout<<3;

        }
        else
            cout<<2;
    }
    return 0;
}