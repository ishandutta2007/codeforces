/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxK = 2e6 + 10;
const int maxN = 2e5 + 10;

int a[maxN];
int seen[maxK];

int main() { 
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) 
        cin >> a[i];
    sort( a , a + n ) ; 
    n = unique(a , a + n ) - a ;

    int ret = 0;
    for( int i = 0 ; i < n; i++ ) { 
        if( seen[a[i]] ) continue;
        seen[a[i]] = true;
        for( int j = a[i] + a[i] ; j < maxK ; j+= a[i] ) { 
            int x = *(lower_bound( a , a + n , j )-1) ;
            if( x >= a[i] ) 
                ret = max( ret, x % a[i] ) ;
        }
    }
    cout << ret << endl;
}