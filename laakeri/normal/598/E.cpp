#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

ll dp[40][40][60];
ll inf=1e13;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tcs;
    cin>>tcs;
    for (int i=0;i<40;i++){
        for (int ii=0;ii<40;ii++){
            dp[i][ii][0]=0;
            for (int iii=1;iii<60;iii++){
                dp[i][ii][iii]=inf;
            }
        }
    }
    for (int k=1;k<=50;k++){
        for (int i=1;i<=30;i++){
            for (int ii=1;ii<=30;ii++){
                if (i*ii==k){
                    dp[i][ii][k]=0;
                }
                else if (i*ii>k){
                    //ve
                    for (int j=1;j<i;j++){
                        for (int a=0;a<=k;a++){
                            dp[i][ii][k]=min(dp[i][ii][k], dp[j][ii][a]+dp[i-j][ii][k-a]+ii*ii);
                        }
                    }
                    //ho
                    for (int j=1;j<ii;j++){
                        for (int a=0;a<=k;a++){
                            dp[i][ii][k]=min(dp[i][ii][k], dp[i][j][a]+dp[i][ii-j][k-a]+i*i);
                        }
                    }
                }
            }
        }
    }
    for (int tc=0;tc<tcs;tc++){
        int n,m,k;
        cin>>n>>m>>k;
        cout<<dp[n][m][k]<<'\n';
    }
}