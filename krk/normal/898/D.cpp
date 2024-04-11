#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 200005;

int n, m, k;
int a[Maxn];
int res;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	deque <int> D;
	for (int i = 0; i < n; i++) {
		D.push_back(a[i]);
		while (D.back() - D.front() >= m) D.pop_front();
		if (D.size() >= k) { res++; D.pop_back(); }
	}
	printf("%d\n", res);
	return 0;
}