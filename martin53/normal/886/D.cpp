#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
string inp[nmax];
int seen[26];
bool test(int i)
{
    memset(seen,0,sizeof(seen));
    for(auto k:inp[i])
        seen[k-'a']++;
    for(int i=0;i<26;i++)
        if(seen[i]>1)return 0;
    return 1;
}
set<int> nx[26],pr[26];
//vector<int> adj[nmax];
string out;
bool been[26],there[26];
void dfs(int node)
{
    if(been[node])
    {
        cout<<"NO"<<endl;
        exit(0);
    }
    been[node]=1;
    out=out+char(node+'a');
    if(nx[node].size())
    {
        dfs(*nx[node].begin());
    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n;
for(int i=1;i<=n;i++)cin>>inp[i];
for(int i=1;i<=n;i++)
    if(test(i)==0)
    {
    cout<<"NO"<<endl;
    return 0;
    }
for(int i=1;i<=n;i++)
{
    int SZ=inp[i].size();
    for(int j=1;j<SZ;j++)
    {
        nx[inp[i][j-1]-'a'].insert(inp[i][j]-'a');
        pr[inp[i][j]-'a'].insert(inp[i][j-1]-'a');
    }
    for(auto k:inp[i])
        there[k-'a']=1;
}
for(int i=0;i<26;i++)
    if(nx[i].size()>1||pr[i].size()>1)
    {
    cout<<"NO"<<endl;
    return 0;
    }
/*
for(int i=0;i<26;i++)
{
    cout<<i<<" -> ";for(auto k:nx[i])cout<<k<<" ";cout<<"\t";for(auto k:pr[i])cout<<k<<" ";cout<<endl;
}
*/
for(int i=0;i<26;i++)
{
    int pos=i;
    while(1)
    {
        //cout<<i<<" -> "<<pos<<endl;
        if(been[pos])
        {
            cout<<"NO"<<endl;
            return 0;
        }
        been[pos]=1;
        if(nx[pos].size())pos=*nx[pos].begin();
        else break;
    }
    memset(been,0,sizeof(been));
}
/*
for(int i=0;i<26;i++)
    if(nx[i].size())
    {
        adj[i].push_back(*nx[i].begin());
    }
*/
for(int i=0;i<26;i++)
    if(nx[i].size()&&pr[i].size()==0)
    {
    dfs(i);
    }
    else if(there[i]&&nx[i].size()==0&&pr[i].size()==0)dfs(i);
cout<<out<<endl;
return 0;
}