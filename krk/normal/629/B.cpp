#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 5005;
const int Maxm = 405;

int n;
int M[Maxm], F[Maxm];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char ch; int a, b; scanf(" %c %d %d", &ch, &a, &b);
		if (ch == 'M') 
			for (int j = a; j <= b; j++)
				M[j]++;
		else for (int j = a; j <= b; j++)
				F[j]++;
	}
	for (int j = 0; j < Maxm; j++)
		res = max(res, min(M[j], F[j]));
	printf("%d\n", 2 * res);
	return 0;
}