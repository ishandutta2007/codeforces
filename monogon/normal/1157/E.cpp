#include <iostream>
#include <set>

using namespace std;

int a[200000];
int n;
int x;

multiset<int> b;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> x;
		b.insert(x);
	}
	for(int i = 0; i < n; i++) {
		auto it = b.upper_bound(n - a[i]);
		if(it != b.begin() && *prev(it) >= n - a[i]) {
			it--;
		}
		if(it == b.end()) {
			it = b.begin();
		}
		cout << ((*it + a[i]) % n) << " ";
		b.erase(it);
	}
}