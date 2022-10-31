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

const int N = 3000*1600 + 10;
const int mod = 1000*1000*1000 + 7;

int sum(int a, int b) { 
    int c = a + b; 
    if( c >= mod ) 
        c -= mod; 
    return c;
}

int mul(int a, int b) { 
    return 1ll * a * b % mod; 
}


int nex[N][2], cnt; 
int val[N]; 

int dp[N][4]; 

int a[N]; 

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    memset(nex, -1, sizeof nex); 
    cnt = 1; 
    int m;
    cin >> m; 
    int ans = 0; 
    dp[0][0] = 1;
    for(int i = 0; i < m; i++) {
        int x; cin >> x; 
        for(int j = 0; j <= i; j++)  {
            if( nex[a[j]][x] == -1 ) { 
                val[cnt] = (val[a[j]] * 2 + x) & 15;
                for(int k = 0; k < 3; k++) {
                    dp[cnt][0] = sum(dp[cnt][0], dp[a[j]][k]);
                    dp[cnt][k+1] = dp[a[j]][k]; 
                }
                if( val[cnt] != 3 && val[cnt] != 5 && val[cnt] != 14 && val[cnt] != 15 )
                    dp[cnt][0] = sum(dp[cnt][0], dp[a[j]][3]);
                ans = sum(ans, dp[cnt][0]);
                nex[a[j]][x] = cnt++; 
            }
            a[j] = nex[a[j]][x];
        }
        cout << ans << '\n';
    }
    return 0;
}