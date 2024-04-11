#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100500;
char mir[] = "AHIMOTUVWXY";
char s[maxn];


int n;
void no()
{
	printf("NO\n");
	exit(0);
}
bool good(char x)
{
	for (int i = 0; i < n; i++)
		if (mir[i] == x)
			return true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	n = strlen(mir);
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		char x = s[i];
		char y = s[len - i - 1];
		if (x != y)
			no();
		if (!good(x) )
			no();
	}
	printf("YES\n");

	return 0;
}