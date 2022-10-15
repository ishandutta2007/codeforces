#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define ff first
#define ss second
double dist(int a,int b,int c,int d){
    return sqrt((double)((a-c)*(a-c)+(b-d)*(b-d)));
}
signed main(){
    // since this is constructive training, i will do constructives
    // slopes?
    int n;
    cin>>n;
    pair<int,int> p[n+1];
    for(int i=1;i<=n;i++)cin>>p[i].ff>>p[i].ss;
    bool vis[n+1]={};
    vector<int> ans;
    ans.push_back(1);
    vis[1]=1;
    for(int i=0;i<n-1;i++){
        int add=0;
        for(int j=1;j<=n;j++){
            if(vis[j])continue;
            if(!add||dist(p[ans[i]].ff,p[ans[i]].ss,p[j].ff,p[j].ss)>dist(p[ans[i]].ff,p[ans[i]].ss,p[add].ff,p[add].ss))add=j;
        }
        vis[add]=1;
        ans.push_back(add);
    }
    for(auto i:ans)cout<<i<<" ";
}