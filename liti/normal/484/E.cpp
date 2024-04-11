//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000*100 + 10; 
const int maxL = 22;

struct Seg { 
	Seg() { pref= suff = in = l = r = 0; } 
	int pref,suff,in;
	int l,r; 
};

Seg seg[maxN*maxL];
int root[maxN];
int a[maxN], H[maxN], hcnt;
vector<int> tmp[maxN];
int scnt;

int n; 
int add( int p , int id , int xl = 0 , int xr = n ) { 
	if( xr - xl == 1 ) { 
		seg[scnt].pref = seg[scnt].suff = seg[scnt].in = 1;
		return scnt++;
	}
	int xm = (xl+xr)/2; 
	int l = seg[id].l , r = seg[id].r; 
	if( p < xm ) 
		l = add( p , seg[id].l , xl , xm ) ; 
	else
		r = add( p , seg[id].r , xm , xr ) ; 
	auto& x = seg[scnt];
	x.l = l, x.r = r; 
	x.pref = seg[x.l].pref + ( seg[x.l].pref == xm - xl ? seg[x.r].pref : 0 ) ; 
	x.suff = seg[x.r].suff + ( seg[x.r].suff == xr - xm ? seg[x.l].suff : 0 ) ; 
	x.in = max( max(seg[x.l].in , seg[x.r].in) , seg[x.l].suff + seg[x.r].pref ); 
	return scnt++;
}
int get( int ql , int qr , int id , int xl = 0 , int xr = n ) { 
	if( xr <= ql || qr <= xl ) return 0; 
	if( ql <= xl && xr <= qr ) 
		return seg[id].in; 
	int xm = (xl+xr)/2;
	auto& x = seg[id];
	int ret = 0;
	if( ql < xm && xm < qr ) 
		ret = min(seg[x.l].suff,xm - ql) + min(seg[x.r].pref,qr-xm);
	ret = max( ret , get( ql , qr , x.l , xl , xm ) ) ; 
	ret = max( ret , get( ql , qr , x.r , xm , xr ) ) ; 
	return ret; 
}

int main() { 
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i];
		H[hcnt++] = a[i]; 
	}
	sort( H , H + hcnt ) ; 
	hcnt = unique( H , H + hcnt ) - H; 
	for( int i = 0 ; i < n ; i++ ) {
		a[i] = lower_bound( H , H + hcnt , a[i] ) - H; 
		tmp[a[i]].push_back(i);
	}
	scnt = 1;
	for( int i = hcnt - 1 ; i >=0 ; i-- ) {
		root[i] = root[i+1]; 
		for( auto x : tmp[i] ) 
			root[i] = add( x , root[i] ); 
	}
	int m; cin >> m;
	for( int i = 0 ; i < m ; i++ ) { 
		int l,r,w; 
		cin >> l >> r >> w; 
		l--;
		int s = 0 , e = hcnt;
		while( e - s > 1 ) { 
			int m = (s+e)/2;
//			cerr << l << ' ' << r << "   " << m << ' ' << get( l , r , root[m] ) << endl;
			if( get( l , r , root[m] ) >= w ) 
				s = m;
			else
				e = m;
		}
		cout << H[s] << '\n';
	}
}