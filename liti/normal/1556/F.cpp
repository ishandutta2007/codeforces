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

const int N = 14 + 1;
const int mod = 1e9 + 7;

int sum(int a, int b) { 
    int c = a + b;
    if(c >= mod)
        c -= mod;
    return c;
}
int mul(int a, int b) { 
    return 1ll*a*b%mod;
}

int bpow(int a, int b) { 
    int r = 1; 
    for(; b; b /= 2) {
        if( b % 2 ) 
            r = mul(r, a);
        a = mul(a, a);
    }
    return r;
}

int dp[N][(1<<N)];
int a[N]; 
int win[N][N];

int wmask[N][(1<<N)];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i]; 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
            if( i != j ) 
                win[i][j] = mul(a[i], bpow(sum(a[i], a[j]), mod-2));
    }
    for(int i = 0; i < n; i++) {
        wmask[i][0] = 1;
        for(int mask = 1; mask < (1<<n); mask++) {
            int j = __builtin_ctz(mask); 
            wmask[i][mask] = mul(win[j][i], wmask[i][mask ^ (1<<j)]);
        }
    }


    for(int mask = 1; mask < (1<<n); mask++) { 
        for(int i = 0; i < n; i++)
            if( (mask >> i) & 1 )
                dp[i][mask] = 1; 
        for(int bmask = ((mask-1) & mask); bmask; bmask = ((bmask-1) & mask)) {
            int prob = 1; 
            for(int i = 0; i < n; i++) 
                if( (bmask >> i) & 1 ) 
                    prob = mul(prob, wmask[i][bmask ^ mask]);
            for(int i = 0; i < n; i++) 
                if( (bmask >> i) & 1 ) 
                    dp[i][mask] = sum(dp[i][mask], mod - mul(prob, dp[i][bmask]));
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = sum(ans, dp[i][(1<<n)-1]);

    cout << ans << endl;

    return 0;
}