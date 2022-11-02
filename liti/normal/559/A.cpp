//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

int a[6];

int gg( int a ) { 
	return a * a; 
}

int main() { 
	for( int i = 0 ; i < 6 ; i++ )
		cin >> a[i];
	int bad = gg(a[0]) + gg(a[2]) + gg(a[4]);
	cout << gg( a[2] + a[3] + a[4] ) - bad << endl;
}