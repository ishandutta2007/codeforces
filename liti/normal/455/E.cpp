//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000 * 100 + 10; 
const int maxK = 4 * maxN;
int addz[maxK], addsum[maxK];
int n; 

void shift( int t , int ind ) { 
	if( addz[ind] == -1 ) { 
		addsum[ind*2] += addsum[ind];
		addsum[ind*2+1] += addsum[ind];
	} else { 
		addz[ind*2] = addz[ind];
		addsum[ind*2] = addsum[ind];
		addz[ind*2+1] = addz[ind];
		addsum[ind*2+1] = addsum[ind] + t*addz[ind];
	}
	addz[ind] = -1;
	addsum[ind] = 0;
}

void addVal( int ql , int qr , int v , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return; 
	if( ql <= xl && xr <= qr ) { 
		addsum[ind] += v; 
		return;
	}
	int xm = (xl+xr)>>1;
	shift( xm - xl , ind ) ; 
	addVal( ql , qr , v , xl , xm , ind * 2 ) ; 
	addVal( ql , qr , v , xm , xr , ind * 2 + 1 ) ; 
}

void setVal( int ql , int qr , int v , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) return; 
	if( ql <= xl && xr <= qr ) { 
		addz[ind] = v;
		addsum[ind] = (xl-ql+1)*v;
		return;
	}
	int xm = (xl+xr)>>1;
	shift( xm - xl , ind ) ; 
	setVal( ql , qr , v , xl , xm , ind*2 ) ; 
	setVal( ql , qr , v , xm , xr , ind * 2  +1 ) ; 
}

int getVal( int p , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr - xl == 1 ) 
		return addsum[ind];
	int xm = (xl+xr)>>1;
	shift( xm - xl , ind ) ; 
	if( p < xm ) 
		return getVal( p , xl , xm , ind * 2 ) ; 
	return getVal( p , xm , xr , ind * 2 + 1 ) ; 
}

vector<pair<int,int>> q[maxN];
int ans[maxN];
int a[maxN];
int main() { 
	memset( addz , -1 , sizeof addz ) ; 
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i];
	int m; cin >> m;
	for( int i = 0 ; i < m ; i++ ) { 
		int x,j;
		cin >> x >> j; 
		j--; x--;
		q[j].push_back( { n - j - 1 + x , i } ) ; 
	}
	for( int i = 0 ; i < n ; i++ ) { 
		addVal( n - i - 1 , n , a[i] ) ;
		int s = n - i - 1 , e = n; 
		while( e - s > 1 ) { 
			int m = (s+e)/2;
			if( (m-(n-i-1)+1)*a[i] <= getVal( m ) ) 
				s = m; 
			else
				e = m;
		}
		setVal( n - i - 1 , e , a[i] );
		for( auto x : q[i] ) 
			ans[x.second] = getVal( x.first ) ; 
	}
	for( int i = 0 ; i < m ; i++ ) 
		cout << ans[i] << '\n';
}