#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n;
char B[Maxn];
vector <int> res;

int main()
{
	scanf("%d", &n);
	scanf("%s", B);
	for (int i = 0; i < n; i++) if (B[i] == 'B') {
		int j = i;
		while (j < n && B[j] == 'B') j++;
		res.push_back(j - i);
		i = j - 1;
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}