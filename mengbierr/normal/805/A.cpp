#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int l , r ;

void input ( ) {
    scanf ( "%d%d" , &l , &r ) ;
}

void solve ( ) {
    if ( l == r ) { printf ( "%d\n" , l ) ; return ; }
    int i ;
    int mx = -1 ;
    int id = -1 ;
    for ( i = 2 ; i <= 1000000 ; i ++ ) {
        int u = ( r / i ) - ( ( l - 1 ) / i ) ;
        if ( mx < u ) {
            mx = u ;
            id = i ;
        }
    }
    printf ( "%d\n" , id ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}