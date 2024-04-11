#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[1000];
bool visit[1000][1000];
bool row[1000], col[1000], rowfi, colfi;

void dfs(int x,int y)
{
    if(!visit[x][y] && s[x].at(y) == '#')
    {
        visit[x][y] = true;
        if(x!=n-1)
            dfs(x+1,y);
        if(x!=0)
            dfs(x-1,y);
        if(y!=m-1)
            dfs(x,y+1);
        if(y!=0)
            dfs(x,y-1);
    }
}

int main()
{
    cin>>n>>m;
    int i,j;
    for(i=0;i<n;i++)
        cin>>s[i];
    bool suc = true;
    for(i=0;i<n;i++)
    {
        bool first = true;
        for(j=0;j<m;j++)
        {
            if(s[i].at(j) == '#')
            {
                if(first)
                    first = false;
                else if(s[i].at(j-1)!= '#')
                    suc = false;
            }
        }
    }
    for(i=0;i<m;i++)
    {
        bool first = true;
        for(j=0;j<n;j++)
        {
            if(s[j].at(i) == '#')
            {
                if(first)
                    first = false;
                else if(s[j-1].at(i)!= '#')
                    suc = false;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(s[i].at(j) == '#')
            {
                row[i] = true;
                break;
            }
        }
        if(row[i]==false)
            rowfi = true;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(s[j].at(i) == '#')
            {
                col[i] = true;
                break;
            }
        }
        if(col[i] == false)
            colfi = true;
    }
    if(colfi || rowfi)
    {
        if(!(colfi && rowfi))
        {
            suc = false;
        }
    }
    if(!suc)
    {
        cout<<"-1";
    }
    else
    {
        for(i=0;i<n;i++)
        {
            for(j<0;j<m;j++)
            {
                visit[i][j] = false;
            }
        }
        int ranking = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(!visit[i][j] && s[i].at(j)=='#')
                {
                    ranking++;
                    dfs(i,j);
                }
            }
        }
        cout<<ranking;
    }
    return 0;
}