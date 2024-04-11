#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	
	while (q--) {
		long long k;
		cin >> k;
		--k;
		long long lst = 0;
		long long nxtpw = 1;
		int numlen = 0;
		for (long long i = 1; ; ++i) {
			if (i == nxtpw) {
				++numlen;
				nxtpw *= 10;
			}
			lst += numlen;
			if (k >= lst) {
				k -= lst;
			} else {
				long long nxtpw = 1;
				int numlen = 0;
				for (long long j = 1; j <= i; ++j) {
					if (j == nxtpw) {
						++numlen;
						nxtpw *= 10;
					}
					if (k >= numlen) {
						k -= numlen;
					} else {
						cout << to_string(j)[k] << endl;
						break;
					}
				}
				break;
			}
		}
	}
	
	return 0;
}