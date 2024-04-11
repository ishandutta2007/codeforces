//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 100 + 10; 
int a[maxN][maxN];
int dR[maxN], dC[maxN];

pair<int,int> v[maxN];

int main() { 
    int n,m; 
    cin >> n >> m; 
    for( int i = 0 ; i < n ; i++ ) 
        for( int j = 0 ; j < m ; j++ ) 
            cin >> a[i][j];

    for( int i = 0 ; i < n ; i++ ) { 
        for( int j = 0 ; j < m ; j++ ) { 
            if( !i ) 
                dC[j] = a[i][j] - a[i][0]; 
            else if( dC[j] != a[i][j] - a[i][0] ) { 
                cout << -1 << endl;
                return 0; 
            }
        }
    }
    for( int j = 0 ; j < m ; j++ ) { 
        for( int i = 0 ; i < n ; i++ ) { 
            if( !j ) 
                dR[i] = a[i][j] - a[0][j]; 
            else if( dR[i] != a[i][j] - a[0][j] ) { 
                cout << -1 << endl;
                return 0; 
            }
        }
    }
    int mnC = *(min_element( dC , dC + m )); 
    vector<pair<string,int>> ans; 
    for( int j = 0 ; j < m ; j++ ) 
        for( int k = 0 ; k < dC[j] - mnC ; k++ )
            ans.push_back( { "col" , j+1 } ); 

    int mnR = *(min_element( dR , dR + n )); 
    for( int i = 0 ; i < n ; i++ ) 
        for( int k = 0 ; k < dR[i] - mnR ; k++ )
            ans.push_back( { "row" , i+1 } ); 

    //cerr << mnC << " " << mnR << endl;
    int v = a[0][0] + mnC + mnR;
    if( v < 0 ) { 
        cout << -1 << endl;
        return 0; 
    }
    if( n < m ) 
        for( int i = 0 ; i < n ; i++ ) 
            for( int k = 0 ; k < v ; k++ ) 
                ans.push_back( { "row" , i + 1 } ); 
    else
        for( int i = 0 ; i < m ; i++ ) 
            for( int k = 0 ; k < v ; k++ ) 
                ans.push_back( { "col" , i + 1 } ); 
    cout << ans.size() << endl;
    for( auto x : ans ) 
        cout << x.first << ' ' << x.second << '\n';
}