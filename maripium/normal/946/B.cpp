#include<bits/stdc++.h>
using namespace std;

long long n,m;
int main() {
	cin >> n >> m;
	while(1) {
		if(n == 0 || m == 0) break;
		if(n >= 2 * m) n %= (2 * m);
		else {
			if(m >= 2 * n) m %= (2 * n);
			else break;
		}
	}
	cout << n << ' '<< m;
}