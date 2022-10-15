#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=3e5+5;
int nxt[2][mxN<<4],freq[mxN<<4],dp[2][32],cnt=0;
void upd(int x){
    int ptr=0;
    for(int i=30;i>=0;i--){
        int z=(x>>i)&1;
        if(!nxt[z][ptr])nxt[z][ptr]=++cnt;
        ptr=nxt[z][ptr];
        freq[ptr]++;
    }
}
void eat(int x){
    int ptr=0;
    for(int i=30;i>=0;i--){
        int z=(x>>i)&1,s=freq[nxt[z^1][ptr]];
        dp[z][i]+=s;
        ptr=nxt[z][ptr];
        if(!ptr)return;
    }
}
signed main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        eat(x);
        upd(x);
    }
    int ans=0,inv=0;
    for(int i=30;i>=0;i--){
        inv+=min(dp[0][i],dp[1][i]);
        if(dp[1][i]<dp[0][i])ans|=(1<<i);
    }
    cout<<inv<<" "<<ans<<"\n";
}