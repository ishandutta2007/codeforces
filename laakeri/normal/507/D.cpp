#include <iostream>

using namespace std;

typedef long long ll;

ll dp[1002][101][2];

ll pott[1002];
ll pott2[1002];

int main(){
    ll n,k,mod;
    cin>>n>>k>>mod;
    pott[0]=1;
    for (int i=1;i<=1000;i++){
        pott[i]=pott[i-1]*10ll;
        pott[i]%=k;
    }
    pott2[0]=1;
    for (int i=1;i<=1000;i++){
        pott2[i]=pott2[i-1]*10ll;
        pott2[i]%=mod;
    }
    for (ll i=1;i<10;i++){
        dp[1][i%k][1]++;
    }
    dp[1][0][0]=1;
    ll v=0;
    for (int i=1;i<=n;i++){
        for (int ii=0;ii<k;ii++){
            for (int iii=0;iii<2;iii++){
                if (iii==1&&ii==0){
                    if (i<n) v+=9ll*pott2[n-i-1]*dp[i][ii][iii];
                    else v+=dp[i][ii][iii];
                    v%=mod;
                    dp[i][ii][iii]=0;
                }
                for (ll kk=0;kk<10;kk++){
                    dp[i+1][(ii+pott[i]*kk)%k][kk||iii]+=dp[i][ii][iii];
                    dp[i+1][(ii+pott[i]*kk)%k][kk||iii]%=mod;
                }
            }
        }
    }
    cout<<v<<endl;
}