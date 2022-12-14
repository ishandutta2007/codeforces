#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, t, k, d;
	scanf("%d%d%d%d", &n, &t, &k, &d);
	printf("%s\n", (((n - 1) / k + 1) * t - 1 - d >= t) ? "YES" : "NO");
	return 0;
}