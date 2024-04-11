#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 10000005;

int n, k;
ll has[Maxn];
ll ab;
int res;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		has[a]++;
	}
	ab = n;
	int l = 1, r = Maxn - 1;
	while (l <= r) 
		if (ab >= k) { res = l; ab -= has[l]; l++; }
		else {
			ab -= has[r];
			has[r / 2] += has[r];
			if (r / 2 >= l) ab += has[r];
			has[(r + 1) / 2] += has[r];
			if ((r + 1) / 2 >= l) ab += has[r];
			r--;
		}
	if (!res) printf("-1\n");
	else printf("%d\n", res);
	return 0;
}