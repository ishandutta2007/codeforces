//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 100;

int dp[N][2];

void pr(int n, int c) {
    if(n==0)
        return;

    if(dp[n][c] == dp[n-1][1-c]) 
        pr(n-1, 1 - c);
    else
        pr(n-1, c);

    cout << (c == 0? 'R':'B') ;
}


void solve() { 
    int n;
    cin >> n;

    string s;
    cin >> s;

    for(int i = 0; i < n; i++) {
        if( s[i] == 'R' ) {
            dp[i+1][0] = min(dp[i][0] + 1, dp[i][1]);
            dp[i+1][1] = 1e9;
        } else if( s[i] == 'B' ) { 
            dp[i+1][1] = min(dp[i][1] + 1, dp[i][0]);
            dp[i+1][0] = 1e9;
        } else {
            dp[i+1][0] = min(dp[i][0] + 1, dp[i][1]);
            dp[i+1][1] = min(dp[i][1] + 1, dp[i][0]);
        }
    }
    if(dp[n][0] < dp[n][1])
        pr(n, 0);
    else
        pr(n, 1);
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
    return 0;
}