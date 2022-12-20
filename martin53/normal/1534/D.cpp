#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42;

int n;

int dist[nmax][nmax];

vector<int> seen[2];

void ask(int node)
{
    cout<<"? "<<node<<endl;

    for(int i=1;i<=n;i++)cin>>dist[node][i];

    if(node==1)
    {
        for(int i=2;i<=n;i++)
            seen[dist[node][i]%2].push_back(i);
    }
}

vector< pair<int,int> > outp;

bool edge[nmax][nmax];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin>>n;

    ask(1);

    int id=0;
    if(seen[0].size()>seen[1].size())id=1;

    for(auto w:seen[id])
        ask(w);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(dist[i][j]==1||dist[j][i]==1)edge[i][j]=1;

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(edge[i][j])outp.push_back({i,j});

    cout<<"!"<<endl;
    for(auto w:outp)
        cout<<w.first<<" "<<w.second<<endl;

    return 0;
}