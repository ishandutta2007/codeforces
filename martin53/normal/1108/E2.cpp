#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,arr[nmax];
int m;
pair<int/*left*/,int/*right*/> inp[nmax];
int g[nmax];
int group[nmax];
int mini[nmax];
int add[nmax];
int help[nmax];
int main()
{
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>arr[i];
for(int i=1;i<=m;i++)
{
    cin>>inp[i].first>>inp[i].second;
    g[inp[i].first]=2*i;
    g[inp[i].second]=2*i+1;
}
g[0]=-1;
for(int i=1;i<=n;i++)
    if(g[i-1]==g[i])group[i]=group[i-1];
    else group[i]=group[i-1]+1;
for(int i=1;i<=n;i++)mini[i]=1e9+42;
for(int i=1;i<=n;i++)
    mini[group[i]]=min(mini[group[i]],arr[i]);
group[n+1]=group[n]+1;
int diff=0,id=1;
//cout<<"group: ";for(int i=1;i<=n;i++)cout<<group[i]<<" ";cout<<endl;
for(int i=1;i<=n;i++)
{
    for(int j=0;j<=group[n];j++)
        add[j]=0;
    for(int j=1;j<=m;j++)
        if(inp[j].first<=i&&i<=inp[j].second)continue;
        else add[group[inp[j].first]]--,add[group[inp[j].second+1]]++;

    //for(int j=1;j<=group[n];j++)cout<<add[j]<<" ";cout<<endl;

    for(int j=1;j<=group[n];j++)
        {
        add[j]+=add[j-1];
        //cout<<j<<" -> "<<add[j]<<"       ";
        }
    int mn=1e9+42;
    //cout<<i<<" -> ";for(int j=1;j<=group[n];j++)cout<<add[j]<<" "<<mini[j]<<endl;cout<<"---"<<endl;
    for(int j=1;j<=group[n];j++)
        mn=min(mn,add[j]+mini[j]);
    if(arr[i]-mn>diff)
    {
        diff=arr[i]-mn;
        id=i;
    }
}
cout<<diff<<endl;
int out=0;
for(int i=1;i<=m;i++)
    if(inp[i].first<=id&&id<=inp[i].second);
    else out++;
cout<<out<<endl;
for(int i=1;i<=m;i++)
    if(inp[i].first<=id&&id<=inp[i].second);
    else cout<<i<<" ";cout<<endl;
return 0;
}