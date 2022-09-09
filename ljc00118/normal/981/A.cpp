#include<bits/stdc++.h>
#define gc() getchar()

using namespace std;

const int N = 50 + 10;

char c[N];
int n;

int main() {
	scanf("%s", c);
	n = strlen(c);
	for(int i = n; i >= 1; i--) {
		for(int l = 0; l <= n - i; l++) {
			int r = l + i - 1;
			int L = l, R = r;
			bool ok = 1;
			while(L < R) {
				if(c[L] != c[R]) {
					ok = 0;
					break;
				}
				L++, R--;
			}
			if(!ok) {
				cout << i;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}