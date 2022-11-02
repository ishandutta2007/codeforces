//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() { 
	int n; 
	cin >> n; 
	if( n == 3 ) { 
		cout << 1 << endl;
		return 0 ; 
	}
	cout << (n-2) *1ll* ( n - 2 ) << endl;
}