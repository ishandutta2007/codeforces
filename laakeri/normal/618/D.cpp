#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[202020];
int dp[202020][2];

void dfs(int x, int p){
    vector<int> cc;
    int c0=0;
    for (int nx:g[x]){
        if (nx!=p){
            dfs(nx, x);
            c0+=dp[nx][0];
            cc.push_back(dp[nx][1]-dp[nx][0]);
        }
    }
    dp[x][0]=c0+1;
    dp[x][1]=c0+1;
    sort(cc.begin(), cc.end());
    if ((int)cc.size()>1){
        dp[x][0]=min(dp[x][0], c0+cc[0]+cc[1]-1);
    }
    if ((int)cc.size()>0){
        dp[x][1]=min(dp[x][1], c0+cc[0]);
        dp[x][0]=min(dp[x][0], c0+cc[0]);
    }
    //cout<<x<<" "<<dp[x][0]<<" "<<dp[x][1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll x,y;
    cin>>n>>x>>y;
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (n==2){
        cout<<x<<endl;
        return 0;
    }
    if (x>=y){
        int f=0;
        int ff=0;
        for (int i=1;i<=n;i++){
            if ((int)g[i].size()==n-1){
                f=1;
            }
            if ((int)g[i].size()>2) {
                ff=1;
            }
        }
        if (f==1){
            cout<<(ll)(n-2)*y+x<<endl;
        }
        else{
            cout<<(ll)(n-1)*y<<endl;
        }
        return 0;
    }
    dfs(1, 0);
    ll v=dp[1][0]-1;
    //cout<<v<<endl;
    cout<<(ll)v*y+(ll)(n-1-v)*x<<endl;
}