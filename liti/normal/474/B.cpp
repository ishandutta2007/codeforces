/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN=1000*100 + 10;
int a[maxN];

int main() { 
	int n;
	cin >> n;
	for( int i = 1 ; i <= n; i++ ) 
		cin >> a[i];
	for( int i = 1 ; i <= n ; i++ ) 
		a[i] += a[i-1];
	int m;
	cin >> m;
	for( int i = 0 ; i < m ; i++ ){ 
		int num;
		cin >> num;
		cout << upper_bound(a, a + n + 1 , num - 1) - a   << endl;
	}
}