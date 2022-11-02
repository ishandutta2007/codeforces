#include <iostream>
#include <vector>

using namespace std;

int dp[30001][601];

int gs[30001];

int main(){
    int n,d;
    cin>>n>>d;
    dp[d][300]=1;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        gs[a]++;
    }
    int mv=0;
    for (int i=0;i<=30000;i++){
        for (int ii=0;ii<600;ii++){
            if (d+ii-300>0&&dp[i][ii]){
                dp[i][ii]+=gs[i];
                mv=max(mv, dp[i][ii]);
                if (ii-1>=0&&i+d+ii-300-1<=30000){
                    dp[i+d+ii-300-1][ii-1]=max(dp[i+d+ii-300-1][ii-1], dp[i][ii]);
                }
                if (i+d+ii-300<=30000) dp[i+d+ii-300][ii]=max(dp[i+d+ii-300][ii], dp[i][ii]);
                if (i+d+ii-300+1<=30000) dp[i+d+ii-300+1][ii+1]=max(dp[i+d+ii-300+1][ii+1], dp[i][ii]);
            }
        }
    }
    cout<<mv-1<<endl;
}