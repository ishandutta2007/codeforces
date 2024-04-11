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

const int N = 1000*1000 + 10;

int cnt[N];

int dp[N][3][3];

int main(){
    int n, m;
    cin >> n >> m; 
    for(int i = 0; i < n; i++) { 
        int x;
        cin >> x;
        cnt[x]++; 
    }


    for(int i = 0; i < N; i++) {
        for(int x = 0; x < 3; x++)
            for(int y = 0; y < 3; y++) {
                dp[i][x][y] = -1e9;
                if( x + y > cnt[i] ) 
                    continue;
                for(int z = 0; z < 3; z++) 
                    if( x + y + z <= cnt[i] ) 
                        dp[i][x][y] = max(dp[i][x][y], dp[i-1][y][z] + z + (cnt[i]-x-y-z) / 3);
            }
    }

    cout << dp[N-1][0][0] << endl;
}