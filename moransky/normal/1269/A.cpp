#include <cstdio>
#include <iostream>
using namespace std;
int n;
int inline check(int x) {
	for (int i = 2; i * i <= x; i++)
		if(x % i == 0) return true;
	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = n + 1; ; i++) {
		if(!check(i)) continue;
		if(check(i - n)) {
			printf("%d %d\n", i, i - n);
			return 0;
		}
	}
	return 0;
}