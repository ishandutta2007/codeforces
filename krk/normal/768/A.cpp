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

const int Inf = 1000000007;

int n;
int mn = Inf, cmn = 0;
int mx = -Inf, cmx = 0;

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (a < mn) { mn = a; cmn = 0; }
		if (a == mn) cmn++;
		if (a > mx) { mx = a; cmx = 0; }
		if (a == mx) cmx++;
	}
	if (mn == mx) printf("0\n");
	else printf("%d\n", n - cmn - cmx);
    return 0;
}