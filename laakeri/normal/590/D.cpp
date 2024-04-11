#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[2][400][15000];
int a[222];

void sm(int i, int ii, int j, int v){
    if (dp[i][ii][j]==0){
        dp[i][ii][j]=v;
    }
    else{
        dp[i][ii][j]=min(dp[i][ii][j], v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,s;
    cin>>n>>k>>s;
    s=min(s, 14000);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    dp[0][0][0]=1;
    for (int i=0;i<n;i++){
        int im=i%2;
        int nim=(i+1)%2;
        for (int j=0;j<=i;j++){
            for (int ii=0;ii<=s;ii++){
                if (dp[im][j][ii]>0){
                    sm(nim, j, ii, dp[im][j][ii]);
                    sm(nim, j+1, ii+(i-j), dp[im][j][ii]+a[i]);
                }
            }
        }
        for (int j=0;j<200;j++){
            for (int ii=0;ii<=s+1;ii++){
                dp[im][j][ii]=0;
            }
        }
    }
    int v=1e9;
    for (int ii=0;ii<=s;ii++){
        if (dp[n%2][k][ii]>0) v=min(v, dp[n%2][k][ii]);
    }
    cout<<v-1<<endl;
}