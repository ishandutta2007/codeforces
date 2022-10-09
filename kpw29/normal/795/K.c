#include <stdio.h>
#define maxn 100100
char s[maxn];
int n;
inline int vovel(char zn) {
	return (zn == 'a' || zn == 'u' || zn == 'e' || zn == 'i' || zn == 'o' || zn == 'y');
}

int main()
{
	scanf("%d", &n);
	scanf("%s", s+1);
	for (int i=1; i<=n; ++i)
	{
		if (!vovel(s[i])) printf("%c", s[i]);
		else
		{
			if (s[i-1] != s[i]) printf("%c", s[i]);
			else if (s[i] == s[i-1] && (s[i] == 'e' || s[i] == 'o') && s[i - 2] != s[i] && s[i + 1] != s[i]) printf("%c", s[i]);
		}
	}
	return 0;
}