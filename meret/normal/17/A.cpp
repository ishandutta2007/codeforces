#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef long long LL;

int n, k;

bool prime[1001];
int p[1000], cp;

void era() {
	for (int i = 2; i <= n; ++i)
		prime[i] = 1;
	for (int i = 2; i <= n; ++i) {
		if (prime[i]) {
			p[cp++] = i;
			for (int j = i * i; j <= n; j += i)
				prime[j] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	era();
	for (int i = 2; i <= n; ++i) {
		if (prime[i]) {
			for (int j = 0; j + 1 < cp; ++j) {
				if (p[j] + p[j + 1] + 1 == i) {
					--k;
					break;
				}
			}
		}
	}
	if (k > 0)
		printf("NO\n");
	else
		printf("YES\n");
}