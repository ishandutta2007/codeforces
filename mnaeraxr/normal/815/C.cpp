#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 5000 + 10;

int64 dp1[ maxn ][ maxn ];
int64 dp2[ maxn ][ maxn ];

int64 cost1[ maxn ], cost2[ maxn ];
int64 tp1[ maxn ], tp2[ maxn ];

int parent[ maxn ];
int size[ maxn ];

vector<int> adj[ maxn ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int64 b;

    cin >> n >> b;

    for (int i = 1; i <= n; ++i){
        cin >> cost1[i] >> cost2[i];
        cost2[i] = cost1[i] - cost2[i];
        if (i > 1){
            int par; cin >> par;
            adj[ par ].push_back( i );
        }
    }

    memset( dp1, 0x3f, sizeof dp1 );
    memset( dp2, 0x3f, sizeof dp2 );

    for (int i = n; i; --i){
        dp1[i][0] = dp2[i][0] = 0;
        dp1[i][1] = cost1[i];
        dp2[i][1] = cost2[i];
        size[ i ] = 1;

        for (auto u : adj[i]){
            memset( tp1, 0x3f, sizeof tp1 );
            memset( tp2, 0x3f, sizeof tp2 );

            tp1[0] = tp2[0] = 0;
            
            for (int j = 0; j <= size[u]; ++j){
                for (int k = 0; k <= size[i]; ++k){
                    tp1[k + j] = min(tp1[k + j], dp1[i][k] + dp1[u][j]);

                    if (k)
                        tp2[k + j] = min(tp2[k + j], dp2[i][k] + min(dp2[u][j], dp1[u][j]));
                }
            }
            size[ i ] += size[ u ];
            for (int j = 0; j <= size[i]; ++j)
                dp1[i][j] = tp1[j], dp2[i][j] = tp2[j];
        }
    }

    int t = 0;

    while (dp1[1][t + 1] <= b || dp2[1][t + 1] <= b)
        t++;

    cout << t << endl;

    return 0;
}

/*
 * solution: 9
 */