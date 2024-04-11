#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
char a[11];
bool ok=true;
bool check(char a[])
{
	for(int i=0;i<7;i++)
		if(a[i]==a[i+1]) return false;
	return true;
}
int main()
{
	for(int i=1;i<=8;i++)
	{
		scanf("%s",a);
		ok&=check(a);
	}
	if(ok) puts("YES");
	else puts("NO");
	return 0;
}