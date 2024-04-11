#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> G[], int n, int par, int dp[], int sp[]) {
    //dp is assume delete, sp is assume infected
//    cout<<n<<endl;
    dp[n] = 0, sp[n] = 0;
    int can = 0;
    for(auto it: G[n]) {
        if(it == par) continue;
        dfs(G,it,n,dp,sp);
        dp[n] += dp[it]+1;
        sp[n] += sp[it];
        can = max(can,dp[it]-sp[it]);
    }
    sp[n] += can;
//    cout<<n+1<<' '<<dp[n]<<' '<<sp[n]<<endl;
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        vector<int> G[n];
        for(int i=0;i<n-1;i++) {
            int a,b; cin>>a>>b; a--,b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
//        cout<<"YEA\n";
        int dp[n], sp[n];
        dfs(G,0,-1,dp, sp);
        cout<<sp[0]<<endl;
    }
    return 0;
}