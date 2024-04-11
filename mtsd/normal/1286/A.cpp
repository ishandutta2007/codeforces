#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int dp[110][101][101][2];

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int t = (n+1)/2;
    int s = n/2;
    // rep(i,n){
    //     if(a[i]!=0){
    //         if(a[i]%2==0){
    //             s--;
    //         }else{
    //             t--;
    //         }
    //     }
    // }
    rep(i,105){
        rep(j,100){
            rep(k,100){
                rep(l,2){
                    dp[i][j][k][l] = inf;
                }
            }
        }
    }
    dp[0][s][t][0] = 0;
    dp[0][s][t][1] = 0;
    for(int i=1;i<=n;i++){
        rep(j,s+1){
            rep(k,t+1){
                if(a[i-1]==0){
                    dp[i][j][k][0] = min(dp[i][j][k][0],dp[i-1][j+1][k][0]);
                    dp[i][j][k][0] = min(dp[i][j][k][0],dp[i-1][j+1][k][1] + 1);
                    dp[i][j][k][1] = min(dp[i][j][k][1],dp[i-1][j][k+1][0] + 1);
                    dp[i][j][k][1] = min(dp[i][j][k][1],dp[i-1][j][k+1][1]);
                }else if(a[i-1]%2==0){
                    dp[i][j][k][0] = min(dp[i][j][k][0],dp[i-1][j+1][k][0]);
                    dp[i][j][k][0] = min(dp[i][j][k][0],dp[i-1][j+1][k][1] + 1);
                
                }else{
                    dp[i][j][k][1] = min(dp[i][j][k][1],dp[i-1][j][k+1][0] + 1);
                    dp[i][j][k][1] = min(dp[i][j][k][1],dp[i-1][j][k+1][1]);
                    
                }
            }
        }
    }
    // rep(i,n+1){
    //     rep(j,s+1){
    //         rep(k,t+1){
    //             cerr << i << " "<< j << " "<< k << " " << dp[i][j][k][0] << " "<< dp[i][j][k][1] << endl; 
    //         }
    //     }
    // }
    cout << min(dp[n][0][0][1],dp[n][0][0][0]) << endl;
    return 0;
}