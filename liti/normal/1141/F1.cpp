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

const int N = 1500 + 10;

int a[N];
int dp[N][N];

map<int,int> ans; 
map<int,pii> mp; 

pii u[N][N];
int ss[N][N];

void pr(int i, int j) { 
    if( i == -1 ) return; 
    cout << i+1 << ' ' << j << '\n';
    pr( u[i][j].F , u[i][j].S ); 
}


int main(){
    int n;
    cin >> n; 

    for(int i = 0; i < n; i++) 
        cin >> a[i]; 

    int best = 0; 
    pii bi; 

    for(int j = n; j > 0; j--) {
        int sum = 0; 
        for(int i = j-1; i >= 0; i--) { 
            sum += a[i]; 
            int v = 1;
            if( ans.count(sum) ) { 
                v += ans[sum]; 
                u[i][j] = mp[sum]; 
            } else 
                u[i][j] = pii(-1, -1);

            ss[i][j] = sum;
            dp[i][j] = v; 

            if( v > best ) { 
                best = v; 
                bi = pii(i, j); 
            }
        }

        int i = j-1; 
        for(int k = i+1; k <= n; k++) { 
            if( dp[i][k] > ans[ss[i][k]] ) {
                ans[ss[i][k]] = dp[i][k];
                mp[ss[i][k]] = pii(i, k); 
            }
        }
    }

    cout << best << endl; 
    pr( bi.F , bi.S ); 

    return 0;
}