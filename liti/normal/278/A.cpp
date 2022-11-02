#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	int n;
	cin >> n; 
	int d[n] ;
	for(int i = 0 ; i< n; i ++ )
	{
		cin >> d[i];
	}
	int s,t ; 
	cin >> s >> t;
	if ( s > t ) 
		swap ( s, t);
	s --;
	t--;
	int l = abs( t - s );
	int d1 = 0 , d2 = 0 ;
	for(int i = s; i < s + l  ; i++) 
		d1 += d[i% n] ;
	for(int i = t; i < t + ( n - l ) ; i++ )
		d2 += d[i % n];
	cout << min( d1, d2 ) << endl;
}