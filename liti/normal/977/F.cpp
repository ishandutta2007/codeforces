//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 1000 * 1000 + 10; 
map<int,int> last; 
int dp[maxN], u[maxN], a[maxN];

void pr(int v) { 
    if( v == -1 ) 
        return;
    pr( u[v] ); 
    cout << v + 1 << " ";
}

int main() { 
    ios::sync_with_stdio(false); cin.tie(0); 

    int n;
    cin >> n;

    pair<int,int> best = { 1, 0 } ; 

    for(int i = 0 ; i < n; i++ ) { 
        cin >> a[i];
        if( last.count(a[i]-1) ) { 
            dp[i] = dp[last[a[i]-1]] + 1; 
            u[i] = last[a[i]-1];
        } else { 
            dp[i] = 1;
            u[i] = -1; 
        }
        last[a[i]] = i;
        best = max(best, make_pair(dp[i], i)); 
    }

    cout << best.first << endl;
    pr( best.second );
}