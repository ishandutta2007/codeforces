#include <cstdlib>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool flag = 0;

vector <int> m[100001];
int n;
bool v[100001]={0};
int color[100001]={0};

void dfs(int a)
{
    v[a]=true;
    for(int i = 0; i < m[a].size();i++)
    {
        if (color[m[a][i]]==0)
            color[m[a][i]]= (color[a]==1?2:1);
        else if (color[m[a][i]] == color[a]) 
        {
            cout<<-1;
            exit(0);
        }
    }
    
    for(int i = 0; i < m[a].size();i++)
    {
        if(v[m[a][i]] == 0) dfs(m[a][i]);     
    }
}

int main() 
{
    int M;
    cin>>n>>M;
    for(int i = 0; i < M;i++)
    {
        int a, b;
        cin>>a>>b;
        a--;b--;
        m[b].push_back(a);
        m[a].push_back(b);
    }
    for(int i =0;i<n;i++)
        if(v[i]==0)
        {
            color[i]=1;
            dfs(i);
        }
    int c1=0,c2=0;
    for (int i =0;i<n;i++)
        if (color[i]==1) c1++;
        else c2++;
    cout<<c1<<endl;
    for(int i =0;i<n;i++)
        if (color[i]==1) cout<<i+1<<' ';
    cout<<endl;
    cout<<c2<<endl;
    for(int i =0;i<n;i++)
        if (color[i]==2) cout<<i+1<<' ';
    
    return 0;
}