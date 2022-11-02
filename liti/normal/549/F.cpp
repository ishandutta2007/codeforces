//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
const int maxN = 300 * 1000 + 10;

int n,k; 

pair<int,int> mx[4*maxN]; 
int a[maxN];
void mt( int xl = 0 , int xr = n , int ind = 1) { 
	if( xr - xl == 1 ) {
		mx[ind] = {a[xl],xl}; 
		return;
	}
	int xm = (xl+xr)>>1;
	mt( xl , xm , ind * 2 ) ; 
	mt( xm , xr , ind * 2 + 1 ) ; 
	mx[ind] = max(mx[ind*2],mx[ind*2+1]);
}

pair<int,int> gmax( int ql , int qr , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl )
		return {-1,-1}; 
	if( ql <= xl && xr <= qr ) 
		return mx[ind];
	int xm = (xl+xr)>>1; 
	pair<int,int> ret = {-1,-1} ; 
	ret = max( ret , gmax( ql , qr , xl , xm , ind * 2 ) ) ; 
	ret = max( ret , gmax( ql , qr , xm , xr , ind * 2 + 1 ) ) ; 
	return ret; 
}

int sumL[maxN] , sumR[maxN];
pair<int,int> l[maxN],r[maxN];
ll ans; 

void calc( int s , int e ) { 
	if( e - s <= 1 ) return;
	int mxi = gmax( s , e ).second ; 
	calc( s , mxi ) ; 
	calc( mxi + 1 , e ) ; 

//	cout << "BEG " << ans << ' ' << s << ' ' << e << ' ' << mxi << endl;
	if( mxi - s < e - (mxi+1) ) { 
		for( int i = s ; i <= mxi ; i++ ) {
			int ss = (sumL[mxi] - sumL[i] + k) % k; 
			ss = ( k - ss ) % k; 
			if( ss == 0 && i != mxi ) ans++; 
			ss = ( ss + sumL[mxi+1] ) % k; 
			ans += lower_bound( l , l + n , make_pair( ss , e ) ) 
			   - lower_bound( l , l + n , make_pair( ss , mxi + 1 ) ) ;	
		}
	} else { 
		for( int i = mxi ; i < e ; i++ ) { 
			int ss = (sumR[mxi] - sumR[i] + k) % k;
			ss = ( k - ss ) % k; 
			if( ss == 0 && i != mxi ) ans++; 
			ss = ( ss + sumR[mxi-1] ) % k; 
//			cout << ss << endl;
			ans += lower_bound( r , r + n , make_pair( ss , mxi ) ) - 
				lower_bound( r , r + n , make_pair( ss , s ) ) ; 
		}
	}
//	cout << "END " << ans << ' ' << s << ' ' << e << endl;
}

int main() { 
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cin >> n >> k;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i]; 
	mt(); 
	for( int i = 1 ; i < n ; i++ ) { 
		sumL[i] = (sumL[i-1] + a[i-1]) % k; 
		l[i-1] = { sumL[i] , i - 1 }; 
	}
	l[n-1] = { (sumL[n-1] + a[n-1]) %k , n-1 };
	for( int i = n - 2 ; i >= 0 ; i-- ) {
		sumR[i] = (sumR[i+1] + a[i+1]) % k;
		r[i+1] = { sumR[i] , i + 1 }  ; 
	}
	r[0] = { (sumR[0] + a[0]) %k , 0 };
	sort( l , l + n ) ; 
	sort( r , r + n ) ; 

	calc( 0 , n );
	cout << ans << endl;
}