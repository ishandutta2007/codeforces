#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL dp[200010], ans;
vector<int> link[200010];
void dfs(int num, int from)
{
    dp[num]=1;
    for(int i=0; i<link[num].size(); i++){
        if(link[num][i]==from)continue;
        dfs(link[num][i], num);
        dp[num]+=dp[link[num][i]];
    }
}
void dfs2(int num, int from, LL c)
{
    //printf("%d %d\n", c, num);
    ans=max(ans, c);
    for(int i=0; i<link[num].size(); i++){
        if(link[num][i]==from)continue;
        int temp1=dp[num], temp2=dp[link[num][i]];
        swap(dp[num], dp[link[num][i]]);
        int temp=dp[num]+dp[link[num][i]];
        dp[num]=n-temp2;
        dfs2(link[num][i], num, c-temp+dp[num]+dp[link[num][i]]);
        swap(dp[num], dp[link[num][i]]);
        dp[num]=temp1;
        dp[link[num][i]]=temp2;
    }
}
int main()
{
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        link[a].push_back(b);
        link[b].push_back(a);
    }
    int leaf;
    for(int i=1; i<=n; i++){
        if(link[i].size()==1){
            leaf=i;
            break;
        }
    }
    dfs(leaf, 0);
    for(int i=1; i<=n; i++){
        ans+=dp[i];
    }
    dfs2(leaf, 0, ans);
    printf("%lld", ans);
}