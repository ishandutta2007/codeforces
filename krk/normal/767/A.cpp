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

const int Maxn = 100005;

int n;
bool has[Maxn];

int main() 
{
	scanf("%d", &n);
	int lookfor = n;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		has[a] = true;
		bool pr = false;
		while (lookfor > 0 && has[lookfor]) {
			if (pr) printf(" ");
			pr = true;
			printf("%d", lookfor--);
		}
		printf("\n");
	}
    return 0;
}