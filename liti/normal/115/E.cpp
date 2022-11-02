//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 2 * 1000 * 100 + 100;

ll mx[4*maxN] , toadd[4*maxN];
ll dp[maxN],lp[maxN];
ll a[maxN];
int n,m; 

void shift( int ind ) { 
	mx[ind*2] += toadd[ind];
	mx[ind*2+1] += toadd[ind]; 
	toadd[ind*2] += toadd[ind];
	toadd[ind*2+1] += toadd[ind]; 
	toadd[ind] = 0 ; 
}
void addVal( int ql , int qr , ll v , int xl = 0 , int xr = n , int ind = 1 ) {
	if( xr <= ql || qr <= xl ) return;
	if( ql <= xl && xr <= qr ) { 
		mx[ind] += v; 
		toadd[ind] += v; 
		return;
	}
	shift(ind);
	int xm = (xl+xr)>>1;
	addVal( ql , qr , v , xl , xm , ind * 2 ) ; 
	addVal( ql , qr , v , xm , xr , ind * 2 + 1 ) ; 
	mx[ind] = max( mx[ind*2] , mx[ind*2+1]);
}
ll getMx( int ql , int qr , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return 0; 
	if( ql <= xl && xr <= qr ) return mx[ind];
	shift(ind);
	int xm = (xl+xr)>>1;
	return max(getMx(ql,qr,xl,xm,ind*2) , getMx(ql,qr,xm,xr,ind*2+1)) ;
}

vector<pair<int,int>> en[maxN];
int main() { 
	cin >> n >> m;
	n++;
	for( int i = 1 ; i < n; i++ ) 
		cin>> a[i];
	for( int i = 0 ; i < m ; i++ ) { 
		int l,r,x; cin >> l >> r >> x; 
		en[r].push_back( { l , x } ) ; 
	}
	for( int i = 1 ; i < n ; i++ ) { 
		addVal( i , i + 1 , getMx( 0 , i ) ) ; 
		for( auto x : en[i] ) 
			addVal( 0 , x.first , x.second ) ; 
		addVal( 0 , i , -a[i] ) ; 
	}
	cout << getMx( 0 , n ) << endl;
}