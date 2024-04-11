//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 100 + 10; 
int a[maxN]; 

int main() { 
    int n; cin >> n; 
    int sum = 0; 
    for( int i = 0 ; i < n ; i++ ) { 
        cin >> a[i]; 
        sum += a[i]; 
    }
    if( sum != 0 ) { 
        cout << "YES" << endl;
        cout << 1 << endl << "1 " << n << endl;
        return 0; 
    }
    int psum = 0; 
    for( int i = 0 ; i < n ; i++ ) { 
        psum += a[i]; 
        if( psum != 0 ) { 
            cout << "YES" << endl;
            cout << 2 << endl << "1 " << i + 1 << endl << 
                i + 2 << " " << n << endl;
            return 0; 
        }
    }
    cout << "NO" << endl;
}