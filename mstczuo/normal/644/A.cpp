# include <iostream>
# include <cstdio>
using namespace std;

int n, a, b;

int main() {
	cin >> n >> a >> b;
	if(n > a * b) {
		puts("-1");
		return 0;
	}
	int odd = 1, even = 2;
	for(int i = 0; i < a; ++i) {
		for(int j = 0; j < b; ++j) {
			if(j) putchar(' ');
			if((i + j) & 1) {
				printf("%d", even <= n ? even : 0);
				even += 2;
			} else {
				printf("%d", odd <= n ? odd : 0);
				odd += 2;
			}
		}
		puts("");
	}
	return 0;
}