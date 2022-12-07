#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
int p[3];
PII A[3],B[3];
bool work()
{
	if(B[0].first==B[1].first&&B[1].first==B[2].first&&B[0].second+B[1].second+B[2].second==B[0].first)
	{
		printf("%d\n",B[0].first);
		for(int i=0;i<B[0].second;i++)
		{
			for(int j=0;j<B[0].first;j++)
				putchar(p[0]+'A');
			puts("");
		}
		for(int i=0;i<B[1].second;i++)
		{
			for(int j=0;j<B[1].first;j++)
				putchar(p[1]+'A');
			puts("");
		}
		for(int i=0;i<B[2].second;i++)
		{
			for(int j=0;j<B[2].first;j++)
				putchar(p[2]+'A');
			puts("");
		}
		return true;
	}
	if(B[0].first==B[1].first+B[2].first&&B[0].first==B[0].second+B[1].second&&B[1].second==B[2].second)
	{
		printf("%d\n",B[0].first);
		for(int i=0;i<B[0].second;i++)
		{
			for(int j=0;j<B[0].first;j++)
				putchar(p[0]+'A');
			puts("");
		}
		for(int i=0;i<B[1].second;i++)
		{
			for(int j=0;j<B[0].first;j++)
				if(j<B[1].first) putchar(p[1]+'A');
				else putchar(p[2]+'A');
			puts("");
		}
		return true;
	}
	return false;
}
int main()
{
	scanf("%d%d",&A[0].x,&A[0].y);
	scanf("%d%d",&A[1].x,&A[1].y);
	scanf("%d%d",&A[2].x,&A[2].y);
	p[0]=0,p[1]=1,p[2]=2;
	do
	{
		for(int i=0;i<3;i++) B[i]=A[p[i]];
		for(int S=0;S<8;S++)
		{
			for(int i=0;i<3;i++)
				if(S&(1<<i)) swap(B[i].first,B[i].second);
			if(work()) return 0;
			for(int i=0;i<3;i++)
				if(S&(1<<i)) swap(B[i].first,B[i].second);
		}
	}while(next_permutation(p,p+3));
	puts("-1");
	return 0;
}