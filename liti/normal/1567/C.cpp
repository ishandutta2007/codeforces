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

const int N = 11;

ll dp[N][2][2];
int a[N];

void solve() {
    int x;
    cin >> x; 

    int n;
    for(n = 0; x; n++, x/=10)
        a[n] = x % 10; 
    
    memset(dp, 0, sizeof dp); 

    dp[0][0][0] = 1; 

    for(int i = 0; i < n; i++) { 
        for(int c1 = 0; c1 < 2; c1++) 
            for(int c2 = 0; c2 < 2; c2++) 
                for(int f = 0; f < 10; f++) 
                    for(int s = 0; s < 10; s++) { 
                        int d = c1 + f + s; 
                        int digit = d % 10; 
                        int c3 = d / 10; 

                        if(digit != a[i])
                            continue;


                        dp[i+1][c2][c3] += dp[i][c1][c2]; 
                    } 
    }

    cout << dp[n][0][0]-2 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    int t;
    cin >> t;
    while(t--) 
        solve();
    return 0;
}