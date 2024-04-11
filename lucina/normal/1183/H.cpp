#include<bits/stdc++.h>
using namespace std;
char s[105];
int last[105][26],n;
long long dp[105][105],f[105],cost;
long long k;
long long recur(int pos,int len){
    if(pos==-1)return 0LL;
    if(len==0)return 1LL;
    if(dp[pos][len]!=-1)return dp[pos][len];
    long long res=0;
    for(int i=0;i<26;i++){
        res+=(recur(last[pos][i],len-1));
        if(res>k)break;
    }
    return dp[pos][len]=res;
}

int main(){
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=102;i++)
        for(int j=0;j<26;j++)
        last[i][j]=-1;
    scanf("%s",s+1);
    for(int i=0;i<105;i++)
        for(int j=0;j<105;j++)
        dp[i][j]=-1LL;
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++){
            last[i+1][j]=max(last[i+1][j],last[i][j]);
        }
        last[i+1][s[i]-'a']=i;
    }
    for(int i=0;i<=n;i++)
    f[i]=recur(n+1,i);
    for(int i=n;i>=0;i--){
        if(f[i]){
            if(f[i]>k){
                cost+=(k*(n-i));
                k=0;
            }
            else{
                k-=f[i];
                cost+=(f[i]*(n-i));
            }
        }
    }
    printf("%lld\n",k==0?cost:-1LL);
}