# include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	if(k >= n * 2) {
		cout << 0 << endl;
	} else if(k <= n + 1) {
		cout << (k-1) / 2 << endl;
	} else {
		cout << (n-(k-n)+1) / 2 << endl;
	}
}