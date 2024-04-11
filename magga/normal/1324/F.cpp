#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int aa = 0;
long long int n,a,b;
int flag[200001];
vector<long long int>grap[200001];
bool visited[200001]{0};
long long int dp[200001]{0};
long long int ans[200001]{0};
long long int dfs(long long int i,long long int par){
    long long int ret = flag[i]; 
    for(auto j:grap[i]){
        if(j!=par){
            ret+=max(aa,dfs(j,i));
        }
    }
    dp[i]=ret;
    return ret;   
}
void dfs2(long long int i,long long int par){
    for(auto j:grap[i]){
        if(j==par){
            continue;
        }
        dp[i]-=max(aa,dp[j]);
        dp[j]+=max(aa,dp[i]);
        dfs2(j,i);
        dp[j]-=max(aa,dp[i]);
        dp[i]+=max(aa,dp[j]);
    }
    ans[i]=dp[i];
}
void solve(){
    cin>>n;
    for(long long int i=0;i<n;i++){
        cin>>flag[i];
        if(flag[i]==0){
            flag[i]=-1;
        }
    }
    for(long long int i=0;i<n-1;i++){
        cin>>a>>b;a--;b--;
        grap[a].push_back(b);
        grap[b].push_back(a);
    }
    dfs(0,-1);
    dfs2(0,-1);
    for(long long int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}