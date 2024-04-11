#include <bits/stdc++.h>
using namespace std;
char s[50050];
int v[50], Ca, Cq;
vector<char> a;
int main()
{
	scanf("%s", s);
	int len = strlen(s);
	if (len < 26) printf("-1\n");
	else
	{
		for (int i = 0; i < 26; i ++)
		{
			if (s[i] == '?') Cq ++;
			else
			{
				if (v[s[i] - 'A'] == 0) Ca ++;
				v[s[i] - 'A'] ++;
			}
		}
		int l = 0, r = 25;
		while (Ca + Cq != 26)
		{
			if (s[l] == '?') Cq --;
			else
			{
				v[s[l] - 'A'] --;
				if (v[s[l] - 'A'] == 0) Ca --;
			}
			l ++;
			r ++;
			if (r == len) break;
			if (s[r] == '?') Cq ++;
			else
			{
				if (v[s[r] - 'A'] == 0) Ca ++;
				v[s[r] - 'A'] ++;
			}
		}
		if (r == len)printf("-1\n");
		else
		{
			int cnt = 0;
			for (int i = 0; i < 26; i ++)
				if (!v[i])a.push_back(i + 'A');
			for (int i = l; i <= r; i ++)
				if (s[i] == '?')
				{
					s[i] = a[cnt];
					cnt++;
				}
			for (int i = 0; i < len; i ++)
				if (s[i] == '?')
					s[i] = 'A';
			printf("%s\n", s);
		}
	}
	return 0;
}