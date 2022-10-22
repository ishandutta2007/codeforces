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

const int Maxn = 1005;

int n;
int a[Maxn];
vector <int> res;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (!res.empty() && gcd(res.back(), a[i]) > 1) res.push_back(1);
		res.push_back(a[i]);
	}
	printf("%d\n", res.size() - n);
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}