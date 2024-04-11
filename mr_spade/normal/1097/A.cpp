#include<cstdio>
const int N=105;
char s[100],t[100];
signed main()
{
	scanf("%s",s);
	for(int i=1;i<=5;i++)
	{
		scanf("%s",t);
		if(t[0]==s[0]||t[1]==s[1])
			return puts("YES"),0;
	}
	puts("NO");
	return 0;
}