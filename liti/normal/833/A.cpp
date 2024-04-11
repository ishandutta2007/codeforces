//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int,int> pii; 

int gg( ll v ) { 
    int s = 0 , e = 1000*1000 + 10; 
    while( e - s > 1 ) { 
        int m = (s+e) / 2; 
        if( 1ll * m * m * m <= v ) 
            s = m;
        else
            e = m; 
    }
    if( 1ll * s * s * s != v ) return -1;
    return s; 
}

int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int t; cin >> t; 

    for( int i = 0 ; i < t ; i++ ) { 
        int a, b; 
        cin >> a >> b; 
        
        ll c = a * 1ll * b; 
        int sq = gg(c);
        if( sq == -1 || __gcd(1ll*a*a,1ll*b) != b ||
            __gcd(1ll*b*b,1ll*a) != a ) 
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}