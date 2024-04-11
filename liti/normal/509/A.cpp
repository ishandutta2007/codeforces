/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

int main() { 
	int n;
	cin >> n;

	n--;
	ll ret= 1;
	for( int i = n + 1 ; i <= 2*n ; i++ ) 
		ret *= i;
	for( int i = 1 ; i <= n ; i++ ) 
		ret /= i;
	cout << ret << endl;
}