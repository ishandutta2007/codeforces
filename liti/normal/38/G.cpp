//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
 
const int maxN = 1000*100 + 100;
vector<pair<int,int>> a[maxN];
set<pair<int,int>> curr;
 
int mx[4*maxN];
int n;
void smax( int p , int v , int xl = 0 , int xr = n, int ind = 1 ) {
    if( xl == p && xr == p + 1 ) {
        mx[ind] = v;
        return;
    }
    int xm = ( xl + xr) / 2;
    if( p < xm )
        smax( p , v , xl , xm , ind * 2 + 0 ) ;
    else
        smax( p , v , xm , xr , ind * 2 + 1 ) ;
    mx[ind] = max( mx[2*ind], mx[2*ind+1] ) ;
}
int xmax( int ql , int qr , int xl = 0 , int xr = n , int ind = 1 ) {
    if( ql == xl && xr == qr )
        return mx[ind];
    int xm = ( xl + xr ) /2;
    int ret = 0;
    if( ql < xm )
        ret = max( ret , xmax( ql , min(qr,xm) , xl , xm , ind * 2 + 0 ) );
    if( qr > xm )
        ret = max( ret , xmax( max(ql,xm) , qr , xm , xr , ind * 2 + 1 ) );
    return ret;
}
 
int fen[maxN];
int tmp[maxN];
int fget( int x , int v = 0 ) {
    for( ; x > 0 ; x -= x & (-x) )
        v += fen[x];
    return v;
}
void fset( int x ) {
    for( ; x < maxN ; x += x & (-x) )
        fen[x]++;
}
 
int main() {
    cin >> n;
 
    for( int i = 0 ; i< n ;i++ ) {
        int hurry, haya;
        cin >> hurry >> haya;
        int val = xmax( hurry - 1 , n ) ;
        int p = max( i - haya , val ) ;
        smax( hurry - 1 , p ) ;
        tmp[i] = p;
        a[max(0,p)].push_back( {-hurry,i} ) ;
    }
    memset( mx , 0 , sizeof mx );
    for( int i = 0 ; i < n ; i++ ) {
        for( int j = 0 ; j < (int)a[i].size() ; j++ ) {
            smax( a[i][j].second , -a[i][j].first ) ;
            curr.insert( a[i][j] ) ;
        }
        while( 1 ) {
            auto it = curr.begin();
            int s = it->second;
            int x = fget( s + 1 );
            if( x >= tmp[s] && xmax(0,s+1) <= -it->first ) {
                cout << s + 1 << ' ';
                smax( s , 0 ) ;
                fset( s + 1 );
                curr.erase(it) ;
                break;
            } else {
                if( x < tmp[s] ) {
                    a[i+tmp[s]-x].push_back(*it);
                } else
                    a[i+2].push_back(*it);
                curr.erase(it);
            }
        }
    }
    cout << endl;
}