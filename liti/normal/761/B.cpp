//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000 + 10; 
int a[maxN],b[maxN];

int main() { 
    int n,l; cin >> n >> l; 
    for( int i  =0 ; i < n ; i++ ) 
        cin >> a[i];
    for( int i  =0 ; i < n ; i++ ) 
        cin >> b[i];
    for( int i = 0 ; i < 1 ; i++ ) 
        for( int j = 0 ; j < n ; j++ ) { 
            int diff = ( a[i] - b[j] + l ) % l;
            bool canDo = true;
            for( int k = 1 ; k < n ; k++ ) 
                if( ( a[(i+k)%n] - b[(j+k)%n] + l ) % l != diff ) 
                    canDo = false;
            if( canDo ) {
                cout << "YES" << endl;
                return 0; 
            }
        }
    cout << "NO" << endl;
}