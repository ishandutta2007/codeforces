/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 2000*100 + 10; 

ll d[maxN];
int h[maxN];

ll val[2][maxN];
int seg[2][4*maxN];
pair<int,int> best[4*maxN];
int n,m; 

bool cmp( pair<int,int> a , pair<int,int> b ) { 
	if( a.first == -1 ) return 1;
	if( b.first == -1 ) return 0;
	ll v1 = val[0][a.first] + val[1][a.second];
	ll v2 = val[0][b.first] + val[1][b.second];
	return ( v1 < v2 ) ; 
}

void make_seg( int xl = 0 , int xr = 2*n , int ind = 1 ) { 
	if( xr - xl == 1 ) { 
		seg[0][ind] = seg[1][ind] = xl;
		best[ind] = {-1,-1};
		return;
	}

	int xm = (xl+xr) / 2;
	make_seg( xl , xm , ind * 2 + 0 ) ; 
	make_seg( xm , xr , ind * 2 + 1 ) ; 

	best[ind] = { seg[0][ind*2+0] , seg[1][ind*2+1] } ;
	if( xm - xl > 1 && cmp( best[ind] , best[2*ind] ) ) 
		best[ind] = best[2*ind];
	if( xr - xm > 1 && cmp( best[ind] , best[2*ind+1] ) )
		best[ind] = best[2*ind+1];

	if( val[0][seg[0][2*ind]] > val[0][seg[0][2*ind+1]] ) 
		seg[0][ind] = seg[0][2*ind];
	else
		seg[0][ind] = seg[0][2*ind+1];

	if( val[1][seg[1][2*ind]] > val[1][seg[1][2*ind+1]] ) 
		seg[1][ind] = seg[1][2*ind];
	else
		seg[1][ind] = seg[1][2*ind+1];

//	cout << "DBG " << xl << ' ' << xr << ' ' << ind<< endl;
//	cout << best[ind].first << ' ' << best[ind].second<< endl;
}

int getMax( int ql , int qr , int id , int xl = 0 , int xr = 2*n , int ind = 1 ) { 
	if( ql <= xl && xr <= qr ) 
		return seg[id][ind];
	int xm = (xl+xr)/2;
	int f = -1 , s = -1;
	if( ql < xm ) 
		f = getMax( ql , qr , id , xl , xm , ind * 2 ) ; 
	if( qr > xm ) 
		s = getMax( ql , qr , id , xm , xr , ind * 2 + 1 ) ; 
	if( f == -1 || s == -1 ) 
		return max(s,f);
	if( val[id][f] > val[id][s] ) 
		return f;
	return s;
}


pair<int,int> get( int ql, int qr , int xl = 0 , int xr = 2*n , int ind = 1 ) { 
	if( ql <= xl && xr <= qr ) 
		return best[ind];
	int xm = (xl+xr) / 2;
	
	pair<int,int> a, b, c = b = a = {-1,-1} ; 
	if( ql < xm ) 
		a = get( ql , qr , xl , xm , ind * 2 ) ; 
	if( qr > xm ) 
		b = get( ql , qr , xm , xr , ind * 2 + 1 )  ;

	if( ql < xm && qr > xm ) 
		c = { getMax( ql , xm , 0 ) , getMax( xm , qr , 1 ) } ; 
	
//	cout << xl << ' ' << xm<< ' ' << xr << "  " << a.first << ' ' << a.second << "  " << b.first << ' ' << b.second << 
//		"  " << c.first << ' ' << c.second<< endl;

	if( cmp(a,b) ) 
		a = b;
	if( cmp(a,c) ) 
		a = c;

	return a;
}


int main() {
	cin >> n >> m;
	for( int i = 0 ; i < n ; i++ )
		cin >> d[i] , d[i+n] = d[i];
	for( int i = 0 ; i < n ; i++ )
		cin >> h[i] , h[i+n] = h[i];

	ll f = 0;
	for( int i = 0 ; i < 2*n ; i++ ) {
		val[0][i] = f + 2ll*h[i];
		f -= d[i];
	}
	f = 0;
	for( int i = 2*n - 1 ; i > 0 ; i-- ) { 
		val[1][i] = f + 2ll*h[i];
		f -= d[i-1];
	}

	for( int i = 1  ; i < 2*n ; i++ ) 
		d[i] += d[i-1];

	make_seg() ; 

	for( int i = 0 ; i < m ; i++ ) { 
		int a,b; cin >> a >> b; 
		swap(a,b);
		b--;
		if( b <= a ) b += n;
//		cout << a << ' ' << b << endl;
		pair<int,int> x = get( a , b ) ;
//		cerr << x.first << ' ' << x.second << endl;
		cout << h[x.first]*2ll + h[x.second]*2ll + d[x.second-1] - (x.first?d[x.first-1]:0) << endl;
	}
}