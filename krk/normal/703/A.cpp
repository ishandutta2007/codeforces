#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
int a, b;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int u, v; scanf("%d %d", &u, &v);
		a += u > v; b += u < v;
	}
	if (a > b) printf("Mishka\n");
	else if (a < b) printf("Chris\n");
	else printf("Friendship is magic!^^\n");
	return 0;
}