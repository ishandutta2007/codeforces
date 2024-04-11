//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii;

int main() { 
    int ans = 0; 

    int n; cin >> n; 
    int mxL = -100; 
    int mnR = 1e9 + 100; 
    for( int i = 0 ; i < n ; i++ ) { 
        int l,r; 
        cin >> l >> r; 
        mxL = max(mxL,l); 
        mnR = min(mnR,r); 
    }

    int m; cin >> m; 
    for( int i = 0 ; i < m ; i++ ) { 
        int l,r; 
        cin >> l >> r; 
        if( mnR <= l ) 
            ans = max( ans , l - mnR ); 
        if( r <= mxL ) 
            ans = max( ans , mxL - r ); 
    }
    cout << ans << endl;

}