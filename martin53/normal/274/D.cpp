#include<bits/stdc++.h>
using namespace std;
const int mmax=3e5+42;
vector< vector<int> > inp;
int n,m;
vector<int> adj[mmax];
int in[mmax];
pair<int/*value*/,int/*index*/> help[mmax];
queue<int> q;
int main()
{
scanf("%i%i",&n,&m);
vector<int> now={};
for(int i=1;i<=m;i++)now.push_back(0);

for(int i=1;i<=n;i++)
{
    for(int j=0;j<m;j++)scanf("%i",&now[j]);
    inp.push_back(now);
}

int e=m;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
        {
        help[j]=make_pair(inp[i][j],j+1);
        //cout<<j<<" -> "<<inp[i][j]<<" "<<j+1<<endl;
        }
    sort(help,help+m);

    //for(int j=0;j<m;j++)cout<<help[j].first<<" "<<help[j].second<<endl;cout<<"---"<<endl;

    int k=0,l;
    while(k<m&&help[k].first==-1)k++;
    l=k;
    while(l<m&&help[k].first==help[l].first)l++;
    l--;
    while(l<m-1)
    {
        int p=l+1,q=l+1;
        while(q<m&&help[q].first==help[p].first)q++;
        q--;


        e++;
        for(int j=k;j<=l;j++)
            adj[help[j].second].push_back(e),in[e]++;
        for(int j=p;j<=q;j++)
            adj[e].push_back(help[j].second),in[help[j].second]++;
        k=p;
        l=q;
    }

}

vector<int> output={};
for(int i=1;i<=m;i++)
    if(in[i]==0)q.push(i);
while(q.size())
{
    int now=q.front();
    if(now<=m)output.push_back(now);
    q.pop();
    for(auto k:adj[now])
    {
        in[k]--;
        if(in[k]==0)q.push(k);
    }
}

if(output.size()!=m)printf("-1\n");
else
{
    for(auto k:output)
        printf("%i ",k);
    printf("\n");
}
return 0;
}