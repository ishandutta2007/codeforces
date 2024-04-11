#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[4][4];
bool mog;
int p=0;
int main()
{
	mog=false;
	for(int i=0;i<4;i++) scanf("%s",a[i]);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<2;j++)
		{
			p=0;
			for(int k=0;k<3;k++)
			{
				if(a[i][j+k]=='o') p=p+10;
				if(a[i][j+k]=='.') p++; 
			}
			if(p==1)
			{
				printf("YES");
				return 0;
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<2;j++)
		{
			p=0;
			for(int k=0;k<3;k++)
			{
				if(a[j+k][i]=='o') p=p+10;
				if(a[j+k][i]=='.') p++; 
			}
			if(p==1)
			{
				printf("YES");
				return 0;
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			p=0;
			for(int k=0;k<3;k++)
			{
				if(a[i+k][j+k]=='o') p=p+10;
				if(a[i+k][j+k]=='.') p++; 
			}
			if(p==1)
			{
				printf("YES");
				return 0;
			}
		}
	}
	for(int i=2;i<4;i++)
	{
		for(int j=0;j<2;j++)
		{
			p=0;
			for(int k=0;k<3;k++)
			{
				if(a[i-k][j+k]=='o') p=p+10;
				if(a[i-k][j+k]=='.') p++; 
			}
			if(p==1)
			{
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}