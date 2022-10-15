#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
signed main(){
    int a,n,m,weeee=1e18;
    cin>>a>>n>>m;
    bool wa[a+1]={};
    for(int i=1,u,v;i<=n;i++){
        cin>>u>>v;
        weeee=min(weeee,u);
        for(int j=u;j<v;j++)wa[j]=1;
    }
    pair<int,int> p[m+1];
    for(int i=1;i<=m;i++)cin>>p[i].ff>>p[i].ss;
    sort(p+1,p+m+1);
    if(weeee<p[1].ff){
        cout<<"-1\n";
        return 0;
    }
    int ans[a+1]={};
    for(int i=1;i<=a;i++){
        weeee=1e18;
        if(!wa[i-1])ans[i]=ans[i-1];
        else{
            for(int j=1;j<=m;j++){
                int z=0;
                if(p[j].ff<i){
                    z=ans[p[j].ff]+p[j].ss*(i-p[j].ff);
                    weeee=min(weeee,z);
                }
            }
            ans[i]=weeee;
        }
    }
    cout<<ans[a]<<"\n";
}