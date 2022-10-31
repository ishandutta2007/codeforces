#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000 * 100 + 100; 
int a[maxN]; 

int main() {
	ios::sync_with_stdio(false);
	int n;
	long long k;
	cin >> n >> k; 
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	k--;
	
	int j;
	for(int i = 0; i < n; i = j) {
		for(j = i; j < n && a[i] == a[j]; j++);
		if( k < (j-i) * 1ll * n ) { 
			cout << a[i] << ' ' << a[k/(j-i)] << endl;
			return 0; 
		}
		k -= (j-i) * 1ll * n;
	}
		

	return 0;
}