#include <iostream>
using namespace std;

int a[101];
int main() { 
    int n;
    cin >> n ;
    
    for( int i =0 ; i < n ;i++ )
        cin >> a[i];
    
    int ans = 0;
    for( int i = 0 ; i < n ; i++ )
        for( int j = i ; j < n ; j++ ) {
            int cnt = 0;
            for( int k = 0 ; k < n ;k++ ) 
                if( k < i || k > j ) 
                    cnt += (a[k]==1);
                else
                    cnt += (a[k]==0);
            ans = max( ans, cnt ); 
        }
    cout << ans << endl;
}