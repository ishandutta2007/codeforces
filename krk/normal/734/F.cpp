#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxb = 31;

int n;
int a[Maxn], b[Maxn];
ll sum;
int res[Maxn];
int bits[Maxb];

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); sum += a[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]); sum += b[i];
	}
	if (sum % (2 * n)) { printf("-1\n"); return 0; }
	sum /= (2 * n);
	for (int i = 0; i < n; i++) {
		ll got = a[i] + b[i];
		if (got < sum) { printf("-1\n"); return 0; }
		got -= sum;
		if (got % n) { printf("-1\n"); return 0; }
		res[i] = got / n;
		for (int j = 0; j < Maxb; j++)
			bits[j] += bool(res[i] & 1 << j);
	}
	for (int i = 0; i < n; i++) {
		ll A = 0, B = 0;
		for (int j = 0; j < Maxb; j++)
			if (res[i] & 1 << j) {
				A += ll(1 << j) * bits[j];
				B += ll(1 << j) * n;
			} else {
				B += ll(1 << j) * bits[j];
			}
		if (a[i] != A || b[i] != B) { printf("-1\n"); return 0; }
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}