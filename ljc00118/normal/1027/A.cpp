#include <bits/stdc++.h>
using namespace std;

const int N = 200 + 10;

char c[N];
int T, n;

int main() {
	cin >> T;
	while(T--) {
		scanf("%d", &n);
		scanf("%s", c + 1);
		bool ok = 1;
		for(int i = 1; n - i + 1 > i; i++) {
			if(abs(c[i] - c[n - i + 1]) > 2 || abs(c[i] - c[n - i + 1]) == 1) {
				ok = 0;
				break;
			}
		}
		if(ok) puts("YES"); else puts("NO");
	}
	return 0;
}