#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 1200000;

int n;
vector<int> va;
vector<int> vb;
int a[MAXN];
int b[MAXN];
ll pr[MAXN];
int nx[MAXN];
int lst[MAXN];
int fl;

int main() {
	scanf("%d", &n);
	ll sum = 0;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i), sum += a[i];
	for (int i = 0; i < n; ++i)
		scanf("%d", b + i), sum -= b[i];
	if (sum > 0) {
		fl = 1;
		for (int i = 0; i < n; ++i)
			swap(a[i], b[i]);
	}
	for (int i = 0; i < n; ++i)
		lst[i] = -1;
	pr[0] = 0;
	for (int i = 0; i < n; ++i)
		pr[i + 1] = pr[i] + b[i];
	sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		int x = upper_bound(pr, pr + n + 1, sum) - pr - 1;
		nx[i] = x;
		int go = sum - pr[x];
		if (go == 0) {
			for (int j = 0; j <= i; ++j)
				va.push_back(j + 1);
			for (int j = 0; j < x; ++j)
				vb.push_back(j + 1);
			break;
		}
		if (lst[go] != -1) {
			int l = lst[go] + 1; 
			int r = i + 1;
			for (int j = l; j < r; ++j)
				va.push_back(j + 1);
			l = nx[lst[go]];
			r = nx[i];
			for (int j = l; j < r; ++j)
				vb.push_back(j + 1);
			break;
		}
		lst[go] = i;
	}
	if (fl)
		swap(va, vb);
	printf("%d\n", (int)va.size());
	for (int i: va)
		printf("%d ", i);
	printf("\n");
	printf("%d\n", (int)vb.size());
	for (int i: vb)
		printf("%d ", i);
	printf("\n");
	return 0;
}