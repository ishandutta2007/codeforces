/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;

int n, maxa = 0;

int a[10050];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >>a[i], maxa = max(maxa, a[i]);
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += maxa - a[i];
	printf("%d\n", ans);
	return 0;
}