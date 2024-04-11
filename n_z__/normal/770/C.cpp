#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100001],vis[100001];
vector<int>v[100001],ans;
void f(int now){if(vis[now]==0){vis[now]=1;for(auto x:v[now])f(x);vis[now]=2;ans.push_back(now);}else if(vis[now]==1){cout<<-1;exit(0);}}
main(){
    int n,k;
    cin>>n>>k;
    for(int x=1;x<=k;x++)
    cin>>a[x];
    for(int x=1,y;x<=n;x++){
        int m;
        cin>>m;
        while(m--)cin>>y,v[x].push_back(y);
    }
    for(int x=1;x<=k;x++)f(a[x]);
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";
}