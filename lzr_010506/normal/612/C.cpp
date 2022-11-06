#include <bits/stdc++.h>
using namespace std;
char ch[1000010];
int op[5], ans, a[1000010], s;

int Find(char c)
{
	if(c == '<') return 1;
	if(c == '{') return 2;
	if(c == '[') return 3;
	if(c == '(') return 4;
	if(c == '>') return 5;
	if(c == '}') return 6;
	if(c == ']') return 7;
	return 8;
}

int main()
{
	scanf("%s", ch);
	int n = strlen(ch);
	for(int i = 0; i < n; i ++)
	{
		int id = Find(ch[i]);
		bool Flag = 0;
		if(id > 4) Flag = 1;
		if(Flag == 1)
		{
		    id -= 4;
			if(s == 0) {cout << "Impossible"; return 0;}
			if(a[s] != id) ans ++;
			s --;
		}
		else a[++ s] = id;
	}
	if(s) {cout << "Impossible"; return 0;}
	cout << ans;
	return 0;
}