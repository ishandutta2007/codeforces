# include <iostream>
# include <cstdio>
# include <set>
using namespace std;

multiset<int> e;

int a[520];

int gcd(int a,int b) {
	for(int t; b; t = a, a = b, b = t % a);
	return a;
}

int main() {
	int n, x;
	cin >> n;
	for (int i = 0; i < n * n; ++i) {
		cin >> x;
		e.insert(x);
	}
	for(int k = 0; k < n; ++k) {
		a[k] = *e.rbegin();
		e.erase(e.find(a[k]));
		for(int i = 0; i < k; ++i) {
			e.erase(e.find(gcd(a[k], a[i])));
			e.erase(e.find(gcd(a[k], a[i])));
		}
	}
	for(int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << endl;
}