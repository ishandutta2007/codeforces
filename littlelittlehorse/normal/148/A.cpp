#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int f[100001], A, B, C, D, n;

int main(){
	//freopen("a.in", "r", stdin);
	scanf("%d%d%d%d%d", &A, &B, &C, &D, &n);
	memset(f, 0, sizeof(f));
	for (int i = A; i <= n; i += A) f[i] = 1;
	for (int i = B; i <= n; i += B) f[i] = 1;
	for (int i = C; i <= n; i += C) f[i] = 1;
	for (int i = D; i <= n; i += D) f[i] = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += f[i];
	printf("%d\n", ans);
}