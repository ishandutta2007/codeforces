#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 2000 + 10; 

int64 A[ maxn ], B[ maxn ];
int64 dp[ maxn ][ maxn ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif

    int n, k;
    int64 p;
    cin >> n >> k >> p;

    for (int i = 1; i <= n; ++i)
        cin >> A[i];

    for (int i = 1; i <= k; ++i)
        cin >> B[i];

    sort(A + 1, A + n + 1);
    sort(B + 1, B + k + 1);

    memset(dp, oo, sizeof dp);
    
    for (int i = 0; i <= k; ++i)
        dp[0][i] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j){
            dp[i][j] = min( dp[i][j - 1], 
                max(dp[i - 1][j - 1], abs(A[i] - B[j]) + abs(B[j] - p)) );
        }

    cout << dp[n][k] << endl;

    return 0;
}