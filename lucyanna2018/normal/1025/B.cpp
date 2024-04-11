#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

int n, a[155555], b[155555];
bool chk(int x) {
	for (int i = 1; i <= n; i++)
		if (a[i] % x != 0 && b[i] % x != 0)
			return false;
	printf("%d\n", x);
	return true;
}
bool solve(int x) {
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) {
			while (x%i == 0)x /= i;
			if (chk(i))return true;
		}
	}
	if (x > 1 && chk(x))return true;
	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]);
	if (!solve(a[1]) && !solve(b[1])) {
		puts("-1");
	}
	return 0;
}