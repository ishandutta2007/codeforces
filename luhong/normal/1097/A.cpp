#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <bitset>

int main()
{
	char c[5]; scanf("%s", c);
	for(int i = 1; i <= 5; i++)
	{
		char s[5]; scanf("%s", s);
		if(s[0] == c[0] || s[1] == c[1]) return 0 * puts("YES");
	}
	puts("NO");
}