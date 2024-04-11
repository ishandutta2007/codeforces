/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

int main(){ 
	string a,b;
	cin >> a >> b;
	int n = a.size() ; 

	bool ch = 0;
	string ret = a; 
	for( int i = n - 1 ; i >= 0; i-- ) {
		if( ret[i] != 'z' ) { 
			ret[i] = ret[i] + 1; 
			for( int k = i + 1 ; k < n ; k++ ) 
				ret[k] = 'a';
			break;
		}
	}
	if( ret == a || ret == b ) { 
		cout << "No such string" << endl;
		return 0;
	}
	cout << ret << endl;
}