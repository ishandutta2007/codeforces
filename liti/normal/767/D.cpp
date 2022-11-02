//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef pair<int,int> pii; 

const int maxN = 2000 * 1000 + 10; 

int a[maxN], b[maxN]; 
pair<int,int> c[maxN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,k; 
    cin >> n >> m >> k;
    for( int i = 0 ; i < n ; i++ ) { 
        int x; cin >> x;
        c[i] = { x , 0 }; 
    }

    for( int i = 0 ; i < m ; i++) { 
        int x; cin >> x;
        c[i+n] = { x , i+1 } ; 
    }

    sort( c , c + m + n ); 

    int s = -1 , e = m + 1; 
    while( e - s > 1 ) { 
        int mid = (e+s)/2; 
        int cnt = 0; 

        int last = 1000 * 1000 * 100; 
        int rem = 0; 
        for( int i = n + m - 1 ; i >= 0 ; i-- ) { 
            if( c[i].second ) { 
                if( cnt < mid ) 
                   cnt++;
               else
                   continue;
            }

            int v = c[i].first;
            int diff = last - v; 
            rem = max( 0ll, rem - diff * 1ll * k ); 
            rem++; 

            last = v; 
        }
        rem = max( 0ll , rem - (last+1) * 1ll * k ); 
        if( rem > 0 ) 
            e = mid;
        else
            s = mid;
    }
    cout << s << endl;
    if( s != -1 ) 
        for( int i = n + m - 1 , v = s ; i >= 0 && v > 0  ; i-- )
            if( c[i].second ) { 
                cout << c[i].second << " "; 
                v--; 
            }
}