#include<bits/stdc++.h>
using namespace std;
int n,m,t,i,j,a,b;
long long c;
string s[1200];
int ans[1000][1000];
int INF = 1e9;
bool total_suc = false;
queue<pair<int,int>> qu;

void bfs()
{
    while(!qu.empty())
    {
        pair<int,int> pa = qu.front();
        qu.pop();
        int ii = pa.first;
        int jj = pa.second;
        if(ii!=0 && ans[ii-1][jj]==INF)
        {
            qu.push({ii-1,jj});
            ans[ii-1][jj] = ans[ii][jj] + 1;
        }
        if(ii!=n-1 && ans[ii+1][jj]==INF)
        {
            qu.push({ii+1,jj});
            ans[ii+1][jj] = ans[ii][jj] + 1;
        }
        if(jj!=0 && ans[ii][jj-1]==INF)
        {
            qu.push({ii,jj-1});
            ans[ii][jj-1] = ans[ii][jj] + 1;
        }
        if(jj!=m-1 && ans[ii][jj+1]==INF)
        {
            qu.push({ii,jj+1});
            ans[ii][jj+1] = ans[ii][jj] + 1;
        }
    }
}

int main()
{
    cin>>n>>m>>t;
    for(i=0;i<n;i++)
        cin>>s[i];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            ans[i][j]=INF;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            bool suc = false;
            if(i!=0 && s[i].at(j)==s[i-1].at(j))
                suc = true;
            if(i!=n-1 && s[i].at(j)==s[i+1].at(j))
                suc = true;
            if(j!=0 && s[i].at(j)==s[i].at(j-1))
                suc = true;
            if(j!=m-1 && s[i].at(j)==s[i].at(j+1))
                suc = true;
            if(suc)
            {
                ans[i][j] = 0;
                total_suc = true;
                qu.push({i,j});
            }
        }
    }
    if(total_suc)
    {
        bfs();
    }
    while(t--)
    {
        cin>>a>>b>>c;
        if(ans[a-1][b-1]==INF || ans[a-1][b-1] >= c)
            cout<<s[a-1].at(b-1)<<"\n";
        else
        {
            long long divi = c - ans[a-1][b-1];
            if(divi%2==0)
            {
                cout<<s[a-1].at(b-1)<<"\n";
            }
            else if (s[a-1].at(b-1)=='0')
                cout<<1<<"\n";
            else
                cout<<0<<"\n";
        }
    }
}