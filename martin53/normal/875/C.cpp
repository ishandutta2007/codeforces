#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m;
vector<int> numbers[nmax],adj[nmax];
int SZ[nmax];
bool must[nmax],must_not[nmax];
bool been[nmax];
void dfs(int node)
{
    if(been[node])return;
    been[node]=1;
    must[node]=1;
    for(auto k:adj[node])
        dfs(k);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();

cin>>n>>m;
int x;
for(int i=1;i<=n;i++)
{
    cin>>SZ[i];
    for(int j=0;j<SZ[i];j++)
    {
    cin>>x;
    numbers[i].push_back(x);
    }
}

for(int i=1;i<n;i++)
{
    bool bad=1;
    for(int j=0;j<SZ[i]&&j<SZ[i+1];j++)
    if(numbers[i][j]!=numbers[i+1][j])
    {
        bad=0;
        if(numbers[i][j]>numbers[i+1][j])
        {
            must[numbers[i][j]]=1;
            must_not[numbers[i+1][j]]=1;
        }
        else
        {
        adj[numbers[i+1][j]].push_back(numbers[i][j]);
        }
        break;
    }
    if(bad)
    {
        if(numbers[i].size()>numbers[i+1].size())
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
}

for(int i=1;i<=m;i++)
    if(must[i])dfs(i);

for(int i=1;i<=m;i++)
    if(must[i]&&must_not[i])
    {
        cout<<"No"<<endl;
        return 0;
    }

int ans=0;
for(int i=1;i<=m;i++)
    if(must[i])ans++;
cout<<"Yes"<<endl;
cout<<ans<<endl;
for(int i=1;i<=m;i++)
    if(must[i])cout<<i<<" ";
cout<<endl;
//system("pause");
return 0;
}