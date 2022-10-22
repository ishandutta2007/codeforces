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

int main() 
{
	int a = 0, d = 0;
	scanf("%d", &n);
	char ch;
	while (n--) {
		scanf(" %c", &ch);
		if (ch == 'A') a++;
		else d++;
	}
	if (a > d) printf("Anton\n");
	else if (a < d) printf("Danik\n");
	else printf("Friendship\n");
    return 0;
}