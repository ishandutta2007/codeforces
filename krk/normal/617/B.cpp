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

const int Maxn = 105;

int n;
int a[Maxn];

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	ll res = 1;
	bool was = false;
	for (int i = 0; i < n; i++) if (a[i] == 1) {
		was = true;
		int j = i + 1;
		while (j < n && a[j] != 1) j++;
		if (j < n) { res *= (j - i); i = j - 1; }
		else break;
	}
	if (was) printf("%I64d\n", res);
	else printf("0\n");
    return 0;
}