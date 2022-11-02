//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000*100 + 100; 
int a[maxN]; 

int main() { 
	int n; 
	cin >> n;
	int sum = 0;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i]; 
		sum += a[i];
	}
	if( a[n-1] == 1 || ( n > 1 && a[n-2] == 0 && sum == n - 2) ) { 
		cout << "NO" << endl;
		return 0; 
	}
	cout << "YES" << endl;
	if( n == 1 ) { 
		cout << 0 << endl;
		return 0;
	}	
	if( n == 2 ) {
		cout << "1->0" << endl;
		return 0;
	}
	string res = "";
	bool ch = false;
	for( int i = 0 ; i < n - 2 ; i++ ) 
		if( !ch && a[i] == 0 ) {
			ch = true;
			res += "(0->(";
		} else if( a[i] == 0 ) 
			res += "0->";
		else
			res += "1->";
	res += char(a[n-2]+'0');
	if( ch ) res += "))";
	res += "->0";
	cout << res << endl;
}