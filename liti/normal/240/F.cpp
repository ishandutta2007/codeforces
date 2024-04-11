//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    
const int maxN = 1000*100 + 10; 
const int maxK = 26; 
typedef int Seg[4*maxN];
Seg sum[maxK],toadd[maxK];
int n,m; 
int cnt[maxK];

inline void shift( int id , int xl , int xm , int xr , int ind ) { 
	if( toadd[id][ind] == -1 ) return;
	toadd[id][ind*2] = toadd[id][ind*2+1] = toadd[id][ind];
	sum[id][ind*2] = toadd[id][ind] * (xm - xl);
	sum[id][ind*2+1] = toadd[id][ind] * (xr - xm); 
	toadd[id][ind] = -1;
}

inline void update( int id , int ind ) { 
	sum[id][ind] = sum[id][ind*2] + sum[id][ind*2+1]; 
}

void sVal( int ql , int qr , int v , int id , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( ql <= xl && xr <= qr ) { 
		sum[id][ind] = (xr-xl)*v; 
		toadd[id][ind] = v; 
		return;
	}
	int xm = (xl+xr)>>1;
	shift( id,  xl , xm , xr , ind ) ; 
	if( ql < xm ) 
		sVal( ql , qr , v , id , xl , xm , ind * 2 ) ; 
	if( qr > xm ) 
		sVal( ql , qr , v , id , xm , xr , ind * 2 + 1 ) ; 
	update( id , ind ) ; 
}
int gVal( int ql , int qr , int id , int xl = 0 , int xr = n , int ind = 1 ) { 
	if( ql <= xl && xr <= qr ) return sum[id][ind]; 
	int xm = (xl+xr)>>1; 
	shift( id , xl , xm , xr , ind ) ; 
	int ret = 0;
	if( ql < xm ) 
		ret = gVal( ql , qr , id , xl , xm , ind * 2 ) ; 
	if( qr > xm ) 
		ret += gVal( ql , qr , id , xm , xr , ind * 2 + 1 ) ; 
	update( id , ind ) ; 
	return ret;
}

int main() { 
#ifdef ONLINE_JUDGE 
	freopen( "input.txt" , "r" , stdin ) ; 
	freopen( "output.txt" , "w" , stdout ) ; 
#endif
	memset( toadd , -1 , sizeof toadd ); 
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	string s; 
	cin >> s; 
	for( int i = 0 ; i < n ; i++ ) 
		sVal( i , i + 1 , 1 , s[i] - 'a' ) ; 
	for( int i = 0 ; i < m ; i++ ) { 
		int l , r; 
		cin >> l >> r; l--; 
		int odd = 0;
		for( int id = 0 ; id < maxK ; id++ ) {
			cnt[id] = gVal( l , r , id ) ; 
			if( cnt[id] & 1 ) odd++; 
		}
		if( odd > 1 ) continue;
		int ql = l , qr = r;
		for( int id = 0 ; id < maxK ; id++ ) if( cnt[id] ) {
			sVal( l , r , 0 , id ) ; 
			int f = cnt[id] >> 1; 
			if( f ) { 
				sVal( ql , ql + f , 1 , id ) ; 
				sVal( qr - f , qr , 1 , id ) ; 
			}
			ql += f; 
			qr -= f; 
			if( cnt[id] & 1 ) 
				sVal( (ql+qr)/2 , (ql+qr)/2 + 1 , 1 , id ) ; 
		}
	}
	for( int i = 0 ; i < n ; i++ ) 
		for( int id = 0 ; id < 26 ; id++ ) 
			if( gVal( i , i + 1 , id ) == 1 ) {
				s[i] = 'a' + id; 
				break;
			}
	cout << s << endl;
}