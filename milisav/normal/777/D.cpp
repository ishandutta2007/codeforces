#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char s[502000];
vector<char> a[502000];
int b[502000];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		b[i]=strlen(s)-1;
		for(int j=1;j<b[i]+1;j++) a[i].push_back(s[j]);
	}
	for(int i=n-2;i>=0;i--)
	{
		for(int j=0;j<b[i];j++)
		{
			if(j==b[i+1])
			{
				b[i]=b[i+1];
				break;
			}
			if(a[i][j]<a[i+1][j]) break;
			if(a[i][j]>a[i+1][j])
			{
				b[i]=j;
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("#");
		for(int j=0;j<b[i];j++) printf("%c",a[i][j]);
		printf("\n");
	}
	return 0;
}