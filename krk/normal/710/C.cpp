#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 55;

int n;
bool mark[Maxn][Maxn];

int main()
{
	scanf("%d", &n);
	int cur = 0;
	for (int i = 0; i <= n / 2; i++) {
		for (int j = n / 2 - cur; j <= n / 2 + cur; j++)
			mark[i][j] = true;
		cur++;
	}
	cur -= 2;
	for (int i = n / 2 + 1; i < n; i++) {
		for (int j = n / 2 - cur; j <= n / 2 + cur; j++)
			mark[i][j] = true;
		cur--;
	}
	int odd = 1, even = 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (mark[i][j]) { printf("%d", odd); odd += 2; }
			else { printf("%d", even); even += 2; }
			printf("%c", j + 1 < n? ' ': '\n');
		}
	return 0;
}