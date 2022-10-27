/**
    Remember : Don't count root as leaf in rooted tree!!!!!
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int lf,n;
int dp[maxn];
vector<int> a[maxn];
void dfs(int nod,bool dep){
    if(a[nod].empty()){
            ///ok :P Stupid me
        return (void)(lf++,dp[nod] = 1);
    }
    for(int i : a[nod])
            dfs(i,dep ^ 1);
    if(dep){
        dp[nod] = 0;
        for(int i:a[nod])
            dp[nod] += dp[i];
    }
    else{
        dp[nod] = maxn;
        for(int i:a[nod])
            dp[nod] = min(dp[nod],dp[i]);
    }
    return ;
}


int main(){
    scanf("%d" ,&n);
    int u,v;
    for(int i =1 ;i<n;i++){
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
    }
    if(n == 1)
        return !printf("1 1");
    dfs(1,0);
    int ans1 = lf - dp[1] + 1;
    dfs(1,1);
    printf("%d %d\n",ans1,dp[1]);
}
/**
    Should I think something better?
    Ok, at first let's handle max case
    dp[i] = maximum value we can get from subtree i
    imagine that in this node it's first player turn
    dp[i1] , dp[i2], ... dp[ik] is the return value
    So what's the maximum we could get ?
    Isn't it simply min(dp[i1], dp[i2],...., dp[ik]) based on rank
    And then what's second player turn
    dp[i1], dp[i2], ... dp[ik] is return value
    Then what's the minimum ?
    based on rearrangement he can put
    3 3 4
    100 99 98 | 100 99 98 | 100 99 98 97
    So we keep max instead
*/