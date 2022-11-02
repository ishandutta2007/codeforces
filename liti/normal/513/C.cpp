/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
typedef long double ld;

const int maxN = 10000 + 1;
pair<int,int> a[5];

int main() { 
	int n;
	cin >> n;
	for( int i = 0 ; i < n ; i++ ) 
		cin >> a[i].first >> a[i].second;

	ld ret = 0;
	for( int i = 1 ; i < maxN ; i++ ) {
	//	if( i < 10 ) cout << ret << ' ' << i << endl;
		for( int k = 0 ; k < n ; k++ ) {
			if( a[k].second <= i ) continue;
			ld p = (a[k].second - max(a[k].first,i+1) + 1)/ld(a[k].second - a[k].first +1);

			ld p1 = 1 , p2 = 1;
			for( int j = 0 ; j < n ; j++ ) if( j != k ) {
				if( a[j].first > i ) { 
					p1 = 0, p2 = 0;
					break;
				}
				p1 *= (min(a[j].second,i)-a[j].first+1)/ld(a[j].second-a[j].first+1);
				p2 *= (min(a[j].second,i-1)-a[j].first+1)/ld(a[j].second-a[j].first+1);
			}
	//		if( i == 3 ) cout << p1 << ' ' << p2  << ' ' << p << endl;
			p *= (p1 - p2);
			ret += p*i;
		}
		for( int k = 0 ; k < (1<<n) ; k++ ) if( __builtin_popcount(k) > 1 )  {
			ld p = 1;
			for( int j= 0 ; j < n ; j++ ) 
				if( k & (1<<j) ) {
					if( a[j].second < i || a[j].first > i ) p = 0;
					else p *= 1/ld(a[j].second-a[j].first+1);
				} else { 
					if( a[j].first >= i ) p = 0;
					else p *= (min(a[j].second,i-1)-a[j].first+1)/ld(a[j].second-a[j].first+1) ;
				}
			ret += p*i;
		}
	}
	cout << fixed << setprecision(9) << ret << endl;
}