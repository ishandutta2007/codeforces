#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int adj[nmax][nmax];
int outp;
int n,k;

void solve(vector<int> cur,int colour)
{
    if(cur.size()<=1)return;

    //cout<<"solve ";for(auto w:cur)cout<<" "<<w;cout<<" colour= "<<colour<<endl;

    outp=max(outp,colour);

    vector< vector<int> > groups={};
    for(int i=1;i<=k;i++)groups.push_back({});

    for(int i=0;i<cur.size();i++)
        groups[i%k].push_back(cur[i]);

    int pointer=0;
    for(int i=0;i<k;i++)
    {
        for(auto &j:groups[i])
        {
            j=cur[pointer++];
            //cout<<"j= "<<j<<" pointer= "<<pointer<<endl;
        }
    }

    for(int i=0;i<k;i++)
        for(int j=i+1;j<k;j++)
            for(auto u:groups[i])
                for(auto v:groups[j])
                {
                    adj[u][v]=colour;
                    //cout<<u<<" "<<v<<" -> "<<colour<<endl;
                }
    for(int i=0;i<k;i++)
        solve(groups[i],colour+1);
}

int main()
{
    scanf("%i%i",&n,&k);

    vector<int> cur={};
    for(int i=1;i<=n;i++)cur.push_back(i);

    solve(cur,1);

    printf("%i\n",outp);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            printf("%i ",adj[i][j]);
    printf("\n");

    return 0;
}