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

int a, b;

int main() 
{
	scanf("%d %d", &a, &b);
	if (a == 0 && b == 0 || abs(a - b) > 1) printf("NO\n");
	else printf("YES\n");
    return 0;
}