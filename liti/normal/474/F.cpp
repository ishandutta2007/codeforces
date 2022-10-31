/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000*100 + 10; 
const int maxL = 20 ; 

int mn[maxN][maxL], cnt[maxN][maxL];
int gg[maxN][maxL];
int a[maxN];

int main() { 
	int n;
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i];
		gg[i][0] = a[i];
		cnt[i][0] = 1;
		mn[i][0] = a[i];
	}

	for( int j = 1 ; j < maxL ; j++ ) 
		for( int i =0 ; i < n ; i++ ) {
			if( i + (1<<j) >= maxN ) continue;
			gg[i][j] = __gcd(gg[i][j-1],gg[i + (1<<(j-1))][j-1] ) ; 
			if( mn[i][j-1] < mn[i+(1<<(j-1))][j-1] ) 
				cnt[i][j] = cnt[i][j-1];
			else if ( mn[i][j-1] > mn[i+(1<<(j-1))][j-1] ) 
				cnt[i][j] = cnt[i+(1<<(j-1))][j-1];
			else { 
		//		cout << "PA " << i << ' ' << j << endl;
				cnt[i][j] = cnt[i][j-1] + cnt[i+(1<<(j-1))][j-1] ; 
			}
			mn[i][j] = min( mn[i][j-1] , mn[i + (1<<(j-1))][j-1] ) ; 
		}

	int m; cin >> m;

	for( int t = 0 ; t < m ; t++ ) { 
		int l,r;
		cin >> l >> r;
		l--;
		int tmp = l;
		int g = a[l];
		int x = 1e9 + 7, c = 0;
		for( int i = maxL - 1 ; i >= 0 ; i-- ) 
			if( l + (1<<i) <= r ) { 
	//			cout << l << ' ' << x << ' ' << c << ' ' << g << endl;
				g = __gcd(g,gg[l][i]); 
				if( mn[l][i] < x ) 
					c = 0; 
				if( mn[l][i] <= x ) {
					x = mn[l][i];
					c += cnt[l][i];
				}
				l += (1<<i); 
	//			cout << l << ' ' << x << ' ' << c << ' ' << g << endl;
			}
		l = tmp;
	//	cerr << g << ' ' << x << ' ' << c << ' ' << r << ' ' << l << endl;
		if( g % x == 0 ) 
			cout << r - l - c << endl;
		else
			cout << r - l << endl;
	}

//	cout << cnt[3][1] << ' ' << mn[3][1] << ' ' << 
//		cnt[3][0] << ' ' << mn[3][0] << endl;
}