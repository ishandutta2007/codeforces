#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
int n,a[maxn],ct[maxn];
///mask and last bit remove 
void dfs(int mask,int bit){
    if(ct[mask]==2)return;
    ++ct[mask];
    for(int i=bit;i<=20;i++){
        if((mask>>i)&1)
            dfs(mask^(1<<i),i+1);
    }
    return;
}

int main(){
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n;i>=1;i--){
        if(i<=n-2){
            int cur=0;
            for(int j=20;j>=0;j--){
                if((!(a[i]>>j & 1))&&(ct[cur^(1<<j)]==2)){
                        cur^=(1<<j);
                }
            }
        ans=max(ans,a[i]^cur);
        }
        dfs(a[i],0);
    }
    printf("%d\n",ans);
}
/*
    Good Luck
        -Lucina
*/