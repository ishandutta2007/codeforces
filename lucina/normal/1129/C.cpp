#include<bits/stdc++.h>
using namespace std;
const int maxn=3010,mod=1e9+7;
void add(int &a,int b){
    a+=b; if(a>=mod)a-=mod; return;
}
int dp[maxn][maxn],n,a[maxn],s,x,len;
int trie[maxn*1000*2][2];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            len=j-i+1;
            if(len==1)dp[i][j]=1;
            else if(len==2)dp[i][j]=2;
            else if(len==3)dp[i][j]=4;
            else{
                for(int k=1;k<=3;k++)
                add(dp[i][j],dp[i][j-k]);
            ///"0011", "0101", "1110", and "1111"
            x=a[j-3]*8+a[j-2]*4+a[j-1]*2+a[j];
            if(x!=3&&x!=5&&x!=14&&x!=15){
                add(dp[i][j],len==4?1:dp[i][j-4]);
            }
            }
        }
    }
    int ans=0,root,cur=1;
    for(int i=1;i<=n;i++){
        root=1;
        for(int j=i;j>=1;j--){
            if(!trie[root][a[j]]){
                add(ans,dp[j][i]);
                trie[root][a[j]]=++cur;
            }
            root=trie[root][a[j]];
        }
        printf("%d\n",ans);
    }
}