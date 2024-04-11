#include<bits/stdc++.h>
using namespace std;
int dp[205][205], n , w[205], k;
vector<int> a[205];

///dp[x][y] maximum weight subset from subtree x
///with nearest node to it has distance at least y
void dfs(int nod,int pa){
    dp[nod][0] = w[nod];
    for(int i :a[nod]){
        if(i == pa) continue;
        dfs(i , nod);
    }
    for(int i = 0; i <= k + 1 ; i++){
        if(i == 0){
            for(int j:a[nod]){
                if(j != pa)
                dp[nod][0] += dp[j][max(0, k - 1)];
            }
        }
        else{
            for(int j :a[nod]){
                if(j == pa) continue;
                int sum = dp[j][i - 1];
                for(int v: a[nod]){
                    if(v != j && v != pa)
                        sum += dp[v][max(i - 1, k - 1 - i)];
                        ///at least i - 1 and sum is less than k? yes
                }
                dp[nod][i] = max(dp[nod][i], sum);
            }
        }
    }
    for(int i = k ;i >= 0 ; i--){
        dp[nod][i] = max(dp[nod][i], dp[nod][i + 1]);
    }
    return;
}


int main(){
    int u, v;
    scanf("%d %d", &n, &k);
    ++ k;
    for(int i = 1; i<= n;i++){
        scanf("%d",&w[i]);
    }
    for(int i = 1 ;i < n; i++){
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1 , 0);
    printf("%d\n", dp[1][0]);

}