//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii; 

int main() {
	int a, b, c;
	cin >> a >> b >> c; 
	a %= b;

	for(int t = 1 ; t < 1000*1000 ; t++ ) { 
		if( a * 10 / b == c ) { 
			cout << t << endl;
			return 0; 
		}
		a = a * 10 % b;
	}
	cout << -1 << endl;
	return 0;
}