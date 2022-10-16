#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[3];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		for (int i = 0; i < 3; i++) scanf("%d", a + i);
		sort(a, a + 3);
		if(a[0] + a[1] + 1 >= a[2]) puts("Yes");
		else puts("No");
	}
	return 0;
	
}