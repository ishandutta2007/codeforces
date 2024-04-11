//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN  = 200;
int a[maxN]; 
int main() { 
	int n = 101; 
	int count =0; 
	for( int i = 2 ; i < n ;i++ ) 
		if( !a[i] || i == 4 || i == 9 || i == 49 || i == 25  ) { 
			if( i * 2 < n ) { 
				cout << i << endl;
				string res; cin >> res; 
				if( res == "yes" ) count++; 
			}
			for( int j = i + i ; j < n ; j+= i ) 
				a[j] = 1; 
		}
	if( count > 1 ) cout << "composite" << endl;
	else cout << "prime" << endl;

}