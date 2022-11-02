/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

int main() { 
	int n;
	cin >> n;
	string a;
	cin >> a; 

	for( int i = 1 ; i <= 100 ; i++ )
		for( int j = 0 ; j + 4 * i < sz(a) ; j++ )
			if( a[j] == '*' && 
					a[j+i] == '*' &&
					a[j+2*i] == '*' && 
					a[j+3*i] == '*' &&
					a[j+4*i] == '*' ) {
				cout << "yes" << endl;
				return 0;
			}
	cout << "no\n" ;
}