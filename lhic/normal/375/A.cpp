#include <fstream>
#include <string.h>

using namespace std;

char s1[1000010];

int main()
{
	scanf("%s",s1);
	int len=strlen(s1);
	for (int i=0;i<len;i++)
	{
		if (s1[i]=='1')
		{
			swap(s1[i],s1[0]);
		}
		if (s1[i]=='6')
		{
			swap(s1[i],s1[1]);
		}
		if (s1[i]=='8')
		{
			swap(s1[i],s1[2]);
		}
		if (s1[i]=='9')
		{
			swap(s1[i],s1[3]);
		}
	}
	int sum=0;
	int sum2=1;
	for (int i=4;i<len;i++)
	{
		sum2=(sum2*3)%7;
		sum=(sum*3+s1[i]-'0')%7;
	}
	if ((sum+sum2*0)%7==0)
	{
		s1[0]='1';
		s1[1]='8';
		s1[2]='6';
		s1[3]='9';
	}
	if ((sum+sum2*1)%7==0)
	{
		s1[0]='1';
		s1[1]='9';
		s1[2]='6';
		s1[3]='8';
	}
	if ((sum+sum2*2)%7==0)
	{
		s1[0]='1';
		s1[1]='6';
		s1[2]='8';
		s1[3]='9';
	}
	if ((sum+sum2*3)%7==0)
	{
		s1[0]='6';
		s1[1]='1';
		s1[2]='9';
		s1[3]='8';
	}
	if ((sum+sum2*4)%7==0)
	{
		s1[0]='1';
		s1[1]='6';
		s1[2]='9';
		s1[3]='8';
	}
	if ((sum+sum2*5)%7==0)
	{
		s1[0]='1';
		s1[1]='9';
		s1[2]='8';
		s1[3]='6';
	}
	if ((sum+sum2*6)%7==0)
	{
		s1[0]='1';
		s1[1]='8';
		s1[2]='9';
		s1[3]='6';
	}
	
	for (int i=0;i<len;i++)
	{
		printf("%c",s1[i]);
	}
	
	
	
}