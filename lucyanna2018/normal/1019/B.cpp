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
int n;
int sgn(int x) {
	if (x > 0)return 1;
	if (x < 0)return -1;
	return 0;
}
int query(int i) {
	int x, y;
	printf("? %d\n", i); fflush(stdout);
	scanf("%d", &x);
	printf("? %d\n", i + n); fflush(stdout);
	scanf("%d", &y);
	return sgn(x - y);
}
int answer(int x) {
	printf("! %d\n", x); fflush(stdout);
	return 0;
}
int main() {
	scanf("%d", &n); n /= 2;
	if (n % 2 == 1)return answer(-1);
	int dif = query(1);
	if (dif == 0)return answer(1);
	int lo = 1, hi = n + 1, dlo = dif, dhi = -dif;
	while (1) {
		int mi = (lo + hi) / 2;
		int d = query(mi);
		if (d == 0)return answer(mi);
		if (dlo * d > 0) {
			lo = mi + 1;
			dlo = d;
		}
		else {
			hi = mi - 1;
			dhi = d;
		}
	}
	return 0;
}