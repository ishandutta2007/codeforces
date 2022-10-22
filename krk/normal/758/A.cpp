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

int n;
int mx, sum;

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		mx = max(mx, a); sum += a;
	}
	printf("%d\n", n * mx - sum);
    return 0;
}