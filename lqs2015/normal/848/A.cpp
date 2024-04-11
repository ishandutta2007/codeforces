#include<iostream>
#include<cstdio>
using namespace std;
char s[111111];
int n,cnt,pc;
int main()
{
	scanf("%d",&n);
	for (int i=0;i<26;i++)
	{
		s[cnt++]='a'+i;
		pc=0;
		while(n)
		{
			pc++;
			if (n<pc) break;
			s[cnt++]='a'+i;
			n-=pc;
		}
		if (!n) break;
	}
	s[cnt]='\0';
	printf("%s",s);
	return 0;
}