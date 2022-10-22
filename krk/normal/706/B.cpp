#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int has[Maxn];
int q;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int x; scanf("%d", &x);
		has[x]++;
	}
	for (int i = 1; i < Maxn; i++)
		has[i] += has[i - 1];
	scanf("%d", &q);
	while (q--) {
		int my; scanf("%d", &my);
		printf("%d\n", has[min(my, Maxn - 1)]);
	}
	return 0;
}