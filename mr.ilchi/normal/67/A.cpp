/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN= 1000+5;
const int INF= 1000000+5;

int n;
int a[maxN], min1[maxN], min2[maxN];
int dp[maxN][maxN], par[maxN][maxN];

inline void print (int id, int pos){
    if (id==1){
        cout << pos << ' ';
        return;
    }

    print (id-1, par[id][pos]);
    cout << pos << ' ';
}
/**********************************/
int main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        dp[1][i]= i;
        min1[i]= 1;
        min2[i]= i+1;
    }
    min1[1]= 0;

    dp[1][0]= dp[1][n+1]= INF;
    
    for (int i=2;i<=n;i++){
        char ch; cin>>ch;
        for (int j=1;j<=n;j++){
            if (ch=='='){
                dp [i][j]= min (INF, dp[i-1][j] + j);
                par[i][j]= j;
            }
            if (ch=='R'){
                dp [i][j]= min (INF, dp[i-1][min1[j]] + j);
                par[i][j]= min1[j]; 
            }
            if (ch=='L'){
                dp [i][j]= min (INF, dp[i-1][min2[j]] + j);
                par[i][j]= min2[j];
            }
        }

        dp[i][0]= dp[i][n+1]= INF;
        min1[1]= 0;
        for (int j=2;j<=n;j++){
            if (dp[i][j-1] < dp[i][min1[j-1]])
                min1[j]= j-1;
            else
                min1[j]= min1[j-1];
        }

        min2[n]= n+1;
        for (int j=n-1;j>0;j--){
            if (dp[i][j+1] < dp[i][min2[j+1]])
                min2[j]= j+1;
            else
                min2[j]= min2[j+1];
        }
    }

    int pos=1;
    for (int i=2;i<=n;i ++)
        if (dp[n][i] < dp[n][pos])
            pos= i;

    print (n,pos);
    cout << endl;

    return 0;
}