//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 2*1000*100 + 100; 
const int inf = 1e9 + 2000;
pair<int,int> mn[4*maxN];
int a[maxN];
int n;
void mt( int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr - xl == 1 ) { 
		mn[ind] = { a[xl] , xl } ; 
		return;
	}
	int xm = (xl+xr)/2;
	mt( xl , xm , ind * 2 ) ; 
	mt( xm , xr , ind * 2 + 1 ) ; 
	mn[ind] = min( mn[ind*2] , mn[ind*2+1] ) ; 
}
pair<int,int> gmn( int ql , int qr , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( xr <= ql || qr <= xl ) 
		return {inf,n}; 
	if( ql <= xl && xr <= qr ) 
		return mn[ind]; 
	int xm = (xl+xr)/2;
	pair<int,int> ret = gmn( ql , qr , xl , xm , ind * 2 ) ; 
	ret = min(ret,gmn(ql,qr,xm,xr,ind*2+1));
	return ret;
}

int ans[maxN];
void smin(int&a,int b) { a = min(a,b); } ; 
void smax(int&a,int b) { a = max(a,b); } ; 
void solve( int s , int e ) { 
	if( e - s == 0 ) return;
	int mni = gmn( s , e ).second;
	smax(ans[e - s],a[mni]);
	solve( s , mni ) ; 
	solve( mni + 1 , e ) ; 
}

int main() {
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i];
	mt();
	solve(0,n); 
	for( int i = n - 1 ; i >= 0 ; i-- ) 
		smax( ans[i] , ans[i+1] ) ;
	for( int i = 1 ; i<= n ; i++ ) {
		cout <<ans[i] << ' ' ;
	}
	cout << endl;
}