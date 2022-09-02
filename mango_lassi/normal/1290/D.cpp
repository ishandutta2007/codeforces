#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool ask(int i) {
	cout << "? " << i+1 << endl;
	char ans;
	cin >> ans;
	return (ans == 'N');
}
void reset() {
	cout << "R" << endl;
}
void answer(int res) {
	cout << "! " << res << endl;
}

int main() {
	int n, k;
	cin >> n >> k;

	// n cafes
	// memory size k
	// At most 3/2 n^2/k operations
	// Resetting memory is free

	// If k = n, we are only allowed to do 3/2 n queries, but can use just n:
	// Loop from 1 to n, and record which coffees were not their first appearance.
	// Answer is just the number of coffees that appeared for the first time.

	// Can we extend this strategy where we calculate for every cup of coffee whether it appears for the first time?

	// Say k = n/2. Do this:
	// 11110000
	// 11001100
	// 11000011
	// 00111100
	// 00110011
	// 00001111
	
	// This strategy takes (n/k' (n/k' - 1) / 2) 2k' ~ n/k' = 2n/k operations
	// Nearly good enough! But we can combine pairs to do this faster!
	// I haven't counted but we can just brute-force to check :)

	int p = (k+1) / 2;
	int m = n/p;
	vector<int> uniq(n, 1);
	vector<int> nxt(m);
	for (int i = 0; i < m; ++i) nxt[i] = i+1;

	int s = 0;
	while(s < m) {
		for (int i = s; i < m;) {
			for (int j = i*p; j < (i+1)*p; ++j) {
				uniq[j] &= ask(j);
			}
			++nxt[i];
			i = nxt[i] - 1;
		}
		reset();
		while(s < m && nxt[s] >= m) ++s;
	}
	int ans = 0;
	for (auto v : uniq) ans += v;
	answer(ans);
}