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
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 1000 + 10;

int a[N][N];
int dp[2][N][N];

int dx[] = {0, -1}; 
int dy[] = {-1, 0};

ll sum = 0; 

void set(int& a, int b) { 
    sum = sum - a + b; 
    a = b; 
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q; 

    int alive = n * m;

    for(int i = n-1; i >= 0; i--) 
        for(int j = m-1; j >= 0; j--) {
            set(dp[0][i][j], 1 + dp[1][i][j+1]); 
            set(dp[1][i][j], 1 + dp[0][i+1][j]);
        }

    for(int k = 0; k < q; k++) { 
        int x, y;
        cin >> x >> y; 

        x--; y--; 

        if (a[x][y] == 0) { 
            a[x][y] = 1;
            alive--; 
            set(dp[0][x][y], 0); 
            set(dp[1][x][y], 0); 
        } else {
            a[x][y] = 0;
            alive++; 
            set(dp[0][x][y], 1 + dp[1][x][y+1]);
            set(dp[1][x][y], 1 + dp[0][x+1][y]); 
        }

        for(int t = 0; t < 2; t++) {
            int r = x, c = y;

            for(int i = 0;;i ^= 1) { 
                int oldr = r, oldc = c;
                
                r += dx[i^t], c += dy[i^t]; 


                if(r >= 0 && c >= 0 && a[r][c] == 0) {
                    set(dp[t^i][r][c], 1 + dp[t^i^1][oldr][oldc]);
                } else 
                    break;
            }
        }

        cout << sum - alive << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    solve();
    return 0;
}