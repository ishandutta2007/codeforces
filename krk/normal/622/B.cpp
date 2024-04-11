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

int h, m;
int x;

int main() 
{
	char str[10]; scanf("%s", str);
	h = (str[0] - '0') * 10 + (str[1] - '0');
	m = (str[3] - '0') * 10 + (str[4] - '0');
	scanf("%d", &x);
	while (x--) {
		m++;
		if (m >= 60) { h = (h + 1) % 24; m = 0; }
	}
	printf("%d%d:%d%d\n", h / 10, h % 10, m / 10, m % 10);
    return 0;
}