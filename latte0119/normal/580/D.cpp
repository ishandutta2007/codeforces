#include<bits/stdc++.h>
using namespace std;
#define int long long
int N,M,K;

int A[20];
int val[20][20];

int dp[1<<19][20];
signed main(){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++)cin>>A[i];
    for(int i=0;i<K;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        val[a][b]=c;
    }
    fill_n(*dp,(1<<19)*20,-1001001001);
    for(int i=0;i<N;i++){
        dp[1<<i][i]=A[i];
    }

    for(int i=0;i<(1<<N);i++){
        for(int j=0;j<N;j++){
            if(dp[i][j]==-1001001001)continue;
            for(int k=0;k<N;k++){
                if((i>>k)&1)continue;
                int &to=dp[i|(1<<k)][k];
                to=max(to,dp[i][j]+A[k]+val[j][k]);
            }
        }
    }

    int ans=0;
    for(int i=0;i<(1<<N);i++){
        int bit=0;
        for(int j=0;j<N;j++)if((i>>j)&1)bit++;
        if(bit!=M)continue;
        for(int j=0;j<N;j++)ans=max(ans,dp[i][j]);
    }
    cout<<ans<<endl;
    return 0;
}