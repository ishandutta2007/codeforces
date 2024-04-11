#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxm = 12;
const int days[Maxm] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n;
int a[100];

int main()
{
	scanf("%d", &n);
	int was = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 29) { a[i]--; was++; }
	}
	if (was > 1) { printf("NO\n"); return 0; }
	for (int i = 0; i < Maxm; i++) {
		bool ok = true;
		for (int j = 0; j < n && ok; j++)
			ok = days[(i + j) % Maxm] == a[j];
		if (ok) { printf("YES\n"); return 0; }
	}
	printf("NO\n");
	return 0;
}