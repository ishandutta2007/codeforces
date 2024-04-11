#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxd = 10;
const int R[Maxd] = {4, 1, 1, 1, 2, 2, 2, 3, 3, 3};
const int C[Maxd] = {2, 1, 2, 3, 1, 2, 3, 1, 2, 3};

int n;
int ind[Maxd];

bool Ok(int r, int c)
{
	return 1 <= r && r <= 3 && 1 <= c && c <= 3 || r == 4 && c == 2;
}

bool Check(int r, int c)
{
	for (int i = 0; i < n; i++)
		if (!Ok(r + R[ind[i]], c + C[ind[i]])) return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char ch; scanf(" %c", &ch);
		ind[i] = ch - '0';
	}
	int tot = 0;
	for (int i = -5; i <= 5; i++)
		for (int j = -5; j <= 5; j++)
			if (Check(i, j)) tot++;
	printf("%s\n", tot <= 1? "YES": "NO");
	return 0;
}