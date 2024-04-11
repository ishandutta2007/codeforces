#include <iostream>
using namespace std;


char s[100500];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int curpos = 0;
	int st = 0;

	while (true)
	{
		char ch = 0;
		scanf("%c", &ch);
		if (ch == 0 || ch == '\n')
			break;
		if (st == 0)
		{
			if (ch == ' ')
				continue;
			if (ch == '"')
			{
				st = 2;
				continue;
			}
			st = 1;
			s[curpos++] = ch;
			continue;
		}
		if (st == 1)
		{
			if (ch == '"')
				throw 42;
			if (ch == ' ')
			{
				st = 0;
				s[curpos] = 0;
				printf("<%s>\n", s);
				curpos = 0;
				continue;
			}
			s[curpos++] = ch;
			continue;
		}
		if (st == 2)
		{
			if (ch == '"')
			{
				st = 0;
				s[curpos] = 0;
				printf("<%s>\n", s);
				curpos = 0;
				continue;
			}
			s[curpos++] = ch;
			continue;
		}
		throw 42;
	}
	if (st == 1)
	{
		st = 0;
		s[curpos] = 0;
		printf("<%s>\n", s);
		curpos = 0;
	}


	return 0;
}