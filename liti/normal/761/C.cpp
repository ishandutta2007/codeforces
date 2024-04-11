//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 50 + 2; 
int a[maxN][5]; 
string s[maxN];

void smin( int& a , int b ) { 
    a = min(a,b);
}

int main() { 
    int n, m; cin >> n >> m;
    memset( a , 33 , sizeof a ); 

    for( int i = 0 ; i < n ; i++ ) { 
        cin >> s[i]; 
        for( int j =0 ; j < m ; j++ ) 
            if( islower(s[i][j]) ) 
                smin( a[i][0] , min( j , m - j ) );  
            else if( isdigit(s[i][j]) ) 
                smin( a[i][1] , min( j , m - j ) );  
            else if( s[i][j] == '#' || s[i][j] == '*' || s[i][j] == '&' ) 
                smin( a[i][2] , min( j , m - j ) );
    }
    int ans = 1e9;
    for( int i = 0 ; i < n ; i++ ) 
        for( int j = 0 ; j < n ; j++ ) if( i != j ) 
            for( int k = 0 ; k < n ; k++ ) if( i != k && j != k ) 
                smin(ans,a[i][0]+a[j][1]+a[k][2]);
    cout << ans << endl;
}