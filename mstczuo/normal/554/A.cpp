#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[30];
	scanf("%s", s);
	int n = strlen(s);
	set<string> S;
	for (int i = 0; i <= n; i++)
	{
		for (char ch = 'a'; ch <= 'z'; ch++)
		{
			string str;
			for (int j = 0; j < i; j++)
				str += s[j];
			str += ch;
			for (int j = i; j < n; j++)
				str += s[j];
			S.insert(str);
		}
	}
	printf("%d\n", int(S.size()));
}