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
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

const int maxN= 1000 + 5;

int n;
int cost[maxN];
int dp[maxN][maxN];
vector <int> ans;

inline void setDyn(){
    for (int i=1;i<=n;i++)
        dp[0][i]= cost[i];

    for (int i=2;i<=n;i++)
        dp[1][i]= max (cost[1], cost[i]);

    for (int i=2;i<=n;i++){

        for (int j=i+1;j<=n;j++){
            
            int tmp1= dp[i-2][j] + max (cost[i-1], cost[i]);
            int tmp2= dp[i-2][i] + max (cost[i-1], cost[j]);
            int tmp3= dp[i-2][i-1] + max (cost[i], cost[j]);

            dp[i][j]= min (tmp1, min(tmp2,tmp3));
        }
    }
}
/*************************************/
inline void print (int i, int j){

    if (i==0){
        ans.push_back (j);
        return;
    }

    if (i==1){
        ans.push_back (j);
        ans.push_back (i);
        return;
    }

    int tmp1= dp[i-2][j] + max (cost[i-1], cost[i]);
    int tmp2= dp[i-2][i] + max (cost[i-1], cost[j]);
    int tmp3= dp[i-2][i-1] + max (cost[i], cost[j]);

    if (dp[i][j]==tmp1){
        ans.push_back (i);
        ans.push_back (i-1);
        print (i-2,j);
    }

    else if (dp[i][j]==tmp2){
        ans.push_back (j);
        ans.push_back (i-1);
        print (i-2, i);
    }
    else if (dp[i][j]==tmp3){
        ans.push_back (j);
        ans.push_back (i);
        print (i-2, i-1);
    }
    
}
/*************************************/
int main(){
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> cost[i];

    reverse (cost+1, cost+n+1);

    if (n==1){
        cout << cost[1] << endl;
        cout << 1 << endl;
        return 0;
    }

    setDyn();

    cout << dp[n-1][n] << endl;

    print (n-1, n);

    if (n%2==1)
        ans.push_back (-1);

    for (int i=0;i<(int)ans.size();i++){
        if (ans[i]!=-1){
            cout << n-ans[i]+1;
            if (i%2==1)
                cout << endl;
            else
                cout << ' ';
        }
    }

    if (ans.back()==-1)
        cout << endl;
    
    return 0;
}