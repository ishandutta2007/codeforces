#include<bits/stdc++.h>
using namespace std;
const int kmax=52,SZ=kmax*2+5;
vector<int> adj[SZ];
int cost[SZ][SZ];
int flow[SZ][SZ];
int output[SZ];
int ask(char x)
{
    if('a'<=x&&x<='z')return x-'a'+1;
    return x-'A'+1+26;
}
int parent[SZ],dist[SZ];
void run()
{
    for(int j=0;j<SZ;j++)
        dist[j]=1e9,parent[j]=1e9;
    dist[0]=0;
    int d;
    /*
    for(int j=0;j<105;j++)
        for(auto k:adj[j])
            cout<<j<<" "<<k<<" "<<flow[j][k]<<" "<<cost[j][k]<<endl;
    */
    for(int i=0;i<105;i++)
        for(int j=0;j<105;j++)
            for(auto k:adj[j])
            if(flow[j][k])
            {
                d=dist[j]+cost[j][k];
                if(d<dist[k])
                {
                    dist[k]=d;
                    parent[k]=j;
                }
            }
    /*
    for(int i=0;i<105;i++)
        if(dist[i]&&dist[i]!=1e9)cout<<i<<" -> "<<dist[i]<<endl;
    */
}
char inv(int i)
{
    i=i-52;
    if(i<=26)return i-1+'a';
    i=i-26;
    return i-1+'A';
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
int n,k;
string p,q;
cin>>n>>k;
cin>>p>>q;
for(int i=0;i<n;i++)
    cost[ask(p[i])][ask(q[i])+52]--,cost[ask(q[i])+52][ask(p[i])]++;
for(int i=1;i<=k;i++)
{
    adj[0].push_back(i);
    flow[0][i]=1;
}
for(int i=1;i<=k;i++)
    for(int j=1;j<=k;j++)
    {
    adj[i].push_back(j+52);
    flow[i][j+52]=1;
    adj[j+52].push_back(i);
    }
for(int j=1;j<=k;j++)
{
    adj[j+52].push_back(105);
    flow[j+52][105]=1;
}

int ans=0;
while(1)
{
    run();
    if(dist[105]>0)break;
    int node=105;
    int t=0;
    //cout<<"path: ";
    while(node)
    {
        //cout<<node<<" ";
        ans=ans+cost[parent[node]][node];
        flow[parent[node]][node]--;
        flow[node][parent[node]]++;
        if(t%2==1){output[parent[node]]=node;/*cout<<"node= "<<node<<" "<<parent[node]<<endl;*/}
        node=parent[node];
        t++;
    }
    //cout<<endl;
}
cout<<-ans<<endl;
for(int i=1;i<=k;i++)
    cout<<inv(output[i]);cout<<endl;
return 0;
}