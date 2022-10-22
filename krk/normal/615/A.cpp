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

const int Maxm = 105;

bool on[Maxm];
int n, m;

int main() 
{
	scanf("%d %d", &n, &m);
	while (n--) {
		int x; scanf("%d", &x);
		while (x--) {
			int a; scanf("%d", &a);
			on[a] = true;
		}
	}
	for (int i = 1; i <= m; i++)
		if (!on[i]) { printf("NO\n"); return 0; }
	printf("YES\n");
    return 0;
}