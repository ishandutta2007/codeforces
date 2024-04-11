#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll dp[202020][2];
ll a[202020];
vector<int> g[202020];

void dfs(int x){
    int ho=0;
    for (int nx:g[x]){
        dfs(nx);
        ll e=dp[x][0];
        ll o=dp[x][1];
        dp[x][1]=max(dp[x][1], e+dp[nx][1]);
        dp[x][0]=max(dp[x][0], e+dp[nx][0]);
        if (ho){
            dp[x][1]=max(dp[x][1], o+dp[nx][0]);
            dp[x][0]=max(dp[x][0], o+dp[nx][1]);
        }
        ho=1;
    }
    dp[x][1]=max(dp[x][1], dp[x][0]+a[x]);
    //cout<<x<<" "<<a[x]<<" "<<dp[x][1]<<" "<<dp[x][0]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int p;
        cin>>p>>a[i];
        if (p>0){
            g[p].push_back(i);
        }
    }
    dfs(1);
    cout<<max(dp[1][0], dp[1][1])<<endl;
}