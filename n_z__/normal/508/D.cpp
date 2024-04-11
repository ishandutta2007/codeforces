#include<bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize(3)
#define int long long
using namespace std;
vector<int>e[1000001];
int innum[1000001],outnum[1000001];
int ans[1000001],cnt;
void DFS(int x)
{
    if(x==0)return;
    for(int i=0;i<e[x].size();i++)
    {
        int w=e[x][i];
        e[x][i]=0;
        DFS(w);
    }
    ans[++cnt]=x;
}
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int num=0,id=1;
    for(int x=1;x<=n;x++)
    {
        string s;
        cin>>s;
        int u=s[0]*256+s[1],v=s[1]*256+s[2];
        e[u].push_back(v);
        outnum[u]++;
        innum[v]++;
        id=u;
    }
    int kind=0;
    for(int x=0;x<=65535;x++)
    {
        num+=abs(innum[x]-outnum[x]);
        if(innum[x]<outnum[x])id=x;
        if(innum[x]!=0||outnum[x]!=0)kind++;
    }
    //cout<<id<<endl;
    if(kind==1){cout<<"YES"<<endl;for(int x=1;x<=n+2;x++)cout<<(char)(id/256);}
    else if(num>2)cout<<"NO"<<endl;
    else{
        DFS(id);
        if(cnt!=n+1)cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<(char)(ans[cnt]/256);
            for(int x=cnt;x>=1;x--)
            cout<<(char)(ans[x]%256);
        }
    }
}