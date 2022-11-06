#include <cstdio>
#include <iostream>

char s[201000];
int main()
{
	int n; scanf("%d", &n);
	int r = 0, b = 0;
	scanf("%s", s);
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '(')
		{
			if(r < b) r++, printf("1");
			else b++, printf("0");
		}
		if(s[i] == ')')
		{
			if(r > b) r--, printf("1");
			else b--, printf("0");
		}
	}
}