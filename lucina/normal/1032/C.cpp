#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
bool dp[maxn][7];
int n,a[maxn],b[maxn];
bool dfs(int x){
    if(x==n+1){
            for(int i=1;i<=n;i++)
            printf("%d ",b[i]);
        return true;
    }
    for(int i=1;i<=5;i++){
        if(dp[x][i]) continue;
        if((a[x]==a[x-1]&&i!=b[x-1])||(a[x]>a[x-1]&&i>b[x-1])||(a[x]<a[x-1]&&i<b[x-1])){
            b[x]=i;
            dp[x][i]=true;
            if(dfs(x+1))
                return true;
        }
    }
    return false;

}
int main(){
    //dp[a][b] means that index a end up with d can't find sol;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=5;i++){
        b[1]=i;
        if(dfs(2))
            return 0;
        }
        printf("%d\n",-1);
    }