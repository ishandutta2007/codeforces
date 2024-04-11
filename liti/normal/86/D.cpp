/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 2000*100 + 100;
const int maxK = 500 + 10; 

struct Que { 
	int l,r,i;
} que[maxN];
bool cmp( Que a , Que b ) { 
	int f1 = a.l / maxK , f2 = b.l / maxK;
	if( f1 != f2 ) 
		return f1 < f2 ; 
	return a.r < b.r; 
}

int a[maxN];
ll ans[maxN];

int cnt[5*maxN];
ll currVal ; 

inline void addV( int ind ) { 
	currVal += ll(a[ind]) * ( 2*cnt[a[ind]] + 1 ) ;
	cnt[a[ind]]++;
}
inline void remV( int ind ) { 
	currVal += ll( a[ind] ) * ( -2*cnt[a[ind]] + 1 ) ;
	cnt[a[ind]]--;
}

int main() { 
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;

	for( int i =0 ; i < n ; i++ ) 
		cin >> a[i];
	for( int i = 0 ; i < m ; i++ ) {
		cin >> que[i].l >> que[i].r ;
		que[i].l--;
		que[i].i = i;
	}
	sort( que , que + m , cmp );

	int l = 0 , r = 0;
	for( int i = 0 ; i < m ; i++ ) { 
		if( r > que[i].r ) 
			for( ; r > que[i].r ; r-- ) 
				remV( r-1 ) ; 
		else
			for( ; r < que[i].r ; r++ ) 
				addV( r ) ; 
		if( l < que[i].l ) 
			for( ; l < que[i].l ; l++ ) 
				remV(l);
		else
			for( ; l > que[i].l ; l-- ) 
				addV(l-1);
		ans[que[i].i] = currVal;
	}

	for( int i = 0 ; i < m ; i++ ) 
		cout << ans[i] << '\n';
}