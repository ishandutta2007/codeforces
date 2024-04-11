//In the name of Allah
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll; 
const int maxN = 3000 + 1; 

pii a[maxN];
pii b[maxN]; 
int nx[maxN],pr[maxN],v[maxN];
int r,c,n; 

inline int gg( int i ) { 
	pii x = {a[i].second,a[i].first};
	return lower_bound(b,b+n+2,x)-b;
}
inline int ff( int i ) { 
	return b[i].first; 
}

int nex( int i ) { 
	if( v[nx[i]] ) return nx[i];
	return nx[i] = nex(nx[i]); 
}
int prev( int i ) { 
	if( v[pr[i]] ) return pr[i]; 
	return pr[i] = prev(pr[i]);
}

int L[11],R[11];

int main() { 
	cin >> r >> c >> n;
	int k; cin >> k;
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i].first >> a[i].second; 
		b[i] = { a[i].second , a[i].first }; 
	}
	b[n] = { 0 , 0 } , b[n+1] = { c + 1 , 0 } ; 
	sort( a , a + n ); 
	sort( b , b + n + 2 ); 

	v[0] = v[n+1] = 1;  
	pr[0] = 0, nx[n+1] = n+1;
	ll ans = 0; 

	for( int i = 1 ; i <= r ; i++ ) { 
		int ind = 0; 
		for( ; ind < n && a[ind].first < i ; ind++ ); 
		if( ind == n ) break; 
		for( int j = ind ; j < n ; j++ ) 
			v[gg(j)] = 1; 
		for( int j = 1 ; j <= n ; j++ ) {
			nx[j] = j + 1;
			pr[j] = j - 1; 
		}

		int curr = 0;
		for( int j = 1 ; j <= n ; j++ ) if( v[j] ) { 
			int x = j; 
			for( int t = 1 ; t < k ; t++ , x = nex(x) );
			curr += (ff(j)- ff(prev(j)) ) * (c+1-ff(x));
		}

		int ptr = n; 
		for( int i2 = r ; i2 >= i ; i2-- ) { 
			ans += curr;
			for( ;ptr > ind && a[ptr-1].first >= i2; ptr-- ) { 
				L[0] = R[0] = gg(ptr-1);
				for( int t = 1 ; t < k ; t++ ) {
					L[t] = prev(L[t-1]);
					R[t] = nex(R[t-1]);
				}
				for( int t = 0 ; t < k ; t++ ) {
					int left = L[t]; 
					int right = R[k-t-1]; 
					curr -= (ff(left)-ff(prev(left))) * (ff(nex(right))-ff(right));
				}
				v[L[0]] = 0;
			}
		}
	}
	cout << ans << endl;
}