#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 500005;

int n, a, b, T;
char str[Maxn];
int res;
vector <int> C;

int Cost(int x) { return str[x] == 'h'? 1: 1 + b; }

int main()
{
	scanf("%d %d %d %d", &n, &a, &b, &T);
	scanf("%s", str);
	// 1
	int cost = 0;
	int i = 0;
	while (i < n) {
		cost += Cost(i);
		if (cost <= T) res = max(res, i + 1);
		else break;
		cost += a; i++;
	}
	// 2
	cost = 0;
	i = 0;
	while (i < n) {
		int ind = (n - i) % n;
		cost += Cost(ind);
		if (cost <= T) res = max(res, i + 1);
		else break;
		cost += a; i++;
	}
	if (res == n) { printf("%d\n", res); return 0; }
	// 3
	cost = 0; C.push_back(cost);
	for (int i = 1; i < n; i++) {
		cost += a + Cost(i);
		C.push_back(cost);
	}
	cost = 0;
	for (int i = 0; i < n; i++) {
		int ind = (n - i) % n;
		cost += Cost(ind);
		if (cost + i * a <= T) {
			int my = upper_bound(C.begin(), C.end(), T - cost - i * a) - C.begin() - 1;
			res = max(res, i + 1 + my);
		} else break;
		cost += a;
	}
	// 4
	C.clear();
	cost = 0; C.push_back(cost);
	for (int i = 1; i < n; i++) {
		int ind = (n - i) % n;
		cost += a + Cost(ind);
		C.push_back(cost);
	}
	cost = 0;
	for (int i = 0; i < n; i++) {
		cost += Cost(i);
		if (cost + i * a <= T) {
			int my = upper_bound(C.begin(), C.end(), T - cost - i * a) - C.begin() - 1;
			res = max(res, i + 1 + my);
		} else break;
		cost += a;
	}

	printf("%d\n", res);
	return 0;
}