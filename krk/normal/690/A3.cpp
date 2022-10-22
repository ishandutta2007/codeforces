#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

int t;
int n, r;

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &r); r--;
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			int a; scanf("%d", &a); a--;
			sum = (sum + a) % n;
		}
		int res = (r - sum + n) % n;
		printf("%d\n", res + 1);
	}
	return 0;
}