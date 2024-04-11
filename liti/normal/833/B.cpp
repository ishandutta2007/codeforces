//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 35000 + 10; 
const int maxK = 50 + 5; 
const int inf = 1e9;

typedef pair<int,int> pii;

int dp[maxN][maxK]; 

int a[maxN]; 
int last[maxN]; 
int N; 

int seg[4*maxN][maxK]; 
int toadd[4*maxN]; 

void addVal( int ql , int qr , int v , int xl = 0 , int xr = N , int ind = 1 ) { 
    if( xr <= ql || qr <= xl ) 
        return; 
    if( ql <= xl && xr <= qr ) { 
        toadd[ind] += v;
        return; 
    }

    int xm = (xl+xr)/2;
    addVal( ql , qr , v , xl , xm , ind * 2 ); 
    addVal( ql , qr , v , xm , xr , ind * 2 + 1 ); 

    for( int k = 0 ; k < maxK ; k++ ) 
        seg[ind][k] = max( seg[ind*2][k] + toadd[ind*2] , 
                seg[ind*2+1][k] + toadd[ind*2+1] ); 
}

int getVal( int ql , int qr , int qk , int xl = 0 , int xr = N , int ind = 1 ) { 
    if( xr <= ql || qr <= xl ) 
        return -inf; 
    if( ql <= xl && xr <= qr ) 
        return seg[ind][qk] + toadd[ind]; 

    int xm = (xl+xr)/2;
    return max( getVal(ql, qr, qk, xl, xm, ind * 2) , 
           getVal(ql, qr, qk, xm, xr, ind * 2 + 1 ) ) + toadd[ind]; 
} 

void setVal( int qp , int xl = 0 , int xr = N , int ind = 1 ) { 
    if( xr - xl == 1 ) { 
        for( int k = 0 ; k < maxK ; k++ ) { 
            seg[ind][k] = dp[qp][k]; 
        }
        return;
    }
    int xm = (xl+xr)/2; 
    if( qp < xm ) 
        setVal( qp , xl , xm , ind * 2 );
    else
        setVal( qp , xm , xr , ind * 2 + 1 ); 

    for( int k = 0 ; k < maxK ; k++ ) 
        seg[ind][k] = max( seg[ind*2][k] + toadd[ind*2] , 
                seg[ind*2+1][k] + toadd[ind*2+1] ); 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    memset( seg , -63 , sizeof seg );

    int n, m; 
    cin >> n >> m; 
    N = n + 1;

    setVal(0);
    for( int i = 1 ; i <= n ; i++ ) { 
        cin >> a[i-1];
        a[i-1]--; 

        addVal( last[a[i-1]] , i , 1 ); 
        last[a[i-1]] = i;
        for( int k = 1 ; k <= m ; k++ )
            dp[i][k] = getVal( 0 , i , k-1 ); 
        
        setVal( i ); 
    }

    cout << dp[n][m] << endl;
}