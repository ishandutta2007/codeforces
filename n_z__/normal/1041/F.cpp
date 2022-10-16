#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200001],b[200001];
unordered_map<int,int>mp;
main(){
    int n;
    cin>>n>>a[1];
    int ans=0;
    for(int x=1;x<=n;x++)
    cin>>a[x],ans=max(ans,++mp[a[x]]);
    int m;
    cin>>m>>b[1];
    for(int x=1;x<=m;x++)
    cin>>b[x],ans=max(ans,++mp[b[x]]);
    for(int y=1;y<=30;y++)
    {
        mp.clear();
        for(int x=1;x<=n;x++)
        ans=max(ans,++mp[a[x]%(1<<y)]);
        for(int x=1;x<=m;x++)
        ans=max(ans,++mp[(b[x]+(1<<(y-1)))%(1<<y)]);
    }
    cout<<ans<<endl;
}