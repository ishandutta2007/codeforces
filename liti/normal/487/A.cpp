/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;
#define sz(x) (((int) x.size()))

int main() { 
	int hy,ay,dy;
	int hm, am, dm;
	int h,a,d;
	cin >> hy >> ay >> dy;
	cin >> hm >> am >> dm;
	cin >> h >> a >> d;

	// t1 = hm / ( ay - dm ) 
	// t2 = hy / ( am - dy ) 
	// t1 < t2
	//
	// ( hm ) * ( am - dy ) < ( hy ) * ( ay - dm ) 

	int ans = 0;
	if( ay - dm <= 0 ) { 
		ans = ( 1 - ( ay - dm ) )*a;
		ay = dm + 1;
	} 

	if( am - dy <= 0 ) {
		cout << ans << endl;
		return 0;
	}

	int best = ans + 1e7 ; 

	for( int i = ay ; i < ay + 1000 ; i++ ) 
		for( int j = dy ; j < dy + 200 ; j++ ) 
			for( int k = hy ; k < hy + 200 ; k++ ) { 
	//			if( k == 100 && j == dy && i == ay ) cout <<  ( hm + i - dm - 1 ) / ( i - dm ) << ' ' << 
	//				( k + am - j - 1 ) / ( am - j )  << endl;
				if( am - j <= 0 || ( hm + i - dm - 1 ) / ( i - dm ) < ( k + am - j - 1 ) / ( am - j ) ) 
					best = min( best, ans + ( i - ay ) * a + ( j - dy ) * d + ( k - hy ) * h ) ;
			}
	for( int i = ay ; i < ay + 200 ; i++ ) 
		for( int j = dy ; j < dy + 1000 ; j++ ) 
			for( int k = hy ; k < hy + 200 ; k++ ) { 
	//			if( k == 100 && j == dy && i == ay ) cout <<  ( hm + i - dm - 1 ) / ( i - dm ) << ' ' << 
	//				( k + am - j - 1 ) / ( am - j )  << endl;
				if( am - j <= 0 || ( hm + i - dm - 1 ) / ( i - dm ) < ( k + am - j - 1 ) / ( am - j ) ) 
					best = min( best, ans + ( i - ay ) * a + ( j - dy ) * d + ( k - hy ) * h ) ;
			}
	for( int i = ay ; i < ay + 200 ; i++ ) 
		for( int j = dy ; j < dy + 200 ; j++ ) 
			for( int k = hy ; k < hy + 1000 ; k++ ) { 
	//			if( k == 100 && j == dy && i == ay ) cout <<  ( hm + i - dm - 1 ) / ( i - dm ) << ' ' << 
	//				( k + am - j - 1 ) / ( am - j )  << endl;
				if( am - j <= 0 || ( hm + i - dm - 1 ) / ( i - dm ) < ( k + am - j - 1 ) / ( am - j ) ) 
					best = min( best, ans + ( i - ay ) * a + ( j - dy ) * d + ( k - hy ) * h ) ;
			}
	cout << best << endl;

}