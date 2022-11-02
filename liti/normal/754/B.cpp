
//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

int n = 4; 
string a[4]; 

bool canDo() { 
    for( int i = 0 ; i + 3 <= n ; i++ ) 
        for( int j = 0 ; j < n ; j++ ) 
            if( a[i][j] == a[i+1][j] && a[i+2][j] == a[i][j] && 
                    a[i][j] == 'x' ) 
                return true; 
    for( int i = 0 ; i < n ; i++ ) 
        for( int j = 0 ; j + 3 <= n ; j++ ) 
            if( a[i][j] == a[i][j+1] && a[i][j+2] == a[i][j] && 
                    a[i][j] == 'x' ) 
                return true; 
    for( int i = 0 ; i + 3 <= n ; i++ ) 
        for( int j = 0 ; j + 3 <= n ; j++ ) 
            if( a[i][j] == a[i+1][j+1] && a[i+2][j+2] == a[i][j] && 
                    a[i][j] == 'x' ) 
                return true; 

    for( int i = 2 ; i < 4 ; i++ ) 
        for( int j = 0 ; j + 2 <= 4 ; j++ ) 
            if( a[i][j] == a[i-1][j+1] && a[i-2][j+2] == a[i][j] && 
                    a[i][j] == 'x' ) 
                return true; 
    return false;
}

int main() { 
    for( int i = 0 ; i < n ; i++ ) 
        cin >> a[i]; 

    for( int i = 0 ; i < n ; i++ ) 
        for( int j = 0 ; j < n ; j++ ) { 
            if( a[i][j] == '.' ) { 
                a[i][j] = 'x'; 
                if( canDo() ) { 
                    cout << "YES" << endl;
                    return 0; 
                }
                a[i][j] = '.'; 
            }
        }
    cout << "NO" << endl;
}