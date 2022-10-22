#include <cstdio>
using namespace std;

int main()
{
	int cur = 0;
	int res = 0;
	char ch;
	while (scanf(" %c", &ch) == 1)
		if (ch == '(') cur++;
		else if (cur) { res += 2; cur--; }
	printf("%d\n", res);
	return 0;
}