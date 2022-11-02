/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1<<12;
int a[maxN];

int main() { 
	int n;
	cin >> n;

	int k = 1<<(n+1);
	for( int i = 2 ; i < k ; i++ ) 
		cin >> a[i];
	int sum = 0 ;
	for( int i = k - 1 ; i > 1 ; i -= 2 ) { 
//		cout << a[i] << ' ' << a[i-1] << endl;
		int x = max( a[i] , a[i-1] ) ; 
		sum += x - a[i] + x - a[i-1]; 
		a[i] = x; 
		a[i] = x; 
		a[(i-1)/2] += x; 
	}
	cout << sum << endl;
}