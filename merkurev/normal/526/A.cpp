#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int maxn = 100500;
char str[maxn];


int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	scanf("%s", str);

	int len = strlen(str);
	for (int i = 0; i < len; i++)
		for (int j = 1; i + 4 * j < len; j++)
		{
			bool good = true;
			for (int h = 0; h <= 4; h++)
				if (str[i + h * j] != '*')
					good = false;
			if (good)
			{
				printf("yes\n");
				return 0;
			}
		}
	printf("no\n");

	return 0;
}