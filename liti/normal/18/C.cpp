/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000*100 + 10; 

int a[maxN];

int main() { 
	int n;
	cin >> n;

	long long sum = 0 ; 
	for(int i  = 0 ; i < n; i++ ) {
		cin >> a[i];
		sum += a[i];
	}

	int counter =0 ; 
	long long s = 0 ; 
	for(int i = 0 ; i < n - 1 ; i++ ) {
		s += a[i];
		if( s == sum - s ) 
			counter++;
	}
	cout << counter << endl;
}