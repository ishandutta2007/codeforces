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

int k, a, b;

int main() 
{
	scanf("%d %d %d", &k, &a, &b);
	int wa = a / k, wb = b / k;
	if (wa == 0 && b % k > 0 || wb == 0 && a % k > 0) printf("-1\n");
	else printf("%d\n", wa + wb);
    return 0;
}