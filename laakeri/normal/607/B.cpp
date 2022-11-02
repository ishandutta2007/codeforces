#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[555][555];
int dp2[555];
int c[555];

int n;

void calc(int a, int b){
    if (a==b){
        dp[a][b]=1;
    }
    else if(b==a+1){
        if (c[a]==c[b]){
            dp[a][b]=1;
        }
        else{
            dp[a][b]=2;
        }
    }
    else{
        for (int m=a;m<b;m++){
            dp[a][b]=min(dp[a][b], dp[a][m]+dp[m+1][b]);
        }
    }
    //cout<<a<<" "<<b<<" "<<dp[a][b]<<endl;
    for (int j=1;a-j>=0&&b+j<n;j++){
        if (c[a-j]!=c[b+j]) break;
        dp[a-j][b+j]=min(dp[a-j][b+j], dp[a][b]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>c[i];
    }
    for (int i=0;i<=n;i++){
        for (int ii=0;ii<=n;ii++){
            dp[i][ii]=555;
        }
        dp[i][i]=1;
    }
    for (int le=1;le<=n;le++){
        for (int i=0;i+le-1<n;i++){
            calc(i, i+le-1);
        }
    }
    cout<<dp[0][n-1]<<endl;
}