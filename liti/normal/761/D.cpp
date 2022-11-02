//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 100 * 1000 + 100; 
int a[maxN], b[maxN], ord[maxN]; 

int main() { 
    ios::sync_with_stdio(false); cin.tie(0); 
    int n,l,r; cin >> n >> l >> r; 

    for( int i = 0 ; i < n ; i++ ) 
        cin >> a[i]; 
    for( int i = 0 ; i < n ; i++ ) { 
        int x; cin >> x; 
        ord[x-1] = i; 
    }

    int l2 = -1e9; 
    for( int tt = 0 ; tt < n ; tt++ ) { 
        int i = ord[tt]; 
        //b[i] > l1
        //b[i] - a[i] > l2
        b[i] = max( l , a[i] + l2 + 1 ); 
        l2 = b[i] - a[i]; 
        if( b[i] > r ) { 
            cout << -1 << endl;
            return 0; 
        }
    }
    for(int i=0 ; i < n ; i++ ) 
        cout << b[i] << " " ; 
    cout << endl;

}