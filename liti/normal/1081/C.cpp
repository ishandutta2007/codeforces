//In the name God
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int maxN = 2000 + 10;
const int mod = 998244353;

int mul(int a, int b) { 
    return 1ll * a * b % mod;
}
int sum(int a, int b) { 
    int c = a + b;
    if( c >= mod ) 
        c -= mod; 
    return c;
}

int dp[maxN][maxN];

int main() {
    int n, m, k;
    cin >> n >> m >> k; 
    dp[0][0] = m; 
    for(int i = 1; i < n; i++) 
        for(int k = 0; k <= i; k++) {
            if( k ) 
                dp[i][k] = mul(dp[i-1][k-1], m-1);
            dp[i][k] = sum(dp[i][k], dp[i-1][k]);
        }
    cout << dp[n-1][k] << endl;
    return 0; 
}