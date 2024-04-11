
#include <iostream>
#include <set>

using namespace std;

int n;
long long a, x;
multiset<long long> s[2];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		s[i % 2].insert(x);
		cin >> a;
		a ^= x;
		x = a;
	}
	s[n % 2].insert(x);
	x = 0;
	for(int i = 0; i < 2; i++) {
		while(s[i].size()) {
			a = s[i].size();
			s[i].erase(*s[i].begin());
			long long b = a - s[i].size();
			x += b * (b - 1) / 2;
		}
	}
	cout << x << endl;
}