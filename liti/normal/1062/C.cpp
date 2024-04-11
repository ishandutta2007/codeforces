//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 1000 * 1000 + 10; 
const int mod = 1e9 + 7;
int psum[maxN];

int dp[maxN];
int tav[maxN];

int main() { 
    dp[0] = 0;
    tav[0] = 1; 

    for(int i = 1; i < maxN; i++) { 
        tav[i] = (2*tav[i-1]) % mod; 
        dp[i] = (2*dp[i-1] + 1) % mod;
    }

    ios::sync_with_stdio(false); cin.tie(0);

    int n, q; 
    cin >> n >> q; 
    string s; 
    cin >> s; 
    for( int i = 0; i < n; i++ ) { 
        int v = (s[i] == '1'); 
        psum[i+1] = psum[i] + v; 
    }

    for(int i = 0; i < q; i++) { 
        int l, r;
        cin >> l >> r; 
        l--; 
        int o = psum[r] - psum[l]; 
        cout << (dp[o] + 1LL*dp[o]*(tav[r-l-o]+mod-1)%mod) % mod  << '\n';
    }
}