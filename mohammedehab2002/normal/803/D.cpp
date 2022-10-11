#include <iostream>
#include <stdio.h>
using namespace std;
string s;
char arr[1000005];
int k;
bool check(int x)
{
	int i=0,a=0;
	while (i!=s.size())
	{
		int t=min(i+x-1,(int)s.size()-1);
		while (s[t]!=' ' && s[t]!='-' && t!=s.size()-1)
		{
			t--;
			if (t<0)
			break;
		}
		if (t==i-1)
		return 0;
		i=t+1;
		a++;
	}
	return (a<=k);
}
int main()
{
	scanf("%d",&k);
	getchar();
	gets(arr);
	s=string(arr);
	int st=1,en=s.size();
	while (st!=en)
	{
		int mid=(st+en)/2;
		if (check(mid))
		en=mid;
		else
		st=mid+1;
	}
	printf("%d",st);
}