//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = 1000*100 + 100;

const int mod = 1e9 + 7;

int sum(int a, int b){ 
    int c=  a + b; 
    if( c >= mod ) c -= mod; 
    return c;
}
int mul(int a, int b) { 
    return 1ll * a * b % mod; 
}
int bpow(int a, int b) { 
    int r = 1; 
    for( ; b ; b /=2 ) { 
        if( b % 2 == 1 ) 
            r = mul(r, a ); 
        a = mul(a, a ); 
    }

    return r;
}

int inv(int v) { 
    return bpow(v, mod-2); 
}


int dp[N]; 
int z[N]; 
vector<int> pr[N]; 
int cnt[N]; 

int main(){
    ios::sync_with_stdio(false); cin.tie(0); 

    fill( z, z + N, 1 ); 
    for(int i = 2; i < N; i++) 
        if( pr[i].empty() ) { 
            for(int j = i; j < N; j += i) { 
                z[j] *= i; 
                pr[j].pb(i); 
            }
        }


    int n;
    cin >> n; 

    for(int i = 1; i <= n; i++) 
        cnt[z[i]]++; 

    dp[1] = 0; 
    int M = inv(n);
    int ans = inv(n); 

    for(int i = 2; i <= n; i++) { 
        if( cnt[i] == 0 ) continue;
        int k = sz(pr[i]); 
        int tot = (1<<k) - 1; 
        int zzz = -1; 
        for(int mask = 0; mask < (1<<k); mask++) { 
            int rem = 1; 
            for(int j = 0; j < k; j++) 
                if( ( (mask>>j) & 1 ) == 0 ) 
                    rem *= pr[i][j]; 

            int val = rem;
            rem = n/rem; 
            
            int ted = 0; 
            for( int submask = mask; ; submask = ((submask-1) & mask) ) {
                int cof = 1; 
                if( __builtin_popcount(submask) % 2 == 1 ) 
                    cof = mod-1;
                int num = 1;
                for(int j = 0; j < k; j++) 
                    if( (submask>>j) & 1 ) 
                        num *= pr[i][j]; 
                ted = sum(ted, mul(cof, rem/num)); 

                if( submask == 0 ) break;
            }

            dp[i] = sum(dp[i], mul(ted, M));
            if( val == i ) { 
                zzz = sum(1, mod - mul(ted, M));
            } else
                dp[i] = sum(dp[i], mul(mul(ted,M), dp[val]));
        }

        assert(zzz != -1);
        dp[i] = mul(dp[i], inv(zzz));

        ans = sum(ans, mul(cnt[i], mul(M, 1+dp[i])));
    }

    cout << ans << endl;

    return 0;
}