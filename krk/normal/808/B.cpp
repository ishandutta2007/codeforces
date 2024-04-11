#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 200005;

int n, k;
int a[Maxn];
ld sum;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	ld cur = 0;
	for (int i = 0; i < k - 1; i++)
		cur += a[i];
	for (int i = k - 1; i < n; i++) {
		cur += a[i];
		sum += cur;
		cur -= a[i - (k - 1)];
	}
	cout << fixed << setprecision(11) << sum / ld(n - k + 1) << endl;
	return 0;
}