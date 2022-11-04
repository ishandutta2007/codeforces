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
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int maxN= 5000+5;

typedef long long ll;

const ll INF= 1ll<<60;

int n;
int cost[maxN];
ll dp[2][maxN];
vector <int> Q;

int main (){
    scanf ("%d", &n);
    for (int i=1;i<=n;i++){
        scanf ("%d",cost+i);
        Q.push_back(cost[i]);
    }
    
    sort (Q.begin(), Q.end());
    for (int i=1;i<=n;i ++){
        int cur=(i&1), oth=((i+1)&1);
        dp[cur][0]= dp[oth][0]+ labs(cost[i]-Q[0]);
        for (int j=1;j< (int)Q.size();j ++)
            dp[cur][j]= min(dp[cur][j-1], dp[oth][j]+labs(cost[i]-Q[j]));
    }
    printf ("%I64d\n", dp[n&1][Q.size()-1]);

    return 0;
}