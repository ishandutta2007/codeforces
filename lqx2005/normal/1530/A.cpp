#include <bits/stdc++.h>

using namespace std;
int main() {
	int T;
	for(cin >> T; T--; ) {
		int n;
		cin >> n;
		int dig = 0;
		for(; n; n /= 10) dig = max(dig, n % 10);
		cout << dig << endl;
	}	
	return 0;
}