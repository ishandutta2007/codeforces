#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

ll add;
map <ll, int> M;
int n, a[Maxn];
ll cur[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); cur[i] = a[i];
		if (i > 0) cur[i] += cur[i - 1];
		M[cur[i]]++;
	}
	res = n;
	for (int i = 0; i < n; i++) {
		res = min(res, n - M[-add]);
		add -= a[i];
		M[cur[i]]--;
		M[-add]++;
	}
	printf("%d\n", res);
	return 0;
}