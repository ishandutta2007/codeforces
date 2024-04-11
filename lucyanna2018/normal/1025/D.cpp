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

int n, a[707];
int L[707][707], R[707][707];
bool g[707][707];
int gcd(int x, int y) {
	return y ? gcd(y, x%y) : x;
}
int getL(int S, int E);
int getR(int S, int E);
int getL(int S, int E) {
	if (S > E)return 1;
	int&res = L[S][E];
	if (res)return res;
	for (int i = S; i <= E; i++) {
		if (getL(S, i - 1) == 1 && getR(i + 1, E) == 1 && g[i][E + 1])
			return res = 1;
	}
	return res = -1;
}
int getR(int S, int E) {
	if (S > E)return 1;
	int&res = R[S][E];
	if (res)return res;
	for (int i = S; i <= E; i++) {
		if (getL(S, i - 1) == 1 && getR(i + 1, E) == 1 && g[S - 1][i])
			return res = 1;
	}
	return res = -1;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)
		g[i][j] = (gcd(a[i], a[j]) > 1);
	for(int i=1; i<=n; i++)
		if (getL(1, i - 1) == 1 && getR(i + 1, n) == 1) {
			puts("Yes");
			return 0;
		}
	puts("No");
	return 0;
}