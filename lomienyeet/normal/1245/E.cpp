#include <bits/stdc++.h>
using namespace std;
#define double long double
#define n 10
#define ff first
#define ss second
// rare moment of me commenting my code
// cus my thought process is too convoluted
int main(){
    int arr[n][n];
    double dp[2][n][n]; // {walked, x-coord, y-coord}
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[0][i][j]=0;
            dp[1][i][j]=727727727727727727; // hi
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<6;i++)dp[0][0][i]=6; // directly 1/6 dice
    for(int i=6;i<n;i++){
        dp[0][0][i]=0;
        for(int j=1;j<=6;j++)dp[0][0][i]+=(1+dp[0][0][i-j])/6.0; // qi wang
    }
    for(int i=1;i<n;i++){
        if(i&1){ // r -> l
            for(int j=n-1;j>-1;j--){
                for(int k=1;k<7;k++){ // dice from walked/!walked
                    pair<int,int> cur={i,j+k};
                    if(cur.ss>=n){
                        cur.ff--;
                        cur.ss-=(n-1);
                        cur.ss=n-cur.ss;
                    }
                    dp[0][i][j]+=(1+min(dp[0][cur.ff][cur.ss],dp[1][cur.ff][cur.ss]))/6.0; // qi wang
                }
                if(arr[i][j])dp[1][i][j]=dp[0][i-arr[i][j]][j];
            }
        }
        else{ // l -> r
            for(int j=0;j<n;j++){
                for(int k=1;k<7;k++){ // dice from walked/!walked
                    pair<int,int> cur={i,j-k};
                    if(cur.ss<0){
                        cur.ff--;
                        cur.ss*=-1;
                        cur.ss--;
                    }
                    dp[0][i][j]+=(1+min(dp[0][cur.ff][cur.ss],dp[1][cur.ff][cur.ss]))/6.0; // qi wang
                }
                if(arr[i][j])dp[1][i][j]=dp[0][i-arr[i][j]][j];
            }
        }
    }
    cout<<fixed<<setprecision(10)<<min(dp[0][n-1][0],dp[1][n-1][0])<<"\n";
}