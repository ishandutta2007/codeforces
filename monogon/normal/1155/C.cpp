
#include <iostream>

using namespace std;

int n, m;
long long x0, g;
long long x[300000], p[300000];

long long gcd(long long a, long long b) {
	long long r;
	do {
		r = a % b;
		a = b;
		b = r;
	}while(r != 0);
	return a;
}

int main() {
	cin >> n >> m >> x0;
	for(int i = 1; i < n; i++) {
		cin >> x[i];
		x[i] -= x0;
		if(i == 1) g = x[i];
		else g = gcd(g, x[i]);
	}
	for(int i = 0; i < m; i++) {
		cin >> p[i];
	}
	for(int i = 0; i < m; i++) {
		if(g % p[i] == 0) {
			cout << "YES" << endl << x0 << " " << (i + 1) << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}