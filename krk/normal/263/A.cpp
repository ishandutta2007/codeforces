#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 5;

int main()
{
	for (int i = 0; i < Maxn; i++)
		for (int j = 0; j < Maxn; j++) {
			char c; scanf(" %c", &c);
			if (c == '1') printf("%d\n", abs(i - 2) + abs(j - 2));
		}
	return 0;
}