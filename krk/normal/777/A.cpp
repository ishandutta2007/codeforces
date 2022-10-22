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
int a[3];

int main() 
{
	scanf("%d", &n);
	n %= 6;
	a[0] = 0; a[1] = 1; a[2] = 2;
	for (int i = 0; i < n; i++)
		if (i % 2 == 0) swap(a[0], a[1]);
		else swap(a[1], a[2]);
	int x; scanf("%d", &x);
	printf("%d\n", a[x]);
    return 0;
}