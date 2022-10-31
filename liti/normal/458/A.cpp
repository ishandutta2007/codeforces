/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN= 100*100*10 + 1000;

int f[maxN], l[maxN];

void calc( int* a ) { 
	for(int i = maxN - 3 ; i>= 0 ;i-- ) { 
		int x = min( a[i], a[i+1] ) ; 
		a[i+2] += x;
		a[i]-=x;
		a[i+1] -= x;
	}
	for(int i = 0 ; i < maxN - 2 ;i++ ) { 
		int x = min( a[i], a[i+1] ) ; 
		a[i+2] += x;
		a[i]-=x;
		a[i+1] -= x;
	}

}

int main() { 
	string a,b;
	cin >> a >> b;
	for(int i = 0 ; i < a.size() ; i++ ) 
		f[a.size()-i] = a[i] - '0';
	for(int i = 0 ; i < b.size() ; i++ ) 
		l[b.size()-i] = b[i] - '0';

	calc(f) ;
	calc(l);
	for(int i = maxN - 1 ; i >= 0 ; i-- )  
		if( f[i] > l[i] ) {
			cout << ">" << endl;
			return 0;
		} else if ( l[i] > f[i] )  {
			cout << "<" << endl;
			return 0;
		}
	cout << "=" << endl;
}